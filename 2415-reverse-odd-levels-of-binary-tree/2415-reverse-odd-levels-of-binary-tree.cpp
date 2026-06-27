class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {

        if(root == NULL) return root;

        queue<TreeNode*> q;
        q.push(root);

        int level = 0;

        while(!q.empty()){

            int size = q.size();

            vector<TreeNode*> nodes;

            for(int i = 0; i < size; i++){

                TreeNode* temp = q.front();
                q.pop();

                nodes.push_back(temp);

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

            if(level % 2 == 1){

                int i = 0;
                int j = nodes.size() - 1;

                while(i < j){
                    swap(nodes[i]->val, nodes[j]->val);
                    i++;
                    j--;
                }
            }

            level++;
        }

        return root;
    }
};