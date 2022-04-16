#include <iostream>
#include <vector>

class Node {
    public:
        int value;
        Node* left;
        Node* right;

        Node(int value) : value {value}, left {}, right {} {
        }
};

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root; 
}

// InOrder traversal will print tree in order
void printInOrder(Node* root) {
    if (root == nullptr) {
        return;        
    }
    printInOrder(root->left);
    std::cout << root->value << ' ';
    printInOrder(root->right);
}

bool search(Node* root, int key) {
    if (root == nullptr) {
        return false;
    }
    if (root->value == key) {
        return true;
    }
    if (root->value < key) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

Node* findSmallestNode(Node* root) {
    while (root->left) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr) {
        return nullptr;
    }
    if (key < root->value) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->value) {
        root->right = deleteNode(root->right, key);
    } else {
        // current node matchs the key
        // Case 1: No Children
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;

        // Case 2: Single Child
        } else if (root->left == nullptr) {
            Node* temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == nullptr) {
            Node* temp = root;
            root = root->left;
            delete temp;

        // Case 3: Two Children
        } else {
            // find smallest node in the right subtree
            Node* temp = findSmallestNode(root->right);
            root->value = temp->value;
            root->right = deleteNode(root->right, temp->value);
        }
    }
    return root;
}

void printRange(Node* root, int start, int end) {
    if (root == nullptr) {
        return;
    }
    if (root->value >= start && root->value <= end) {
        // need to call on both sides
        printRange(root->left, start, end);
        std::cout << root->value << ' ';
        printRange(root->right, start, end);
    } else if (root->value > end) {
        printRange(root->left, start, end);
    } else if (root->value < start){
        printRange(root->right, start, end);
    }
}

void deleteTree(Node* root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

void printRootToLeaf(Node* root, std::vector<int>& path) {
    if (root == nullptr) {
        return;
    }
    if (root->left == nullptr && root->right == nullptr) {
        // leaf node - print path
        for (const auto& ele : path) {
            std::cout << ele << " -> ";
        }
        std::cout << root->value << "\n";
    }
    path.push_back(root->value);
    printRootToLeaf(root->left, path);
    printRootToLeaf(root->right, path);

    // backtrack
    path.pop_back();
}

int main() {
    Node* root = nullptr;
    int a[] {8, 3, 10, 1, 6, 14, 4, 7, 13};
    for (int x : a) {
        root = insert(root, x);
    }
    printInOrder(root);
    std::cout << '\n';
    std::cout << std::boolalpha;
    std::cout << "Key 8? " << search(root, 8) << '\n';
    std::cout << "Key 22? " << search(root, 22) << '\n';
#if 0
    std::cout << "Removing 1: ";
    deleteNode(root, 1);
    printInOrder(root);
    std::cout << '\n';

    std::cout << "Removing 14: ";
    deleteNode(root, 14);
    printInOrder(root);
    std::cout << '\n';

    std::cout << "Removing 8: ";
    deleteNode(root, 8);
    printInOrder(root);
    std::cout << '\n';
#endif
    printRange(root, 5, 12);
    std::cout << '\n';

    std::cout << "--------------------------\n";
    std::vector<int> path;
    printRootToLeaf(root, path);

    deleteTree(root);
}
