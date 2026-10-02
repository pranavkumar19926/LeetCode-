class Solution {
public:
    int combi(int val, vector<int>& coins, int i,
              vector<vector<int>>& dp) {

        if (val == 0)
            return 1;

        if (val < 0 || i == 0)
            return 0;

        if (dp[i][val] != -1)
            return dp[i][val];

        return dp[i][val] =
            combi(val - coins[i-1], coins, i, dp) +
            combi(val, coins, i-1, dp);
    }

    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        vector<vector<int>> dp(n + 1,
                               vector<int>(amount + 1, -1));

        return combi(amount, coins, n, dp);
    }
};