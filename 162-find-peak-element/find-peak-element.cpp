class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid] < nums[mid + 1]) {
                // Upward slope -> peak right side mein hai
                low = mid + 1;
            } else {
                // Downward slope -> peak mid ya left side mein hai
                high = mid;
            }
        }
        
        return low;  // low == high, yahi peak ka index hai
    }
};