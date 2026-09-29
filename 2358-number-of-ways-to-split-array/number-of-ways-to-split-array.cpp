class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        long long total=0;
        for(int x:nums){
            total+=x;
        }
        long long leftsum=0,rightsum=0;
        int count=0;
        for(int i=0;i<n-1;i++){
            leftsum+=nums[i];

            rightsum=total-leftsum;
            if(leftsum>=rightsum){
                count++;
            }
        }
        return count;
    }
};