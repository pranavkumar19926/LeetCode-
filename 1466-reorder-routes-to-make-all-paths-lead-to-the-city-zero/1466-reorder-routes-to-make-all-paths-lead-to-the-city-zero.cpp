class Solution {
public:

    int bfs(vector<vector<int>> &adj,
            vector<vector<int>> &rev,
            vector<bool> &directions,
            int n,
            int value) {

        directions[n] = true;

        // original edges (need reorder)
        for(int i = 0; i < adj[n].size(); i++) {

            int next = adj[n][i];

            if(directions[next] == false) {

                value = value + 1;   // edge needs reorder
                value = bfs(adj, rev, directions, next, value);
            }
        }

        // reverse edges (no reorder needed)
        for(int i = 0; i < rev[n].size(); i++) {

            int next = rev[n][i];

            if(directions[next] == false) {

                value = bfs(adj, rev, directions, next, value);
            }
        }

        return value;
    }

    int minReorder(int n, vector<vector<int>>& connections) {

        vector<vector<int>> adj(n);
        vector<vector<int>> rev(n);

        for(int i = 0; i < connections.size(); i++) {

            int node = connections[i][0];
            int connect = connections[i][1];

            adj[node].push_back(connect);   // original direction
            rev[connect].push_back(node);   // reverse direction
        }

        vector<bool> directions(n, false);

        int ans = bfs(adj, rev, directions, 0, 0);

        return ans;
    }
};
