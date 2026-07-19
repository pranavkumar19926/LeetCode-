class Solution {
public:

    int ans(vector<int>& prices, bool buy, int val, int in, int c , vector<vector<vector<int>>> &dp) {

        if (in == prices.size() || c == val)
            return 0;

            if(dp[in][c][buy]!=-1){

                return dp[in][c][buy];
            }

        if (buy == false) {

            return dp[in][c][buy]=max(
                -prices[in] + ans(prices, true, val, in + 1, c , dp),
                ans(prices, false, val, in + 1, c , dp)
            );
        }
        else {

            return dp[in][c][buy]=max(
                prices[in] + ans(prices, false, val, in + 1, c + 1 , dp),
                ans(prices, true, val, in + 1, c , dp)
            );
        }
    }

    int maxProfit(int k, vector<int>& prices) {
               int n=prices.size();

        vector<vector<vector<int>>> dp( n+1 , vector<vector<int>>( k+1 , vector<int>(2 , -1) ) );

        return ans(prices, false, k, 0, 0 , dp);
    }
};