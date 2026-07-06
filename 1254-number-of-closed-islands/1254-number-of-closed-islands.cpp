class Solution {
public:

    int rr[4]={1,-1,0,0};
    int cc[4]={0,0,1,-1};

    int closedIsland(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>> q;

        // Left boundary
        for(int i=0;i<n;i++){

            if(grid[i][0]==0){

                q.push({i,0});
                grid[i][0]=1;

                while(!q.empty()){

                    int r=q.front().first;
                    int c=q.front().second;
                    q.pop();

                    for(int k=0;k<4;k++){

                        int ii=r+rr[k];
                        int jj=c+cc[k];

                        if(ii>=0 && ii<n && jj>=0 && jj<m && grid[ii][jj]==0){

                            q.push({ii,jj});
                            grid[ii][jj]=1;
                        }
                    }
                }
            }
        }

        // Top boundary
        for(int i=0;i<m;i++){

            if(grid[0][i]==0){

                q.push({0,i});
                grid[0][i]=1;

                while(!q.empty()){

                    int r=q.front().first;
                    int c=q.front().second;
                    q.pop();

                    for(int k=0;k<4;k++){

                        int ii=r+rr[k];
                        int jj=c+cc[k];

                        if(ii>=0 && ii<n && jj>=0 && jj<m && grid[ii][jj]==0){

                            q.push({ii,jj});
                            grid[ii][jj]=1;
                        }
                    }
                }
            }
        }

        // Right boundary
        for(int i=0;i<n;i++){

            if(grid[i][m-1]==0){

                q.push({i,m-1});
                grid[i][m-1]=1;

                while(!q.empty()){

                    int r=q.front().first;
                    int c=q.front().second;
                    q.pop();

                    for(int k=0;k<4;k++){

                        int ii=r+rr[k];
                        int jj=c+cc[k];

                        if(ii>=0 && ii<n && jj>=0 && jj<m && grid[ii][jj]==0){

                            q.push({ii,jj});
                            grid[ii][jj]=1;
                        }
                    }
                }
            }
        }

        // Bottom boundary
        for(int i=0;i<m;i++){

            if(grid[n-1][i]==0){

                q.push({n-1,i});
                grid[n-1][i]=1;

                while(!q.empty()){

                    int r=q.front().first;
                    int c=q.front().second;
                    q.pop();

                    for(int k=0;k<4;k++){

                        int ii=r+rr[k];
                        int jj=c+cc[k];

                        if(ii>=0 && ii<n && jj>=0 && jj<m && grid[ii][jj]==0){

                            q.push({ii,jj});
                            grid[ii][jj]=1;
                        }
                    }
                }
            }
        }

        int count=0;

        for(int i=1;i<n-1;i++){

            for(int j=1;j<m-1;j++){

                if(grid[i][j]==0){

                    q.push({i,j});
                    grid[i][j]=1;

                    while(!q.empty()){

                        int r=q.front().first;
                        int c=q.front().second;
                        q.pop();

                        for(int k=0;k<4;k++){

                            int ii=r+rr[k];
                            int jj=c+cc[k];

                            if(ii>=0 && ii<n && jj>=0 && jj<m && grid[ii][jj]==0){

                                q.push({ii,jj});
                                grid[ii][jj]=1;
                            }
                        }
                    }

                    count++;
                }
            }
        }

        return count;
    }
};