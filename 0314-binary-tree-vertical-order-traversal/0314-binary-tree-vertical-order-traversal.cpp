/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void ans(TreeNode* roots , int &u , int &v , int i){
           
           if(roots==NULL){

            return ;
           }

          
          u=min(u , i);

          v=max(v , i);


          ans(roots->left , u , v , i-1);

          ans(roots->right , u , v , i+1 );


    }




    vector<vector<int>> verticalOrder(TreeNode* root) {
                  if(root==NULL){

                    vector<vector<int>> a;

                    return a;
                  } 
                  int u=0;
                  int v=0;


                 ans(root , u , v ,0 ) ;

                  int s=-1*u + v + 1 ;
                 vector<vector<int>> vec(s);

                   queue<pair<TreeNode*,int>> q;

                 q.push(make_pair(root , -1*u ) );


                 while(!q.empty()){


                   TreeNode* node=q.front().first;

                   int indi=q.front().second;

                   vec[indi].push_back(node->val);


                   q.pop();

                   if(node->left){

                    q.push(make_pair(node->left , indi-1));
                   }

                   if(node->right){

                    q.push(make_pair(node->right , indi+1 ));

                    }
                       

                 }



                 return vec;


      



    }
};