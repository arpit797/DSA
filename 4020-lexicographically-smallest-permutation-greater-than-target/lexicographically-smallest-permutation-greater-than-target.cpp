class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;

        int candidateIdx = -1;   // sabse dooor (rightmost) valid break point
        vector<int> temp = cnt;  // running count jaise hum target consume karte jaayenge

        for (int i = 0; i < n; i++) {
            // Check: kya abhi ke available characters mein koi target[i] se bada hai?
            bool hasGreater = false;
            for (int c = target[i] - 'a' + 1; c < 26; c++) {
                if (temp[c] > 0) { hasGreater = true; break; }
            }
            if (hasGreater) candidateIdx = i;  // ye ek valid break point hai, update karo

            // Ab dekho kya prefix aage bhi match ho sakta hai (target[i] available hai kya)?
            if (temp[target[i] - 'a'] == 0) break;  // nahi, to aage prefix match nahi ho sakta
            temp[target[i] - 'a']--;                 // haan, to use karke aage badho
        }

        if (candidateIdx == -1) return "";  // koi bhi permutation target se bada nahi ban sakta

        // Ab actual answer banate hain candidateIdx tak
        vector<int> cnt2 = cnt;
        for (int j = 0; j < candidateIdx; j++) cnt2[target[j] - 'a']--;

        string ans = target.substr(0, candidateIdx);

        // candidateIdx par smallest character jo target[candidateIdx] se bada ho
        for (int c = target[candidateIdx] - 'a' + 1; c < 26; c++) {
            if (cnt2[c] > 0) {
                ans += (char)('a' + c);
                cnt2[c]--;
                break;
            }
        }

        // Baaki bache hue characters ascending order mein laga do (sabse chhota banane ke liye)
        for (int c = 0; c < 26; c++) {
            ans += string(cnt2[c], (char)('a' + c));
        }

        return ans;
    }
};