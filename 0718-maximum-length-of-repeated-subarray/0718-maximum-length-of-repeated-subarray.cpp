class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();

        vector<vector<vector<int>>> dp(
            n + 1,
            vector<vector<int>>(m + 1, vector<int>(2, 0))
        );

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                // check == true
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j][1] = 1 + dp[i - 1][j - 1][1];
                }
                else {
                    dp[i][j][1] = 0;
                }

                // check == false
                if (nums1[i - 1] == nums2[j - 1]) {

                    dp[i][j][0] = max(
                        1 + dp[i - 1][j - 1][1],
                        max(dp[i - 1][j][0],
                            dp[i][j - 1][0])
                    );
                }
                else {

                    dp[i][j][0] = max(
                        dp[i - 1][j][0],
                        dp[i][j - 1][0]
                    );
                }
            }
        }

        return dp[n][m][0];
    }
};