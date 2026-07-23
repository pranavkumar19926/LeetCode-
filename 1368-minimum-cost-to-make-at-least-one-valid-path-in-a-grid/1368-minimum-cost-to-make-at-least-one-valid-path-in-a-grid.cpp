class Solution {
public:

bool check(int row , int col , int rmax , int cmax , vector<vector<int>> & grid){
         if(row>=0 && col >=0 && row<rmax && col<cmax){
                    return true;
         }
         else{
            return false;
         }
}

    int minCost(vector<vector<int>>& grid) {

               int n=grid.size();
               int m=grid[0].size();

              // FIX 1: Use a dist array instead of modifying grid values
              vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

              // FIX 2: Use deque instead of queue for 0-1 BFS
              deque<pair<int, pair<int,int> >> q;

              q.push_back(make_pair(0,make_pair(0,0) ));

              dist[0][0]=0;

         while(!q.empty() ){
            
            int c=q.front().first;
            int i=q.front().second.first;
            int j=q.front().second.second;

            q.pop_front();

            if(i==n-1 && j==m-1){
                   return c;
            }

            // Skip stale entries
            if(c > dist[i][j]) continue;


            if(grid[i][j]==1){

                   if(check(i, j+1 , n , m , grid)){
                        if(c < dist[i][j+1]){
                              dist[i][j+1]=c;
                              q.push_front(make_pair(c,make_pair(i,j+1) ));
                        }
                   }
                   if(check(i, j-1 , n , m , grid)){
                        if(c+1 < dist[i][j-1]){
                              dist[i][j-1]=c+1;
                              q.push_back(make_pair(c+1,make_pair(i,j-1) ));
                        }
                   }
                   if(check(i+1, j , n , m , grid)){
                        if(c+1 < dist[i+1][j]){
                              dist[i+1][j]=c+1;
                              q.push_back(make_pair(c+1,make_pair(i+1,j) ));
                        }
                   }
                   if(check(i-1, j , n , m , grid)){
                        if(c+1 < dist[i-1][j]){
                              dist[i-1][j]=c+1;
                              q.push_back(make_pair(c+1,make_pair(i-1,j) ));
                        }
                   }
            }
            

            else if(grid[i][j]==2){
                   
                   if(check(i, j+1 , n , m , grid)){
                        if(c+1 < dist[i][j+1]){
                              dist[i][j+1]=c+1;
                              q.push_back(make_pair(c+1,make_pair(i,j+1) ));
                        }
                   }
                   if(check(i, j-1 , n , m , grid)){
                        if(c < dist[i][j-1]){
                              dist[i][j-1]=c;
                              q.push_front(make_pair(c,make_pair(i,j-1) ));
                        }
                   }
                   if(check(i+1, j , n , m , grid)){
                        if(c+1 < dist[i+1][j]){
                              dist[i+1][j]=c+1;
                              q.push_back(make_pair(c+1,make_pair(i+1,j) ));
                        }
                   }
                   if(check(i-1, j , n , m , grid)){
                        if(c+1 < dist[i-1][j]){
                              dist[i-1][j]=c+1;
                              q.push_back(make_pair(c+1,make_pair(i-1,j) ));
                        }
                   }
            }

            else if(grid[i][j]==3){
                        
                   if(check(i, j+1 , n , m , grid)){
                        if(c+1 < dist[i][j+1]){
                              dist[i][j+1]=c+1;
                              q.push_back(make_pair(c+1,make_pair(i,j+1) ));
                        }
                   }
                   if(check(i, j-1 , n , m , grid)){
                        if(c+1 < dist[i][j-1]){
                              dist[i][j-1]=c+1;
                              q.push_back(make_pair(c+1,make_pair(i,j-1) ));
                        }
                   }
                   if(check(i+1, j , n , m , grid)){
                        if(c < dist[i+1][j]){
                              dist[i+1][j]=c;
                              q.push_front(make_pair(c,make_pair(i+1,j) ));
                        }
                   }
                   if(check(i-1, j , n , m , grid)){
                        if(c+1 < dist[i-1][j]){
                              dist[i-1][j]=c+1;
                              q.push_back(make_pair(c+1,make_pair(i-1,j) ));
                        }
                   }
            }

            else{

                   if(check(i, j+1 , n , m , grid)){
                        if(c+1 < dist[i][j+1]){
                              dist[i][j+1]=c+1;
                              q.push_back(make_pair(c+1,make_pair(i,j+1) ));
                        }
                   }
                   if(check(i, j-1 , n , m , grid)){
                        if(c+1 < dist[i][j-1]){
                              dist[i][j-1]=c+1;
                              q.push_back(make_pair(c+1,make_pair(i,j-1) ));
                        }
                   }
                   if(check(i+1, j , n , m , grid)){
                        if(c+1 < dist[i+1][j]){
                              dist[i+1][j]=c+1;
                              q.push_back(make_pair(c+1,make_pair(i+1,j) ));
                        }
                   }
                   if(check(i-1, j , n , m , grid)){
                        if(c < dist[i-1][j]){
                              dist[i-1][j]=c;
                              q.push_front(make_pair(c,make_pair(i-1,j) ));
                        }
                   }
            }
         }

       return dist[n-1][m-1];
    }
};