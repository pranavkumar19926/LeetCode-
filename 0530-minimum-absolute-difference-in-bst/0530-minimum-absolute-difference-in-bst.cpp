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


     void inorder(TreeNode* roots ,vector<int> &ans ){

           if(roots==NULL){

            return ;
           }

         inorder(roots->left , ans );

         ans.push_back(roots->val);

         inorder(roots->right , ans);
     }






    int getMinimumDifference(TreeNode* root) {
         
         vector<int> ans;

         inorder(root , ans );


         int minn=INT_MAX;

         for(int i=1 ; i<ans.size() ; i++){

               int a=ans[i];
               int b=ans[i-1];

               int diff=abs(a-b);

               if(diff < minn){

                  minn=diff;
               }


         }


         return minn;


    }
};