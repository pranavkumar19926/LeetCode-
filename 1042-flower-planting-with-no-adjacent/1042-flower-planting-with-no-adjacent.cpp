class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        //adjacy matrix
        vector<vector<int>> adj(n+1 );
        
        for(int i=0 ; i< paths.size() ; i++){
              
              int u=paths[i][0];
              int v=paths[i][1];

              adj[u].push_back(v);

              adj[v].push_back(u);


        }
        

        vector<int> parent(n+1 , -1);

        vector<bool> visited(n+1 , false);

        vector<int> ans(n,-1);

      
        for(int i=1 ; i<=n ; i++){
               
                  if(!visited[i]){
                 queue<int> q;
                
                 q.push(i);
                 visited[i]=true;
                 while(!q.empty()){

                      int node=q.front();

                      q.pop();

                    

                     

                      unordered_map<int,int> s;
                      
                      s[1]=0;
                      s[2]=0;
                      s[3]=0;
                      s[4]=0;


                      for(int i=0 ; i<adj[node].size() ; i++){

                            if(!visited[adj[node][i]]){

                                q.push(adj[node][i]);

                                visited[adj[node][i]]=true;
                            }

                            

                                if(parent[adj[node][i]]!=-1){
                              s[parent[adj[node][i]] ]=1;

                                }




                      }

                             

                       
                       for(auto it=s.begin() ; it!=s.end() ; it++){
                                
                                if(it->second!=1){
                                      
                                      parent[node]=it->first;
                                      ans[node-1]=it->first;

                                      break;

                                }


                       }
                      



                      

                 }   


                  }        



        }




        return ans;



    }
};