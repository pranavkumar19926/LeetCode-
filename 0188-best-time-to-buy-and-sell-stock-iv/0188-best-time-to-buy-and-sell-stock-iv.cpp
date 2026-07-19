class Solution {
public:



    int maxProfit(int k, vector<int>& prices) {
               int n=prices.size();
                int p=k;
        vector<vector<vector<int>>> dp( n+1 , vector<vector<int>>( k+1 , vector<int>(2 , 0) ) );

        for(int i=n-1 ; i>=0 ; i--){

            for(int j=p-1 ; j>=0 ; j--){

                for(int k=0 ; k<=1 ; k++){
                        
                           if (k == 0) {

             dp[i][j][k]=max(
                -prices[i] + dp[i+1][j][1], dp[i+1][j][0]
            );
        }
        else {

             dp[i][j][k]=max(
                prices[i] +dp[i+1][j+1][0], dp[i+1][j][1]
            );
       

                }
            }
        }

        }

        return dp[0][0][0] ;
    }
};