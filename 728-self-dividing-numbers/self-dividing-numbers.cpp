class Solution {
public:
    bool isSelfDividing(int n) {
        int temp = n;

        while (temp > 0) {
            int digit = temp % 10;      // get last digit

            if (digit == 0) return false;       // can't divide by 0
            if (n % digit != 0) return false;   // n not divisible by this digit

            temp = temp / 10;           // remove last digit
        }
        return true;    // every digit passed
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;

        for (int i = left; i <= right; i++) {
            if (isSelfDividing(i)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};