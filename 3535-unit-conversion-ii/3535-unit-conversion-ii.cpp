class Solution {
public:

    const long long MOD = 1000000007;


    long long power(long long a, long long b) {

        long long ans = 1;

        while(b > 0) {

            if(b % 2 == 1) {
                ans = (ans * a) % MOD;
            }

            a = (a * a) % MOD;

            b = b / 2;
        }

        return ans;
    }



    vector<int> queryConversions(
        vector<vector<int>>& conversions,
        vector<vector<int>>& queries
    ) {


        int n = 0;


        for(int i = 0; i < conversions.size(); i++) {

            n = max(
                n,
                max(
                    conversions[i][0],
                    conversions[i][1]
                ) + 1
            );
        }


        vector<vector<pair<int,long long>>> adj(n);


        for(int i = 0; i < conversions.size(); i++) {

            int u = conversions[i][0];

            int v = conversions[i][1];

            long long num = conversions[i][2];


            // u -> v = num
            adj[u].push_back(
                make_pair(v, num)
            );


            // v -> u = 1/num
            long long inverse =
                power(num, MOD - 2);


            adj[v].push_back(
                make_pair(v == u ? u : u, inverse)
            );
        }



        // value[i] = conversion ratio from 0 -> i

        vector<long long> value(n, 0);

        vector<bool> visited(n, false);


        queue<int> q;


        value[0] = 1;

        visited[0] = true;

        q.push(0);



        while(!q.empty()) {

            int no = q.front();

            q.pop();


            for(int i = 0; i < adj[no].size(); i++) {

                int nn = adj[no][i].first;

                long long ratio = adj[no][i].second;


                if(!visited[nn]) {

                    visited[nn] = true;


                    value[nn] =
                        (value[no] * ratio) % MOD;


                    q.push(nn);
                }
            }
        }



        vector<int> ans(queries.size());


        for(int i = 0; i < queries.size(); i++) {

            int u = queries[i][0];

            int v = queries[i][1];


            // u -> v
            //
            // 0 -> u = value[u]
            // 0 -> v = value[v]
            //
            // u -> v = value[v] / value[u]

            long long inverse =
                power(value[u], MOD - 2);


            ans[i] =
                (value[v] * inverse) % MOD;
        }


        return ans;
    }
};