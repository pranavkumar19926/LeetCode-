class Solution {
public:

    int change(int amount, vector<int>& coins) {

        vector<int> dp(amount + 1, 0);

        dp[0] = 1;

        for (int coin : coins) {

            for (int j = coin; j <= amount; j++) {

                long long ways =
                    (long long)dp[j] + dp[j - coin];

                if (ways > INT_MAX)
                    dp[j] = INT_MAX;
                else
                    dp[j] = (int)ways;
            }
        }

        return dp[amount];
    }
};