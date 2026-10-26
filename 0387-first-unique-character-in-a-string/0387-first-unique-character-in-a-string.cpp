class Solution {
public:
    int firstUniqChar(string s) {
                unordered_map<char,pair<int,int>> mp;

                for(int i=0 ; i<s.size() ; i++){
                      
                      char a=s[i];

                      if(!mp.count(a)){
                           
                             
                           mp[a]={i , 1};
                      }
                      else{
                         mp[a].second++;

                      }


                } 


                for(int i=0 ; i<s.size() ; i++){

                     if(mp[s[i]].second==1){

                        return i;
                     }
                }  

                return -1;
    }
};