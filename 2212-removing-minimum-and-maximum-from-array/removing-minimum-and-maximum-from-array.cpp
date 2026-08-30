class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        
        int n = nums.size();
        
        int minIndex = 0;
        int maxIndex = 0;
        
        // Find index of minimum and maximum
        for(int i = 0; i < n; i++) {
            if(nums[i] < nums[minIndex]) {
                minIndex = i;
            }
            
            if(nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }
        
        // Case 1: Both from front
        int front = max(minIndex, maxIndex) + 1;
        
        // Case 2: Both from back
        int back = n - min(minIndex, maxIndex);
        
        // Case 3: One from front and one from back
        int mixed = min(minIndex, maxIndex) + 1 
                  + n - max(minIndex, maxIndex);
        
        return min({front, back, mixed});
    }
};