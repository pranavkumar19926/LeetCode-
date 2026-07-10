/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    int count = 0;

    // Counts all paths starting from 'root'
    void ans(TreeNode* root, int target, long long add) {

        if (root == NULL)
            return;

        add += root->val;

        if (add == target)
            count++;

        ans(root->left, target, add);
        ans(root->right, target, add);
    }

    int pathSum(TreeNode* root, int targetSum) {

        if (root == NULL)
            return 0;

        // Start a path from current node
        ans(root, targetSum, 0);

        // Try every node as starting node
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);

        return count;
    }
};