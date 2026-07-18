class Solution {
public:

        int gcd(int a , int b){

               
               if(b==0){

                return a;
               }
 


            return gcd(b , a%b );
        }






    int findGCD(vector<int>& nums) {

                  int maxx=INT_MIN;
                  int minn=INT_MAX;

                  for(int i=0 ; i<nums.size() ; i++){
                            

                            if(maxx < nums[i]){
                                
                                maxx=nums[i];

                            }

                            if(minn > nums[i]){

                                 minn=nums[i];

                            }



                  }  

                   

                   return gcd(minn , maxx );







    }
};