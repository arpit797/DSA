class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int n = nums.size();
        int high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return true;
            }
            
            // Duplicate handling: agar low, mid, high teeno equal hain,
            // to hum decide nahi kar sakte kaunsa half sorted hai
            // isliye bas dono taraf se shrink kar do
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
            }
            else if (nums[low] <= nums[mid]) {
                // Left half sorted hai
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;  // target left half mein hai
                } else {
                    low = mid + 1;   // target right half mein hoga
                }
            }
            else {
                // Right half sorted hai
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;   // target right half mein hai
                } else {
                    high = mid - 1;  // target left half mein hoga
                }
            }
        }
        return false;
    }
}; 