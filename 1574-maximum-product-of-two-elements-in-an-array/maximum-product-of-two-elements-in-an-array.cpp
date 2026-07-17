class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxproduct=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int product=(nums[i]-1)*(nums[j]-1);
                maxproduct=max(product,maxproduct);
            }
        }
        return maxproduct;
    }
};