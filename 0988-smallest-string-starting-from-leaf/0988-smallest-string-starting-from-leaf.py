# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def smallestFromLeaf(self, root: Optional[TreeNode]) -> str:
        def helper(root, cur):
            if not root:
                return
            cur = chr(ord('a')+root.val) + cur
            if root.left and root.right:
                return min(helper(root.left,cur),helper(root.right,cur))
            if root.left:
                return helper(root.left,cur)
            if root.right:
                return helper(root.right,cur)
            return cur
        return helper(root,"")