#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node* parent;

        bool color;
        // Red is 1, Black is 0

        Node(int data) : data(data), left(NULL), right(NULL), parent(NULL), color(1) {}
};

class BRTree {
    private:
        Node* root;

        bool leftLeft;
        bool rightRight;
        bool rightLeft;
        bool leftRight;

        Node* rightRotate(Node* root) {
            Node* x = root->left;

            // Gan x->right vao root->left
            root->left = x->right;

            if (x->right != NULL)
                (x->right)->parent = root;

            // Gan root vao x->right
            x->right = root;

            root->parent = x;

            // Tra ve x
            return x;
        }

        Node* leftRotate(Node* root) {
            Node* y = root->right;

            // Gan y->left vao root->right
            root->right = y->left;

            if (y->left != NULL)
                (y->left)->parent = root;

            // Gan root vao y->left
            y->left = root;

            root->parent = y;

            // Tra ve y
            return y;
        }

        Node* insertHelp(Node* root, int data) {
            bool f = false;
            // f dung khi co xung dot RED-RED

            if (root == NULL) {
                return new Node(data);
            }

            else if (data < root->data) {
                root->left = insertHelp(root->left, data);
                (root->left)->parent = root;

                if (this->root != root) {
                    if (root->color == 1 && (root->left)->color == 1) f = true;
                }
            }

            else {
                root->right = insertHelp(root->right, data);
                (root->right)->parent = root;

                if (this->root != root) {
                    if (root->color == 1 && (root->right)->color == 1) f = true;
                }
            }

            if (leftLeft) {
                root = rightRotate(root);
                root->color = 0;
                (root->right)->color = 1;
                leftLeft = false;
            }

            else if (rightRight) {
                root = leftRotate(root);
                root->color = 0;
                (root->left)->color = 1;
                rightRight = false;
            }

            else if (leftRight) {
                root->left = leftRotate(root->left);
                (root->left)->parent = root;

                root = rightRotate(root);
                root->color = 0;
                (root->right)->color = 1;
                leftRight = false;
            }

            else if (rightLeft) {
                root->right = rightRotate(root->right);
                (root->right)->parent = root;

                root = leftRotate(root);
                root->color = 0;
                (root->left)->color = 1;
                rightLeft = false;
            }
            // Xu ly xung dot Red-Red
            if (f) {
                if ((root->parent)->right == root) {
                    // Neu Cha do - Chu den (right-right hoac right-left)
                    if ((root->parent)->left == NULL || ((root->parent)->left)->color == 0) {
                        if (root->left != NULL && root->left->color == 1)
                            rightLeft = true;
                        if (root->right != NULL && root->right->color == 1)
                            rightRight = true;
                    }

                    // Neu Cha do - Chu do
                    else {
                        root->color = root->parent->left->color = 0;
                        if (root != this->root)
                            root->parent->color = 1;
                    }
                }

                else {
                    // Neu Cha do - Chu den (left-left hoac left-right)
                    if (root->parent->right == NULL || root->parent->right->color == 0) {
                        if (root->left != NULL && root->left->color == 1)
                            leftLeft = true;
                        if (root->right != NULL && root->right->color == 1)
                            leftRight = true;
                    }

                    // Neu Cha do - Chu do
                    else {
                        root->color = root->parent->right->color = 0;
                        if (root != this->root)
                            root->parent->color = 1;
                    }
                }
                f = false;
            }
            return root;
        }

        int height(Node* node) {
                if (node == NULL) return 0;
                int leftHeight = height(node->left);
                int rightHeight = height(node->right);
                return max(leftHeight, rightHeight) + 1;
            }

    public:
        BRTree() : root(NULL), leftLeft(false), rightRight(false), rightLeft(false), leftRight(false) {}

        void insert(int data) {
            if (root == NULL) {
                root = new Node(data);
                root->color = 0;
            }

            else {
                root = insertHelp(root, data);
                if (root->color == 1) root->color = 0;
            }
        }

        void inOrder(Node* root) {
            if (root == NULL) return;
            inOrder(root->left);
            cout << root->data << " ";
            inOrder(root->right);
        }

        Node* getRoot() { return root; }

        int getHeight() { return height(root); }
};

int main() {
    BRTree tree;
    int n;
    int count = 0;

    freopen("Data5.txt","r",stdin);

        while (cin >> n) {
            tree.insert(n);
            count++;
        }

    cout << count << ' ' << tree.getHeight();

    return 0;
}
