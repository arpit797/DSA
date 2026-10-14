class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            int minidx=i;
            for(int j=i+1;j<n;j++){
                if(nums[j]<nums[minidx])
                minidx=j;
            }
            swap(nums[i],nums[minidx]);
        }
    }
};