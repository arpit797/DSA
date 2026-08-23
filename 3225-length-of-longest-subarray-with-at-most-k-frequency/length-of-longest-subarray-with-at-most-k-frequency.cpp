class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int left = 0, maxLen = 0;

        for (int right = 0; right < nums.size(); right++) {
            freq[nums[right]]++;

            // agar current element ki frequency k se zyada ho gayi,
            // window ko left se shrink karo jab tak valid na ho jaye
            while (freq[nums[right]] > k) {
                freq[nums[left]]--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};