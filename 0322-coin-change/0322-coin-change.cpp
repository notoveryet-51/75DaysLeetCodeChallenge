class Solution {
public:
    int combinations(vector<int> &coins, int amount, vector<int> &dp) {
        if (amount==0) return 0;
        if (amount<0) return 1e9;
        if (dp[amount]!=-1) return dp[amount];
        int mini=1e9;
        for (int i=0; i<coins.size(); i++) {
            mini=min(mini, 1+combinations(coins, amount-coins[i], dp));
        }
        return dp[amount]=mini;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        int ans=combinations(coins, amount, dp);
        return (ans>=1e9 ? -1 : ans);
    }
};