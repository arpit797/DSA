class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=0;
        unordered_set<int>st;
        long long result=0;
        long long currsum=0;
        while(j<n){

            while(st.count(nums[j])){
                currsum-=nums[i];
                st.erase(nums[i]);
                i++;
            }
            currsum+=nums[j];
            st.insert(nums[j]);

            if(j-i+1==k){
                result=max(result,currsum);
                currsum-=nums[i];
                st.erase(nums[i]);
                i++;
            }
            j++;
        }
        return result;
    }
};