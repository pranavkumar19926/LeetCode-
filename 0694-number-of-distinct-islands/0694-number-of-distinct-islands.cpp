
class Solution {
public:
    int r[4] = {1, -1, 0, 0};
    int c[4] = {0, 0, 1, -1};

    bool check(int row, int col, int rmax, int cmax) {
        return row >= 0 && col >= 0 &&
               row < rmax && col < cmax;
    }

    void dfs(int rr, int cc,
             int baseR, int baseC,
             vector<vector<int>>& grid,
             vector<vector<bool>>& visited,
             vector<pair<int, int>>& shape) {

        visited[rr][cc] = true;

        // Store coordinates relative to the starting cell
        shape.push_back({rr - baseR, cc - baseC});

        for (int k = 0; k < 4; k++) {
            int re = rr + r[k];
            int ce = cc + c[k];

            if (check(re, ce, grid.size(), grid[0].size()) &&
                grid[re][ce] == 1 &&
                !visited[re][ce]) {

                dfs(re, ce, baseR, baseC,
                    grid, visited, shape);
            }
        }
    }

    int numDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(
            n, vector<bool>(m, false)
        );

        set<vector<pair<int, int>>> st;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1 && !visited[i][j]) {
                    vector<pair<int, int>> shape;

                    dfs(i, j, i, j, grid,
                        visited, shape);

                    sort(shape.begin(), shape.end());

                    st.insert(shape);
                }
            }
        }

        return st.size();
    }
};
