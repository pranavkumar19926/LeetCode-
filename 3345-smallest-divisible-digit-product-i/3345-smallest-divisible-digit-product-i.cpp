class Solution {
public:


   int value(int num ){
             
             int ans=1;

             while(num!=0){


                int digit = num% 10;

                num=num/10;

                ans=ans* digit ;
             }


             return ans;


   }

    int smallestNumber(int n, int t) {
                
                  

                while( value(n) % t !=0){
                     
                     n++;
                }


                return n;

    }
};