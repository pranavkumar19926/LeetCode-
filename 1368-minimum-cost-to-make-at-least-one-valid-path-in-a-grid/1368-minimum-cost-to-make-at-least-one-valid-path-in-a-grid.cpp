class Solution {
public:

bool check(int row , int col , int rmax , int cmax){

    if(row>=0 && col>=0 && row<rmax && col<cmax){
        return true;
    }

    return false;
}

int minCost(vector<vector<int>>& grid) {

    int n=grid.size();
    int m=grid[0].size();

    vector<vector<int>> dist(n,vector<int>(m,INT_MAX));

    deque<pair<int,int>> q;

    q.push_front(make_pair(0,0));

    dist[0][0]=0;

    while(!q.empty()){

        int i=q.front().first;
        int j=q.front().second;

        q.pop_front();

        int c=dist[i][j];

        if(grid[i][j]==1){

            if(check(i,j+1,n,m) && c<dist[i][j+1]){
                dist[i][j+1]=c;
                q.push_front(make_pair(i,j+1));
            }

            if(check(i,j-1,n,m) && c+1<dist[i][j-1]){
                dist[i][j-1]=c+1;
                q.push_back(make_pair(i,j-1));
            }

            if(check(i+1,j,n,m) && c+1<dist[i+1][j]){
                dist[i+1][j]=c+1;
                q.push_back(make_pair(i+1,j));
            }

            if(check(i-1,j,n,m) && c+1<dist[i-1][j]){
                dist[i-1][j]=c+1;
                q.push_back(make_pair(i-1,j));
            }

        }

        else if(grid[i][j]==2){

            if(check(i,j+1,n,m) && c+1<dist[i][j+1]){
                dist[i][j+1]=c+1;
                q.push_back(make_pair(i,j+1));
            }

            if(check(i,j-1,n,m) && c<dist[i][j-1]){
                dist[i][j-1]=c;
                q.push_front(make_pair(i,j-1));
            }

            if(check(i+1,j,n,m) && c+1<dist[i+1][j]){
                dist[i+1][j]=c+1;
                q.push_back(make_pair(i+1,j));
            }

            if(check(i-1,j,n,m) && c+1<dist[i-1][j]){
                dist[i-1][j]=c+1;
                q.push_back(make_pair(i-1,j));
            }

        }

        else if(grid[i][j]==3){

            if(check(i,j+1,n,m) && c+1<dist[i][j+1]){
                dist[i][j+1]=c+1;
                q.push_back(make_pair(i,j+1));
            }

            if(check(i,j-1,n,m) && c+1<dist[i][j-1]){
                dist[i][j-1]=c+1;
                q.push_back(make_pair(i,j-1));
            }

            if(check(i+1,j,n,m) && c<dist[i+1][j]){
                dist[i+1][j]=c;
                q.push_front(make_pair(i+1,j));
            }

            if(check(i-1,j,n,m) && c+1<dist[i-1][j]){
                dist[i-1][j]=c+1;
                q.push_back(make_pair(i-1,j));
            }

        }

        else{

            if(check(i,j+1,n,m) && c+1<dist[i][j+1]){
                dist[i][j+1]=c+1;
                q.push_back(make_pair(i,j+1));
            }

            if(check(i,j-1,n,m) && c+1<dist[i][j-1]){
                dist[i][j-1]=c+1;
                q.push_back(make_pair(i,j-1));
            }

            if(check(i+1,j,n,m) && c+1<dist[i+1][j]){
                dist[i+1][j]=c+1;
                q.push_back(make_pair(i+1,j));
            }

            if(check(i-1,j,n,m) && c<dist[i-1][j]){
                dist[i-1][j]=c;
                q.push_front(make_pair(i-1,j));
            }

        }

    }

    return dist[n-1][m-1];
}
};