class Solution {
public:

    int r[4] = {1, -1, 0, 0};
    int c[4] = {0, 0, 1, -1};

    bool check(int row, int col, int maxr, int maxc) {

        if (row >= 0 && col >= 0 && row < maxr && col < maxc) {
            return true;
        }
        else {
            return false;
        }
    }


    bool dfs(vector<vector<char>>& board,
             string& word,
             int row,
             int col,
             int indi,
             vector<vector<bool>>& visited) {

        if (indi == word.size() - 1) {
            return true;
        }


        visited[row][col] = true;


        for (int k = 0; k < 4; k++) {

            int rr = row + r[k];
            int cc = col + c[k];


            if (
                check(rr, cc, board.size(), board[0].size()) &&
                board[rr][cc] == word[indi + 1] &&
                !visited[rr][cc]
            ) {

                if (dfs(board, word, rr, cc, indi + 1, visited)) {
                    return true;
                }
            }
        }


        // Backtracking
        visited[row][col] = false;

        return false;
    }


    bool exist(vector<vector<char>>& board, string word) {

        int rmax = board.size();
        int cmax = board[0].size();


        vector<vector<bool>> visited(
            rmax,
            vector<bool>(cmax, false)
        );


        for (int i = 0; i < rmax; i++) {

            for (int j = 0; j < cmax; j++) {

                if (board[i][j] == word[0]) {

                    if (dfs(board, word, i, j, 0, visited)) {
                        return true;
                    }
                }
            }
        }


        return false;
    }
};