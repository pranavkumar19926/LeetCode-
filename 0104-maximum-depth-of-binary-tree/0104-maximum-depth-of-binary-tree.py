class Solution:

    def depth(self, a) -> int:

        if a is None:
            return 0

        l = 1 + self.depth(a.left)
        r = 1 + self.depth(a.right)

        return max(l, r)

    def maxDepth(self, root: Optional[TreeNode]) -> int:

        return self.depth(root)