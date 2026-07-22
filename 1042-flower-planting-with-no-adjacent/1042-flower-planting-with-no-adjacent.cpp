class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {

        vector<vector<int>> adj(n + 1);

        for (int i = 0; i < paths.size(); i++) {

            int u = paths[i][0];
            int v = paths[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> flower(n + 1, 0);
        vector<int> ans(n);

        vector<bool> visited(n + 1, false);

        for (int i = 1; i <= n; i++) {

            if (!visited[i]) {

                queue<int> q;
                q.push(i);
                visited[i] = true;

                while (!q.empty()) {

                    int node = q.front();
                    q.pop();

                    bool used[5] = {false};

                    for (int j = 0; j < adj[node].size(); j++) {

                        int next = adj[node][j];

                        if (!visited[next]) {
                            visited[next] = true;
                            q.push(next);
                        }

                        if (flower[next] != 0)
                            used[flower[next]] = true;
                    }

                    for (int color = 1; color <= 4; color++) {

                        if (!used[color]) {

                            flower[node] = color;
                            ans[node - 1] = color;
                            break;
                        }
                    }
                }
            }
        }

        return ans;
    }
};