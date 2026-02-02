

import pdb

class Node:

    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

class BSTree:
    
    root = None
    
    def __init__(self):
        self.root = None
    
    def insert_iter(self, val):

        if self.root is None:
            self.root = Node(val)
        else:
            current = self.root

            while current:
                parent = current
                if val < current.val:
                    current = current.left
                else:
                    current = current.right

            if val < parent.val:
                parent.left = Node(val)
            else:
                parent.right = Node(val)
        
        return self.root
    
    #recursive
    def insert(self, root, key):

        if self.root == None:
            self.root = Node(key)
            return self.root
        elif root == None:
            return Node(key)

        
        if key < root.val:
            root.left = self.insert(root.left, key)
        elif key > root.val:
            root.right = self.insert(root.right, key)
        
        return root

    def helper_inorder_display(self):
        if self.root is None:
            return
        print("tree: \n")
        self.preorder(self.root)
        

    def preorder(self, root):
        if root:
            #pdb.set_trace()
            print(root.val)
            self.preorder(root.left)
            self.preorder(root.right)

    # stack
    def is_valid(self, root):

        min_val = float('-inf')
        max_val = float('inf')

        #inorder
        q = []
        current = root
        while current or q:
            while current:
                q.append(current)
                current = current.left
            
            current = q.pop()
            if current.val <= min_val:
                return False

            min_val = current.val
            current = current.right

        return True
    
    def depth_helper(self, root, depth):

        if root is None:
            return 0
        
        left = self.depth_helper(root.left, depth+1)
        right = self.depth_helper(root.right, depth+1)

        return 1 + max(left, right)
    
    #recursive
    def depth_of_tree(self, root):

        if root is None:
            return 

        depth = self.depth_helper(root, 0)
        print("depth: ",depth)
    
    #iteration

        


       


if __name__ == '__main__':

    bst = BSTree()
    root = None
    root = bst.insert(root, 4)
    bst.helper_inorder_display()
    #pdb.set_trace()
    bst.insert(root, 2)
    bst.helper_inorder_display()
    bst.insert(root, 3)
    bst.helper_inorder_display()
    bst.insert(root, 5)
    bst.helper_inorder_display()
    bst.insert(root, 6)
    bst.helper_inorder_display()
    print(bst.is_valid(root))
    print("binary tree")
    bst.depth_of_tree(root)

































