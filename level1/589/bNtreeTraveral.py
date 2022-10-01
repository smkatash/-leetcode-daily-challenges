class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children

##DepthfirstSearch
class Solution(object):
    def preorder(self, root):
        arr = list()
        def depthfirstS(node):
            if node != None:
                arr.append(node.val)
                for child in node.children:
                    depthfirstS(child)
        depthfirstS(root)
        return arr
    
##BreadthfirstSearch
class Solution(object):
    def preorder(self, root):
        arr = list()
        stack = list()
        if root != None:
            stack.append(root)
        while len(stack) > 0:
            node = stack.pop()
            arr.append(node.val)
            node.children.reverse()
            for child in node.children:
                stack.append(child)
        return arr
    