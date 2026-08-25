class Solution {
public:
  
  int digits(int num){

           
           int val=1;
           int count=0;

           while(num / val !=0){
                 
                 count++;

                 val=val*10;


           }

           return count;

        
  }

    bool isArmstrong(int n) {
          
            
            int digi=digits(n);


            int nu=n;
            int ans=0;

            while(nu!=0){

             int space=nu%10;
             ans+=pow(space,digi);
            nu=nu/10;

            }


            if(ans==n){
                return true;
            }
            else{

                return false;
            }



    }
};