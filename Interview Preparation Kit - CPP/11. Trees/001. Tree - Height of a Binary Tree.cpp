// Problem: https://www.hackerrank.com/challenges/tree-height-of-a-binary-tree/problem
// Score: 10


int height(Node *root) {
    if ((root == nullptr) || (root->left == nullptr && root->right == nullptr)) {
        return 0;
    } else {
        return max(height(root->left), height(root->right)) + 1;
    }
}
