class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {

        int n = quiet.size();

        vector<vector<int>> adj(n);

        for (int i = 0; i < richer.size(); i++) {

            int u = richer[i][0];
            int v = richer[i][1];

            adj[u].push_back(v);
        }

        queue<int> q;

        vector<int> ans(n);

        vector<int> indegree(n, 0);

        for (int i = 0; i < adj.size(); i++) {

            for (int j = 0; j < adj[i].size(); j++) {

                indegree[adj[i][j]]++;
            }
        }

        for (int i = 0; i < indegree.size(); i++) {

            if (indegree[i] == 0) {

                q.push(i);
            }

            ans[i] = i;
        }

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            for (int i = 0; i < adj[node].size(); i++) {

                int next = adj[node][i];

                if (quiet[ans[node]] < quiet[ans[next]]) {

                    ans[next] = ans[node];
                }

                indegree[next]--;

                if (indegree[next] == 0) {

                    q.push(next);
                }
            }
        }

        return ans;
    }
};