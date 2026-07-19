class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> ans(n, vector<int>(m, 0));

        int val = 0;

        // Initialize last row
        for (int i = 0; i < m; i++) {
            ans[n - 1][i] = matrix[n - 1][i] - '0';
            val = max(val, ans[n - 1][i]);
        }

        // Initialize last column
        for (int i = 0; i < n; i++) {
            ans[i][m - 1] = matrix[i][m - 1] - '0';
            val = max(val, ans[i][m - 1]);
        }

        // Fill remaining cells
        for (int i = n - 2; i >= 0; i--) {
            for (int j = m - 2; j >= 0; j--) {

                if (matrix[i][j] == '1') {

                    int a = ans[i + 1][j + 1];
                    int b = ans[i + 1][j];
                    int c = ans[i][j + 1];

                    int va = min({a, b, c});

                    ans[i][j] = va + 1;

                    val = max(val, ans[i][j]);
                }
            }
        }

        return val * val;
    }
};