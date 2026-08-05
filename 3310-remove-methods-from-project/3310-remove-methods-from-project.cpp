class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        vector<vector<int>> adj(n);

        for (int i = 0; i < invocations.size(); i++) {

            int u = invocations[i][0];
            int v = invocations[i][1];

            adj[u].push_back(v);
        }

        vector<bool> check(n, false);
        vector<bool> visited(n, false);
        vector<int> ans;

        queue<int> q;

        q.push(k);
        visited[k] = true;
        check[k] = true;

        // Mark all suspicious methods
        while (!q.empty()) {

            int node = q.front();
            q.pop();

            for (int i = 0; i < adj[node].size(); i++) {

                if (!visited[adj[node][i]]) {

                    visited[adj[node][i]] = true;
                    check[adj[node][i]] = true;
                    q.push(adj[node][i]);
                }
            }
        }

        // Check if any non-suspicious method invokes a suspicious method
        for (int i = 0; i < invocations.size(); i++) {

            int u = invocations[i][0];
            int v = invocations[i][1];

            if (!check[u] && check[v]) {

                vector<int> all;

                for (int j = 0; j < n; j++)
                    all.push_back(j);

                return all;
            }
        }

        // Return remaining methods
        for (int i = 0; i < n; i++) {

            if (!check[i])
                ans.push_back(i);
        }

        return ans;
    }
};