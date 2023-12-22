#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value = 0) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
  private:
    Node* root;

    Node* insertion(Node* current, int value) {
        if (current == nullptr) return new Node(value);

        if (value < current->data) {
            current->left = insertion(current->left, value);
        } else if (value > current->data) {
            current->right = insertion(current->right, value);
        }

        return current;
    }

    Node* minValueNode(Node* current) {
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    Node* deletion(Node* current, int value) {
        if (current == nullptr) return current;

        if (value < current->data) {
            current->left = deletion(current->left, value);
        } else if (value > current->data) {
            current->right = deletion(current->right, value);
        } else {
            if (current->left == nullptr) {
                Node* temp = current->right;
                delete current;
                return temp;
            } else if (current->right == nullptr) {
                Node* temp = current->left;
                delete current;
                return temp;
            }

            Node* temp = minValueNode(current->right);
            current->data = temp->data;
            current->right = deletion(current->right, temp->data);
        }

        return current;
    }

    bool searching(Node* current, int value) {
        if (current == nullptr) return false;

        if (value < current->data) {
            return searching(current->left, value);
        } else if (value > current->data) {
            return searching(current->right, value);
        } else {
            return true;
        }
    }

    void inorderTraverse(Node* current) {
        if (current == nullptr) return;

        inorderTraverse(current->left);
        cout << current->data << " ";
        inorderTraverse(current->right);
    }

    void preorderTraverse(Node* current) {
        if (current == nullptr) return;

        cout << current->data << " ";
        preorderTraverse(current->left);
        preorderTraverse(current->right);
    }

    void postorderTraverse(Node* current) {
        if (current == nullptr) return;

        postorderTraverse(current->left);
        postorderTraverse(current->right);
        cout << current->data << " ";
    }

  public:
    BST() {
        root = nullptr;
    }

    void insertion(int value) {
        root = insertion(root, value);
    }

    void deletion(int value) {
        root = deletion(root, value);
    }

    void searching(int value) {
        if (searching(root, value)) {
            cout << value << " is found." << endl;
        } else {
            cout << value << " is not found." << endl;
        }
    }

    void inorderTraverse() {
        inorderTraverse(root);
        cout << endl;
    }

    void preorderTraverse() {
        preorderTraverse(root);
        cout << endl;
    }

    void postorderTraverse() {
        postorderTraverse(root);
        cout << endl;
    }
};

int main(int, char**) {
    BST bst;

    bst.insertion(14);
    bst.insertion(8);
    bst.insertion(3);
    bst.insertion(7);
    bst.insertion(2);
    bst.insertion(22);
    bst.insertion(15);
    bst.insertion(10);
    bst.insertion(19);

    bst.inorderTraverse();

    bst.deletion(15);
    bst.deletion(2);

    bst.inorderTraverse();

    bst.searching(15);

    return 0;
}
