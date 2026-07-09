class Solution {
public:

    int findparent(int u, vector<int> &parent) {

        if (u == parent[u]) {
            return u;
        }

        return parent[u] = findparent(parent[u], parent);
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {

        vector<bool> ans;

        vector<pair<int,int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());

        vector<int> parent(n);
        vector<int> rank(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < n - 1; i++) {

            if (arr[i + 1].first - arr[i].first <= maxDiff) {

                int a = arr[i].second;
                int b = arr[i + 1].second;

                int ua = findparent(a, parent);
                int ub = findparent(b, parent);

                if (ua == ub)
                    continue;

                if (rank[ua] > rank[ub]) {

                    parent[ub] = ua;
                }
                else if (rank[ua] < rank[ub]) {

                    parent[ua] = ub;
                }
                else {

                    parent[ua] = ub;
                    rank[ub]++;
                }
            }
        }

        for (int i = 0; i < queries.size(); i++) {

            int aa = queries[i][0];
            int bb = queries[i][1];

            if (findparent(aa, parent) == findparent(bb, parent)) {
                ans.push_back(true);
            }
            else {
                ans.push_back(false);
            }
        }

        return ans;
    }
};