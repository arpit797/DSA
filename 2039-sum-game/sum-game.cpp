class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int sum1 = 0, sum2 = 0, cnt1 = 0, cnt2 = 0;

        // first half
        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?') cnt1++;
            else sum1 += num[i] - '0';
        }
        // second half
        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?') cnt2++;
            else sum2 += num[i] - '0';
        }

        int cnt = cnt1 + cnt2;

        // agar total '?' odd hai, Alice hamesha jeetegi
        if (cnt % 2 == 1) return true;

        // even case: Bob mirror strategy use kar sakta hai agar balance ho
        return (sum1 - sum2) != 9 * (cnt2 - cnt1) / 2;
    }
};