class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
         int count0 = 0;
        int count1 = 0;
        int count2 = 0;

        for (int ele : stones) {

            if (ele % 3 == 0) {
                count0++;
            }
            else if (ele % 3 == 1) {
                count1++;
            }
            else {
                count2++;
            }
        }

        // If count of remainder 0 stones is even
        if (count0 % 2 == 0) {

            return count1 >= 1 && count2 >= 1;
        }

        // If count of remainder 0 stones is odd
        return abs(count1 - count2) > 2;
    }
};