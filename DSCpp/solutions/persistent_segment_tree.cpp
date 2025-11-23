// Persistent Segment Tree implementation
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

Node* build(vector<int>& arr, int l, int r) {
    if (l == r) return new Node(arr[l]);
    int m = (l + r) / 2;
    Node* node = new Node(0);
    node->left = build(arr, l, m);
    node->right = build(arr, m+1, r);
    node->val = node->left->val + node->right->val;
    return node;
}

Node* update(Node* prev, int l, int r, int idx, int value) {
    if (l == r) return new Node(value);
    int m = (l + r) / 2;
    Node* node = new Node(0);
    if (idx <= m) {
        node->left = update(prev->left, l, m, idx, value);
        node->right = prev->right;
    } else {
        node->left = prev->left;
        node->right = update(prev->right, m+1, r, idx, value);
    }
    node->val = node->left->val + node->right->val;
    return node;
}

int query(Node* node, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return 0;
    if (ql <= l && r <= qr) return node->val;
    int m = (l + r) / 2;
    return query(node->left, l, m, ql, qr) + query(node->right, m+1, r, ql, qr);
}

int main() {
    vector<int> arr = {1,2,3,4,5};
    Node* root = build(arr, 0, arr.size()-1);
    Node* version2 = update(root, 0, arr.size()-1, 2, 10);
    cout << query(root, 0, arr.size()-1, 1, 3) << endl;
    cout << query(version2, 0, arr.size()-1, 1, 3) << endl;
    return 0;
}
