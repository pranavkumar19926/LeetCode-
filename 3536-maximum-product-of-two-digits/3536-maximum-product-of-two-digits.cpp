class Solution {
public:
    
    int maxProduct(int n) {


          int firstmax=INT_MIN;
          int secondmax=INT_MIN;

                
                
             while(n!=0){

                
            
                int val=n%10;

                
                    if(val >= firstmax){
                    secondmax=firstmax;
                   firstmax=val;

                    } else{

                        secondmax=max(secondmax , val);
                    }
                n=n/10;


             }


             int ans=firstmax * secondmax ;

             return ans;
    }
};