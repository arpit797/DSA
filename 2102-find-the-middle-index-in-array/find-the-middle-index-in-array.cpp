class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int totalSum=0;
        for(int x:nums){
            totalSum+=x;
        }
        int leftsum=0;
        for(int i=0;i<nums.size();i++){
            int rightsum=totalSum-leftsum-nums[i];
            if(leftsum==rightsum){
                return i;
            }
            leftsum+=nums[i];
        }
        return -1;
    }
};