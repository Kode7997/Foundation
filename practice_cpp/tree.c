#include<stdio.h>
#include<stdlib.h>

/*
bst is ordered set of elements
1. struct of tree bst
2. insert bst
3. delete bst
*/


struct bst{
    int val;
    struct bst *left;
    struct bst *right;
};


struct bst* create_node(int val){

    struct bst* root = (struct bst*)malloc(sizeof(struct bst));
    root->val = val;
    root->left = NULL;
    root->right = NULL;

    return root;
}


void insert(struct bst* root, int val){

    if (root != NULL) {
        if(root->val >= val){
            if(root->left != NULL){
                insert(root->left, val);
            }else{
                root->left = create_node(val);
                return;
            }
        }else{
            if(root->right != NULL){
                insert(root->right, val);
            }else{
                root->right = create_node(val);
                return;
            }
        }
    }
}

static struct bst* find_min(struct bst* node) {
    struct bst* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct bst* delete_node(struct bst* root, int val){
    // root is null
    // check the node is present
    // if left and right are none .. then free the node
    // if left is none and right is not none, then attach right
    // if right is none and left is not none, then attach the left
    // if left and right not none, then find the min val of right sub tree

    if (root == NULL) {
        return root;
    }

    if (val < root->val) {
        root->left = delete_node(root->left, val);
    } else if (val > root->val) {
        root->right = delete_node(root->right, val);
    } else {
        // Node to be deleted is found
        if (root->left == NULL) {
            struct bst* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct bst* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        struct bst* temp = find_min(root->right);
        root->val = temp->val;
        root->right = delete_node(root->right, temp->val);
    }
    return root;
}

void inorder(struct bst* root){
    if (root == NULL) return;

    
    printf("%d ",root->val);
    inorder(root->left);
    inorder(root->right);

}


int main(){

    // create bst
    struct bst* root = create_node(10);

    // insert
    insert(root, 11);
    insert(root, 6);
    insert(root, 16);
    insert(root, 14);
    insert(root, 15);
    insert(root, 7);
    insert(root, 5);
    insert(root, 4);
    
    inorder(root);
    printf("\n");
    delete_node(root,10);
    inorder(root);

    // delete of node - 3/4 cases - root, leaf/child node, parent node
    
    return 0;
}