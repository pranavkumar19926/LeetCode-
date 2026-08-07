class Solution {
public:

    struct Node {
        int start;
        int len;
    };

    string longestPalindrome(string s) {

        int n = s.size();

        if (n == 0)
            return "";

        vector<vector<int>> check(n, vector<int>(n, 0));
        vector<vector<Node>> dp(n, vector<Node>(n));

        // Length = 1
        for (int i = 0; i < n; i++) {
            check[i][i] = 1;
            dp[i][i] = {i, 1};
        }

        // Length = 2 to n
        for (int len = 2; len <= n; len++) {

            for (int i = 0; i + len - 1 < n; i++) {

                int j = i + len - 1;

                if (s[i] == s[j]) {

                    if (len == 2)
                        check[i][j] = 1;
                    else
                        check[i][j] = check[i + 1][j - 1];
                }

                if (check[i][j]) {

                    dp[i][j] = {i, len};
                }
                else {

                    if (dp[i + 1][j].len >= dp[i][j - 1].len)
                        dp[i][j] = dp[i + 1][j];
                    else
                        dp[i][j] = dp[i][j - 1];
                }
            }
        }

        return s.substr(dp[0][n - 1].start, dp[0][n - 1].len);
    }
};