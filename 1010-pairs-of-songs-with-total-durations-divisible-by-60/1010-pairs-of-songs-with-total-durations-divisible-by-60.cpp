class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {

        int ans=0;

        vector<int> check(60 , 0);

        for(int i=0 ; i<time.size() ; i++){

            int a=time[i]%60;

            if(a==0){
                 
                 ans+=check[0];

            }
            else{
                
                ans+=check[60-a];
                
            }

            check[a]++;
        }


        return ans;

           
            
    }
};