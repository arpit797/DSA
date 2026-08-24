class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<long long> prefix(n);
        prefix[0] = stones[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + stones[i];
        }
        
        // dp[i] = best score difference achievable by the player to move,
        // when the game state allows picking a prefix of length (i+1) or more (i >= 1)
        long long dp = prefix[n-1];
        for (int i = n-2; i >= 1; i--) {
            dp = max(dp, prefix[i] - dp);
        }
        
        return (int)dp;
    }
};