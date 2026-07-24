class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {

        vector<int> indegree(n + 1, 0);

        vector<vector<int>> adj(n + 1);

        for(int i = 0; i < relations.size(); i++) {

            int u = relations[i][0];
            int v = relations[i][1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;

        for(int i = 1; i <= n; i++) {

            if(indegree[i] == 0) {

                q.push(i);
            }
        }

        int ans = 0;
        int count = 0;

        while(!q.empty()) {

            int size = q.size();

            ans++;

            while(size--) {

                int top = q.front();
                q.pop();

                count++;

                for(int i = 0; i < adj[top].size(); i++) {

                    indegree[adj[top][i]]--;

                    if(indegree[adj[top][i]] == 0) {

                        q.push(adj[top][i]);
                    }
                }
            }
        }

        if(count != n) {

            return -1;
        }

        return ans;
    }
};