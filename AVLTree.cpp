#include <bits/stdc++.h>
#include <fstream>
using namespace std;

class Node {
    public:
        int key;
        Node* left;
        Node* right;
        int height;
};

class AVLTree {
    private:
        Node* root;

        int height(Node *N) {
            if (N == NULL)
                return 0;
            return N->height;
        }

        Node* newNode(int key) {
            Node* node = new Node();
            node->key = key;
            node->right = NULL;
            node->left = NULL;
            node->height = 1;
            return node;
        }

        Node* rightRotate(Node* y) {
            Node* x = y->left;
            Node* T2 = x->right;

            // Thuc hien xoay
            x->right = y;
            y->left = T2;

            // Cap nhat chieu cao
            y->height = max(height(y->left), height(y->right)) + 1;
            x->height = max(height(x->right), height(x->left)) + 1;

            return x;
        }

        Node* leftRotate(Node* x) {
            Node* y = x->right;
            Node* T2 = y->left;

            // Thuc hien xoay
            y->left = x;
            x->right = T2;

            // Cap nhat chieu cao
            x->height = max(height(x->left), height(x->right)) + 1;
            y->height = max(height(y->left), height(y->right) + 1);

            return y;
        }

        int getBalance(Node* N) {
            if (N == NULL)
                return 0;
            return height(N->left) - height(N->right);
        }

        Node* insert(Node* node, int key) {
            // 1. Thuc hien chen nhu cay nhi phan
            if (node == NULL)
                return newNode(key);

            if (key < node->key)
                node->left = insert(node->left, key);
            else if (key > node->key)
                node->right = insert(node->right, key);
            else //Khoa da ton tai ten cay
                return node;

            // 2. Cap nhat chieu cao cua nut cha
            node->height = 1 + max(height(node->left), height(node->right));

            // 3. Lay chi so can bang
            int balance = getBalance(node);

            // Co bon truong hop cua cay khong can bang

            // Truong hop Left Left
            if (balance > 1 && key < (node->left)->key)
                return rightRotate(node);

            // Truong hop Right Right
            if (balance < -1 && key > (node->right)->key)
                return leftRotate(node);

            // Truong hop Left Right
            if (balance > 1 && key > (node->left)->key) {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }

            // Truong hop Right Left
            if (balance < -1 && key < node->right->key) {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }

            // Tra ve con tro nut (khong doi)
            return node;
        }

        void inOrder(Node* root) {
            if (root == NULL) {
                inOrder(root->left);
                cout << root -> key << " ";
                inOrder(root->right);
            }
        }
    public:
        AVLTree() { root = NULL; }

        void insert(int key) { root = insert(root, key); }

        void inOrder() { inOrder(root); }

        int getHeight() { return height(root); }
};

int main() {
    AVLTree tree;
    int n;
    int count = 0;

    // Mở file và đọc dữ liệu từ file
    freopen("Data10.txt","r",stdin);

        while (cin >> n) {
            tree.insert(n);
            count++;
        }

    cout << count << ' ' << tree.getHeight();

    return 0;
}
