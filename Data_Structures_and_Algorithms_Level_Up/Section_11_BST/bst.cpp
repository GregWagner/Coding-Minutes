#include <iostream>
#include <vector>
#include <climits>

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

/*
 * Minmum Height BST
 * Given a sorted array, construct a BST of minimum height.
 */
Node* sortedArrayToBST(std::vector<int> a, int start, int end) {
    if (start > end) {
        return nullptr;
    }
    int mid = (start + end) / 2;
    Node* root = new Node(a[mid]);

    root->left = sortedArrayToBST(a, start, mid - 1);
    root->right = sortedArrayToBST(a, mid + 1, end);

    return root;
}

/*
 * Closest in BST
 * Find the integer closest to a given target value in a BST.
 */
int findClosestInBSt(Node* root, int target) {
    int closest {};
    int difference {INT_MAX};

    Node* temp = root;
    while (temp != nullptr) {
        int currentDiff = std::abs(temp->value - target);
        if (currentDiff == 0) {
            return temp->value;
        }

        if (currentDiff < difference) {
            difference = currentDiff;
            closest = temp->value;
        }

        temp = (temp->value < target ? temp->right : temp->left);
    }
    return closest;
}

/*
 * Flatten the tree
 * Convert a BST to a sorted linked list. Right pointer
 * should behave as the next pointer for the linked list.
 * Need Post order tarversal.
 * 4 cases:
 * 1) Left and right subtrees exists
 * 2) Left and right subtrees do not exist
 * 2) Left subtree does not exist
 * 4) Right subtree does not exist
 */
struct LinkedList {
    Node* head;
    Node* tail;
};

LinkedList tree2LinkedList(Node* root) {
    LinkedList l {nullptr, nullptr};
    if (root == nullptr) {
        return l;
    }

    // Case #1
    if (root->left == nullptr && root->right == nullptr) {
        l.head = root;
        l.tail = root;
        return l;
    }

    // Case #2
    if (root->left != nullptr && root->right == nullptr) {
        LinkedList left = tree2LinkedList(root->left); 
        left.tail->right = root;

        l.head = left.head;
        l.tail = root;
        return l;
    }

    // Case #3
    if (root->left == nullptr && root->right != nullptr) {
        LinkedList right = tree2LinkedList(root->right); 
        root->right = right.head;

        l.head = root;
        l.tail = right.tail;
        return l;
    }
    LinkedList left = tree2LinkedList(root->left); 
    left.tail->right = root;

    LinkedList right = tree2LinkedList(root->right); 
    root->right = right.head;

    l.head = left.head;
    l.tail = right.tail;

    return l;
}

/*
 * Inorder Successor
 * Given a BST, find the inorder successor of a given node
 * without doing inoder traversal.
 * Do root to target leaf traverasal and store successor (larger
 * than target).
 */
Node* inOrderSuccessor(Node* root, Node* target) {
    // If right subtree of target exists.
    if (target->right != nullptr) {
        Node* temp = target->right;
        while (temp->left != nullptr) {
            temp = temp->left;
        }
        return temp;
    }


    Node* temp = root;
    Node* successor = nullptr;

    while (temp != nullptr) {
        if (temp->value > target->value) {
            successor = temp;
            temp = temp->left;
        } else if (temp->value < target->value) {
            temp = temp->right;
        } else {
            break;
        }
    }
    return successor;
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
