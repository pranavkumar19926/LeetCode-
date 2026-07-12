class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {

        int n = boxGrid.size();
        int m = boxGrid[0].size();

        vector<vector<char>> ans(m, vector<char>(n, '.'));

        for (int i = 0; i < n; i++) {

            int k = m;
            int l = n - i - 1;

            for (int j = m - 1; j >= 0; j--) {

                char val = boxGrid[i][j];

                if (val == '*') {

                    ans[j][l] = '*';
                    k = j;

                }
                else if (val == '#') {

                    k--;
                    ans[k][l] = '#';
                }
            }
        }

        return ans;
    }
};