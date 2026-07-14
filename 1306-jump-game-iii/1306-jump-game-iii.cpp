class Solution {
public:

    bool bfs(vector<vector<int>> &adj, int no, vector<int> &visited, vector<int> &arr) {

        int node = no;

        visited[node] = true;

        if (arr[node] == 0) {
            return true;
        }

        for (int i = 0; i < adj[node].size(); i++) {

            if (!visited[adj[node][i]]) {

                if (bfs(adj, adj[node][i], visited, arr)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool canReach(vector<int>& arr, int start) {

        int n = arr.size();

        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {

            int val1 = i + arr[i];
            int val2 = i - arr[i];

            if (val1 >= 0 && val1 < n) {

                if (val1 != i) {
                    adj[i].push_back(val1);
                }
            }

            if (val2 >= 0 && val2 < n) {

                if (val2 != i) {
                    adj[i].push_back(val2);
                }
            }
        }

        vector<int> visited(n, false);

        return bfs(adj, start, visited, arr);
    }
};