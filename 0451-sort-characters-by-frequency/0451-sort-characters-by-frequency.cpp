class Solution {
public:
    string frequencySort(string s) {
      map<char,int> mp;
 



      for(int i=0 ; i<s.size() ; i++){
          
          if(!mp.count(s[i])){
          mp[s[i]]=1;
          }
          else{

            mp[s[i]]++;
          }
      }

      priority_queue<pair<int,char> > pq;

         
       string ans="";

      for(auto it=mp.begin() ; it!=mp.end() ; it++){

            int cn=it->second;
            char a=it->first;

             pq.push(make_pair(cn , a));
           
      }

      while(!pq.empty()){

         int cn=pq.top().first;
         char add=pq.top().second;
         pq.pop();

         while(cn--){

            ans+=add;
         }

      }

      return ans;


    }
};