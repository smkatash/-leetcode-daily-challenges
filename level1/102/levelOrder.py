class Solution(object):
    def levelOrder(self, root):
        if not root:
            return []
        queue = [root]
        next_queue = []
        level = []
        final = []
        while queue:
            for root in queue:
                level.append(root.val)
                if root.left:
                    next_queue.append(root.left)
                if root.right:
                    next_queue.append(root.right)
            final.append(level)
            level = []
            queue = next_queue
            next_queue = []
        return final
