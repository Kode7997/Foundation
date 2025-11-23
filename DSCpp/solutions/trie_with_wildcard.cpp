// Trie with wildcard search
#include <iostream>
#include <vector>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEnd;
    TrieNode() : isEnd(false) { fill(begin(children), end(children), nullptr); }
};

void insert(TrieNode* root, const string& word) {
    TrieNode* node = root;
    for (char c : word) {
        int idx = c - 'a';
        if (!node->children[idx]) node->children[idx] = new TrieNode();
        node = node->children[idx];
    }
    node->isEnd = true;
}

bool search(TrieNode* node, const string& word, int pos) {
    if (!node) return false;
    if (pos == word.size()) return node->isEnd;
    if (word[pos] == '?') {
        for (int i = 0; i < 26; ++i)
            if (search(node->children[i], word, pos+1)) return true;
        return false;
    } else {
        int idx = word[pos] - 'a';
        return search(node->children[idx], word, pos+1);
    }
}

int main() {
    TrieNode* root = new TrieNode();
    insert(root, "cat");
    insert(root, "car");
    insert(root, "dog");
    cout << search(root, "c?t", 0) << endl;
    cout << search(root, "d?g", 0) << endl;
    cout << search(root, "ca?", 0) << endl;
    return 0;
}
