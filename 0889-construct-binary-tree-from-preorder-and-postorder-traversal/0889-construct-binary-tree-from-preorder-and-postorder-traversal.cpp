class Solution {
public:

    unordered_map<int, int> mp;

    TreeNode* construct(vector<int>& preorder,
                        vector<int>& postorder,
                        int &preIndex,
                        int left,
                        int right) {

        if (preIndex >= preorder.size() || left > right)
            return NULL;

        TreeNode* head = new TreeNode(preorder[preIndex]);

        // Leaf node
        if (left == right) {
            preIndex++;
            return head;
        }

        preIndex++;

        // Position of left child in postorder
        int pos = mp[preorder[preIndex]];

        head->left = construct(preorder, postorder, preIndex, left, pos);

        head->right = construct(preorder, postorder, preIndex, pos + 1, right - 1);

        return head;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {

        for (int i = 0; i < postorder.size(); i++) {
            mp[postorder[i]] = i;
        }

        int preIndex = 0;

        return construct(preorder, postorder, preIndex, 0,
                         postorder.size() - 1);
    }
};