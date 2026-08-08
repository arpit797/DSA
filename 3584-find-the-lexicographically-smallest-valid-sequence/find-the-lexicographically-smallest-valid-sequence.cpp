class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        if (n > m) return {};
        vector<int> rem(m + 1, 0);
        int j = n; 
        for (int i = m - 1; i >= 0; --i) {
            rem[i] = rem[i + 1];
            if (j > 0 && word1[i] == word2[j - 1]) {
                j--;
                rem[i] = n - j;
            }
        }

        vector<int> ans;
        ans.reserve(n);
        bool usedChange = false; 
        int wi = 0;           

        for (int i = 0; i < m && wi < n; ++i) {
            if (word1[i] == word2[wi]) {
                ans.push_back(i);
                wi++;
            } else if (!usedChange) {
                int remaining = n - (wi + 1);
                if (rem[i + 1] >= remaining) {
                    ans.push_back(i);
                    wi++;
                    usedChange = true;
                }
            }
        }

        return (wi == n) ? ans : vector<int>{};
    }
};