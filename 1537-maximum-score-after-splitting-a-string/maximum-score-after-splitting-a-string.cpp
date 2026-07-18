class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int total_one = 0;
        for (char ch : s) {
            if (ch == '1')
                total_one++;
        }

        int count_zero = 0;
        int count_one_left = 0;
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0')
                count_zero++;
            else
                count_one_left++;

            ans = max(ans, count_zero + (total_one - count_one_left));
        }

        return ans;
    }
};