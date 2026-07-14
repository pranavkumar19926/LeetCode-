class Solution {
public:

    int r[4]={1,-1,0,0};
    int c[4]={0,0,1,-1};

    bool check(int row , int col , int rmax , int cmax ){

        if(row>=0 && col>=0 && row<rmax && col<cmax){
            return true;
        }
        else{
            return false;
        }
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

        int rr=maze.size();
        int cc=maze[0].size();

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        int l=entrance[0];
        int m=entrance[1];

        pq.push(make_pair(0 , make_pair(l , m)));

        maze[l][m]='+';

        int ans=-1;

        while(!pq.empty()){

            int i=pq.top().second.first;
            int j=pq.top().second.second;
            int count=pq.top().first;

            pq.pop();

            if((i==0 || j==0 || i==rr-1 || j==cc-1) &&
               !(i==l && j==m)){

                ans=count;
                break;
            }

            for(int k=0 ; k<4 ; k++){

                int ro=r[k]+i;
                int co=c[k]+j;

                if(check(ro , co , rr , cc) &&
                   maze[ro][co]=='.'){

                    int d=count+1;

                    pq.push(make_pair(d , make_pair(ro , co)));

                    maze[ro][co]='+';
                }
            }
        }

        return ans;
    }
};