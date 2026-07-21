class Solution {
public:

    int r[4] = {0, 0, 1, -1};
    int c[4] = {1, -1, 0, 0};

    bool check(int row, int col, int rmax, int cmax) {

        if (row >= 0 && col >= 0 && row < rmax && col < cmax) {
            return true;
        }
        else {
            return false;
        }
    }

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {

        int n = isWater.size();
        int m = isWater[0].size();

        queue<pair<int, int>> q;

        // Water = 0, Land = -1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (isWater[i][j] == 1) {
                    isWater[i][j] = 0;
                    q.push({i, j});
                }
                else {
                    isWater[i][j] = -1;
                }
            }
        }

        while (!q.empty()) {

            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {

                int rr = row + r[k];
                int cc = col + c[k];

                if (check(rr, cc, n, m) && isWater[rr][cc] == -1) {

                    isWater[rr][cc] = isWater[row][col] + 1;
                    q.push({rr, cc});
                }
            }
        }

        return isWater;
    }
};