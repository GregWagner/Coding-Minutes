#include <iostream>
#include <queue>

class Node {
    public:
        Node(int data) : data{data} {}
        int data;
        Node* left {};
        Node* right {};
};

// Preorder builld of the tree (root, then left, then righ)
Node* builldtree() {
    int data {};
    std::cout << "Enter data: ";
    std::cin >> data;

    if (data == -1) {
        return nullptr;
    }

    Node* node = new Node(data);
    node->left = builldtree();
    node->right = builldtree();
    return node;
}

Node* buildLevelOrder() {
    int data {};
    std::cout << "Enter data: ";
    std::cin >> data;

    if (data == -1) {
        return nullptr;
    }
    std::queue<Node *> q;
    Node* root = new Node(data);
    q.push(root);

    while (!q.empty()) {
        Node* node = q.front();
        q.pop();

        // read in left
        std::cin >> data;
        if (data != -1) {
            node->left = new Node(data);
            q.push(node->left);
        }

        // read in right
        std::cin >> data;
        if (data != -1) {
            node->right = new Node(data);
            q.push(node->right);
        }
    }
    std::cout << "DONE\n";
    return root;
}

void deleteTree(Node* root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

int height(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + std::max(height(root->left), height(root->right));
}

void printPreorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    std::cout << root->data << '\n';
    printPreorder(root->left);
    printPreorder(root->right);
}

void printInorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    printInorder(root->left);
    std::cout << root->data << '\n';
    printInorder(root->right);
}

void printPostorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    printPostorder(root->left);
    printPostorder(root->right);
    std::cout << root->data << '\n';
}

// Level Order (BFS)
void printLevelOrder(Node* root) {
    std::queue<Node *> q;
    
    q.push(root);
    q.push(nullptr);        // needed to mark end of level

    while (!q.empty()) {
        Node* temp = q.front();
        if (temp == nullptr) {
            std::cout << '\n';
            q.pop();
            // insert a new nullptr to mark next level 
            if (!q.empty()) {
                q.push(nullptr);
            }
        } else {
            q.pop();
            std::cout << temp->data << ' ';
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
                
            }
        }
    }
}

/*
 * Diameter of a binary tree is the larget distance
 * between any two nodes on the tree.
 * O(n^2)
 */
int diameter(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int includesRoot {height(root->left) + height(root->right)};
    int rightHeight {diameter(root->right)};
    int leftHeight {diameter(root->left)};

    return std::max(includesRoot, std::max(rightHeight, leftHeight));
}

// O(n)
// At every node, return height and diameter
std::pair<int, int> diameter1(Node* root) {
    std::pair<int, int> answer {0, 0};
    if (root == nullptr) {
        return answer;
    }

    std::pair<int, int> right {diameter1(root->right)};
    std::pair<int, int> left {diameter1(root->left)};

    answer.first = std::max(left.first, right.first) + 1;

    int d1 = left.first + right.first;
    int d2 = left.second;
    int d3 = right.second;
    answer.second = std::max(d1, std::max(d2, d3));
    return answer;
}

int main() {
#if 0
    Node* root = builldtree();

    std::cout << "Pre-order:\n";
    printPreorder(root);
    std::cout << "In-order:\n";
    printInorder(root);
    std::cout << "Post-order:\n";
    printPostorder(root);
    std::cout << "Level-order:\n";
    printLevelOrder(root);

    deleteTree(root);
#endif
    Node* root = buildLevelOrder();
    printLevelOrder(root);
    std::cout << "Height is " << height(root) << '\n';
    std::cout << "Diameter is " << diameter(root) << '\n';
    std::cout << "Diameter is " << diameter1(root).second << '\n';

    deleteTree(root);
}
