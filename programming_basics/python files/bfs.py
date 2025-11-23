import pdb

class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

class BTree:

    root = None

    def insertNode(self, root, value):
    
        #bfs traversal
        queue = []
        newNode = TreeNode(value)

        if root is None:
            root = newNode
            return

        queue.append(root)

        while (len(queue)):
            
            temp = queue[0]
            queue.pop(0)

            if temp.left != None:
                queue.append(temp.left)
            else:
                temp.left = newNode
                break
            
            if temp.right != None:
                queue.append(temp.right)
            else:
                temp.right = newNode
                break
        #self.inorderTraversal(self.root)

    def getRootNode(self):
        return self.root  
    
    def dfsTraversal(self, root, visited):
        pass


            
def inorderTraversal( node):
    
    if node is None:
        return
        
    inorderTraversal(node.left)
    print(node.val)
    inorderTraversal(node.right)

if __name__ == '__main__':

    bt = BTree()
    root = TreeNode(5)
    root.left = TreeNode(3)
    root.right = TreeNode(6)
    bt.insertNode(root,4)
    # bt.insertNode(3)
    # bt.insertNode(6)

    #root = bt.getRootNode()
    
    inorderTraversal(root)









    