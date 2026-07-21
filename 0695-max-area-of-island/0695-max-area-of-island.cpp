class Solution {
public:


      int r[4]={1,-1,0,0};
      int c[4]={0,0,1,-1};


      bool check(int row , int col , int rmax , int cmax){

              
              if(row>=0 && col>=0 && row<rmax && col<cmax){

                return true;
              }

              else{

                return false;
              }


      }


    int maxAreaOfIsland(vector<vector<int>>& grid) {

                int n=grid.size();
                int m=grid[0].size();

                queue<pair<int,int>> q;

                int ans=0;


                for(int i=0 ; i<n ; i++){
                    for(int j=0 ; j<m ; j++){
                          

                          if(grid[i][j]==1){
                                 
                                 q.push(make_pair(i , j));
                                 grid[i][j]=0;
                                 int cnt=0;

                                 while(!q.empty()){
                                           
                                           int rr=q.front().first;

                                           int cc=q.front().second;
                                           cnt++;

                                           q.pop();


                                        for(int k=0 ; k<4 ; k++){
                                             
                                             int ro=rr+r[k];

                                             int co=cc+c[k];


                                             if(check(ro , co ,n , m ) && grid[ro][co]==1){


                                                q.push(make_pair(ro,co));

                                                grid[ro][co]=0;
                                             }
                                                  

                                              
                                        }



                                 }

                                 ans=max(ans,cnt);

                          }



                    }
                }     


                return ans;              

    }
};