class Solution {
public:
    
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        for(int i = 0; i < edges.size(); i++){
            int node = edges[i][0];
            int connect = edges[i][1];

            adj[node].push_back(connect);
            adj[connect].push_back(node);
        }    

        vector<bool> visited(n, false);
        queue<int> q;
        int ans = 0;

        for(int i = 0; i < n; i++){

            if(visited[i])
                continue;

            q.push(i);
            visited[i] = true;

            int cnt = 0;
            int edgeCount = 0;

            while(!q.empty()){

                int node = q.front();
                q.pop();

                cnt++;
                edgeCount += adj[node].size();

                for(int j = 0; j < adj[node].size(); j++){

                    if(!visited[adj[node][j]]){
                        visited[adj[node][j]] = true;
                        q.push(adj[node][j]);
                    }
                }
            }

            // complete graph condition
            if(edgeCount == cnt * (cnt - 1)){
                ans++;
            }
        }

        return ans;
    }
};
