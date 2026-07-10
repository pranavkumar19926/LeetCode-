class Solution {
public:

    int count = 0;

    void ans(TreeNode* root, int target, long long add,
             unordered_map<long long, int>& mp) {

        if (root == NULL)
            return;

        add += root->val;

        long long val = add - target;

        if (mp.count(val)) {
            count += mp[val];
        }

        mp[add]++;

        ans(root->left, target, add, mp);
        ans(root->right, target, add, mp);

        // Backtrack
        mp[add]--;
    }

    int pathSum(TreeNode* root, int targetSum) {

        unordered_map<long long, int> mp;
        mp[0] ++;

        ans(root, targetSum, 0, mp);

        return count;
    }
};