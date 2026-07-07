class Solution {
public:

    int ans(vector<int>& prices, bool buy, int i, int count,
            vector<vector<vector<int>>> &dp) {

        // Base conditions
        if (i == prices.size() || count == 2) {
            return 0;
        }

        if (dp[i][count][buy] != -1) {
            return dp[i][count][buy];
        }

        if (buy) {

            return dp[i][count][buy] = max(
                -prices[i] + ans(prices, false, i + 1, count, dp),
                ans(prices, true, i + 1, count, dp)
            );

        } else {

            return dp[i][count][buy] = max(
                prices[i] + ans(prices, true, i + 1, count + 1, dp),
                ans(prices, false, i + 1, count, dp)
            );

        }
    }

    int maxProfit(vector<int>& prices) {

        vector<vector<vector<int>>> dp(
            prices.size(),
            vector<vector<int>>(3, vector<int>(2, -1))
        );

        return ans(prices, true, 0, 0, dp);
    }
};