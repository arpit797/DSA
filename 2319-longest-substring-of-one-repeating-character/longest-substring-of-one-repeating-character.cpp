class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        set<int> starts;
        multiset<int> lengths;

        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            starts.insert(i);
            lengths.insert(j - i);
            i = j;
        }
        starts.insert(n); // sentinel

        vector<int> ans;
        int q = queryCharacters.size();

        for (int k = 0; k < q; k++) {
            int idx = queryIndices[k];
            char c = queryCharacters[k];

            if (s[idx] != c) {
                auto it = starts.upper_bound(idx);
                --it;
                int st = *it;
                int end = *starts.upper_bound(st); // run = [st, end)

                int prevStart = -1;
                if (it != starts.begin()) prevStart = *prev(it);
                int nextStart = end;

                // remove old run
                lengths.erase(lengths.find(end - st));
                starts.erase(st);

                s[idx] = c;

                int mstart = idx, mend = idx + 1;

                // left side
                if (idx > st) {
                    starts.insert(st);
                    lengths.insert(idx - st);
                } else if (prevStart != -1 && s[prevStart] == c) {
                    lengths.erase(lengths.find(st - prevStart));
                    starts.erase(prevStart);
                    mstart = prevStart;
                }

                // right side
                if (idx + 1 < end) {
                    starts.insert(idx + 1);
                    lengths.insert(end - (idx + 1));
                } else if (nextStart < n && s[nextStart] == c) {
                    int nextEnd = *starts.upper_bound(nextStart);
                    lengths.erase(lengths.find(nextEnd - nextStart));
                    starts.erase(nextStart);
                    mend = nextEnd;
                }

                starts.insert(mstart);
                lengths.insert(mend - mstart);
            }

            ans.push_back(*lengths.rbegin());
        }
        return ans;
    }
};