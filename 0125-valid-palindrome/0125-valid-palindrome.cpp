class Solution {
public:
    bool isPalindrome(string s) {
          string add="";

          for(int i=0 ; i<s.size() ; i++){
                  

                  if( isalnum(s[i])){
                      if(isupper(s[i])){
                            
                            char a=tolower(s[i]);
                            add+=a;

                      }
                      else{
                    add+=s[i];
                      }
                  }

            

          }

           int first=0;
           int second=add.size()-1;

           while(first <=second){


                 if(add[first]==add[second]){
                     first++;
                     second--;

                 }
                 else{

                    return false;
                 }
           }


           return true;

    }
};