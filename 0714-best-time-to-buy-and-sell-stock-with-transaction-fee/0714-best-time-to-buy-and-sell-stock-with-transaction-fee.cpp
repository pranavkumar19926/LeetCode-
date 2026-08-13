class Solution { 
public: 
     
    int maxProfit(vector<int>& prices, int fee) { 
 
        int n=prices.size(); 
 
        int buy=prices[0]; 
        int profit=0; 
 
        for(int i=1 ; i<n ; i++){ 
            
            int val=prices[i]-buy; 
 
            int p=((prices[i]-buy)-fee); 
 
            if(p>0){ 
                  
                profit+=p; 
                buy=prices[i]-fee; 
 
            } 
            else{ 
                         
                if(val<0){ 
                            
                    buy=prices[i]; 
 
                } 
                         
            } 
 
        } 
 
        return profit; 
    } 
};