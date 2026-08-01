class Solution {
public:
    int dp[20][20];
    int solve(vector<int>& nums, int i, int j){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int pickLeft = nums[i] - solve(nums,i+1,j);
        int pickRight = nums[j] - solve(nums,i,j-1);
        
        return dp[i][j] = max(pickLeft,pickRight);
    }
    bool predictTheWinner(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n = nums.size();
        return solve(nums,0,n-1) >= 0;
    }
};