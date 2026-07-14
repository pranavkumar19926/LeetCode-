class Solution {
public:

   int r[8]={-1,1,0 ,0 ,-1 ,1,1 , -1};
   int c[8]={0,0,-1,1 , -1,1,-1, 1};


   bool check(int rr , int cc , int rmax , int cmax){


             if(rr>=0 && cc>=0 && rr<rmax && cc<cmax ){

                return true;
             }
             else{

                return false;

             }


   }






    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
         

         queue< pair<int,pair<int,int>> > pq;

         

         int n=grid.size();
         int m=grid[0].size();

         if(grid[0][0]==1 || grid[n-1][m-1]==1){

            return -1;
         }

          int ans=INT_MAX;
          int count=0;


          pq.push(make_pair(1 , make_pair(0,0)));

           grid[0][0]=1;

           while(!pq.empty()){

               int count=pq.front().first;

               int i=pq.front().second.first;

               int j=pq.front().second.second;

              if(i==n-1 && j==m-1){

                ans=min(ans , count);
              }

               pq.pop();

               for(int k=0 ; k<8 ; k++){
                 
                 int row=i+r[k];
                 int col=j+c[k];

                 if(check(row,col,n,m) && grid[row][col]==0){


                    pq.push(make_pair(count+1 , make_pair(row,col)));
                    grid[row][col]=1;
                 }


               }





           }


           if(ans==INT_MAX){

            return -1;
           }

           else{


           return ans;

           }

    }
};