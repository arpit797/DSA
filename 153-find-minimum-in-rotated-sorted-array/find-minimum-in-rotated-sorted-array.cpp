class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low < high) {   // dhyan do: yahan '<' hai, '<=' nahi
            int mid = low + (high - low) / 2;
            
            if (nums[mid] > nums[high]) {
                // Minimum right half mein hai (mid khud minimum nahi ho sakta)
                low = mid + 1;
            } else {
                // Minimum mid ya usse left mein hai (mid khud candidate ho sakta hai)
                high = mid;
            }
        }
        
        return nums[high];  // ya nums[high], dono same honge yahan
    }
};