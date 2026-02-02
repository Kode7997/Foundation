class Tree:

    def __init__(self,data):
        self.val = data
        self.left = None
        self.right = None

class BST:

    def __init__(self):
        self.head = None
    
    def insert_node(self, val):

        if self.head == None:
            root = Tree(val)
            self.head = root
            return self.head
        else:
            print("insert to root: ",self.head)
            root = self.head
            while root != None:
                if root.val < val:
                    right = True
                    prev = root
                    root = root.right
                elif root.val >= val:
                    right = False
                    prev = root
                    root = root.left

            if right:
                prev.right = Tree(val)
            else:
                prev.left = Tree(val)
        
        return
    
    def display_inorder_tree(self, root):
        
        if root == None:
            return None
        
        self.display_inorder_tree(root.left)
        print(root.val)
        self.display_inorder_tree(root.right)
    
    def __str__(self):
        return self.head



if __name__ == '__main__':

    bst = BST()
    bst.insert_node(10)
    bst.insert_node(3)
    bst.insert_node(12)
    bst.insert_node(4)
    bst.insert_node(1)
    bst.insert_node(11)
    bst.insert_node(13)

    print("root of the tree: ",bst.__str__().left)
    bst.display_inorder_tree(root=bst.__str__())
        

            
