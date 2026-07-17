class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {

        int s = triangle.size();

        vector<vector<int>> dp(s, vector<int>(s, -1));

        for (int i = 0; i < triangle[s - 1].size(); i++) {

            dp[s - 1][i] = triangle[s - 1][i];
        }

        for (int i = s - 2; i >= 0; i--) {

            for (int j = i; j >= 0; j--) {

                dp[i][j] = triangle[i][j] +
                           min(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }

        return dp[0][0];
    }
};