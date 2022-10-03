class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def dfs(self, root, min, max):
        if root == None:
            return True
        if root.val > min and root.val < max:
            return self.dfs(root, min, root.val) and self.dfs(root, root.val, max)
        return False
    def isValidBST(self, root):
        if root == None:
            return True
        if root and root.left == None and root.right == None:
            return True
        return self.dfs(root,-1e12, 1e12)
        
            