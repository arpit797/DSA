class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i = 0, j = n - 1;

        while (i < j) {
            int currsum = numbers[i] + numbers[j];

            if (currsum == target) {
                return {i + 1, j + 1};
            }
            else if (currsum < target) {
                i++;
            }
            else {
                j--;
            }
        }

        return {};
    }
};