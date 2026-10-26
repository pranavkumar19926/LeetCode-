class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
                   
                   vector<int> col(matrix[0].size() , -1);

                   for(int i=0 ; i<matrix[0].size() ; i++){


                    for(int j=0 ; j<matrix.size() ; j++){

                        col[i]=max(col[i],matrix[j][i]);


                    }

                   }

                   for(int i=0 ; i<matrix.size() ; i++){
                    for(int j=0 ; j<matrix[0].size() ; j++){

                        if(matrix[i][j]==-1){

                            matrix[i][j]=col[j];
                        }
                    }
                   }

                   return matrix;
    }
};