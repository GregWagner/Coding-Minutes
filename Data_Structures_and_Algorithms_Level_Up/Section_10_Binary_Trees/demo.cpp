#include <iostream>
#include <queue>
#include <map>

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

/*
 * Given a binary tree, check if it is height balanced.
 * A non-empty binary tree is balanced if
 * 1) Left subtree is balanced
 * 2) Right subtree is balanced
 * 3) The difference between heights of left and right
 *    subtree is not more than 1.
 */
std::pair<int, bool> balancedTreeHeight(Node* root) {
    std::pair<int, bool> answer;
    if (root == nullptr) {
        answer.first = 0;
        answer.second = true;
        return answer;
    }

    auto left = balancedTreeHeight(root->left);
    auto right = balancedTreeHeight(root->right);

    answer.first = std::max(left.first, right.first) + 1;
    answer.second = left.second && right.second &&
        std::abs(left.first - right.first) <= 1;

    return answer;
}

/*
 * Max Subseet Sum
 * Find the largest sum of a subset of nodes in a binary tree
 * such that if a node is included in the sum then its parent
 * and children must not be includeed in the subset sum.
 * include = root->data + left.exclude + right.exclude
 * exclude = max(left.include, left.exclude) +
 *           max(right.include, right.exlcude)
 * first = include
 * seccond = exclude
 */
std::pair<int, int> maxSubset(Node* root) {
    std::pair<int, int> answer {0, 0};
    if (root == nullptr) {
        return answer;
    }

    auto left = maxSubset(root->left);
    auto right = maxSubset(root->right);

    answer.first = root->data + left.second + right.second;
    answer.second = std::max(left.first, left.second) +
        std::max(right.first, right.second);

    return answer;
}

// print all nodes at distance K from the root node
void printAtLevel(Node* root, int level) {
    if (root == nullptr) {
        return;
    }
    if (level == 0) {
        std::cout << root->data << ' ';
        return;
    }

    printAtLevel(root->left, level - 1);
    printAtLevel(root->right, level - 1);
}

/*
 * Nodes at Distance K
 * Given a binary tree and target node T, find all nodes at dstance K
 * from the given node where K is also an integer.
 * Note: need to get nodes k above and below the target node.
 *       need to save the ancensors of the target node
 */
int printNodesAtDistanceK(Node* root, Node* target, int k) {
    if (root == nullptr) {
        return -1;
    }

    // did we reach the target node
    if (root == target) {
        printAtLevel(target, k);
    }

    int distanceLeft = printNodesAtDistanceK(root->left, target, k);
    if (distanceLeft != -1) {
        if (distanceLeft + 1 == k) {
            std::cout << root->data << ' ';
        } else {
        printAtLevel(root->right, k - 2 - distanceLeft);
        }
        return 1 + distanceLeft;
    } 

    int distanceRight = printNodesAtDistanceK(root->right, target, k);
    if (distanceRight != -1) {
        if (distanceRight + 1 == k) {
            std::cout << root->data << ' ';
        } else {
            printAtLevel(root->left, k - 2 - distanceRight);
        }
        return 1 + distanceRight;
    } 
    return -1;
}

/*
 * Vertical Order Print
 * Print the binary tree vertically
 * left - subtract 1
 * right - add 1
 */
// helper function for printVerticalOrder
void traverseTree(Node* root, std::map<int, std::vector<int>> &m, int d=0) {
    if (root == nullptr) {
        return;
    }
    m[d].push_back(root->data);
    traverseTree(root->left, m, d - 1);
    traverseTree(root->right, m, d + 1);
}

void printVerrticalOrder(Node* root) {
    std::map<int, std::vector<int>> m;
    traverseTree(root, m);

    // keys are sorted
    for (auto p : m) {
        for (auto data : p.second) {
            std::cout << data << ' ';
        }
        std::cout << '\n';
    }
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
        // check if current level has ended
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
 * Note: it may or may not include the root.
 * O(n^2)
 */
int diameter(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    // if passing through root: LeftHeight - 1 + RightHeight - 1 + 2
    // or LeftHeight + RightHeight
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

    // height
    answer.first = std::max(left.first, right.first) + 1;

    // diameter
    int d1 = left.first + right.first;
    int d2 = left.second;
    int d3 = right.second;
    answer.second = std::max(d1, std::max(d2, d3));

    return answer;
}

// Replace with descendatn sum
// Given a binary tree, replace every node by the sum of all its
// descendants and leave the leaf nodes intact.
// Use Post order traversal
int replaceWithSum(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    // leaf node
    if (root->left == nullptr && root->right == nullptr) {
        return root->data;
    }

    int leftSum = replaceWithSum(root->left);
    int rightSum = replaceWithSum(root->right);
    int temp = root->data;
    root->data = leftSum + rightSum;

    return root->data + temp;
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

    Node* root = buildLevelOrder();y
    printLevelOrder(root);
    std::cout << "Height is " << height(root) << '\n';
    std::cout << "Diameter is " << diameter(root) << '\n';
    std::cout << "Diameter is " << diameter1(root).second << '\n';
#endif

    Node* root = buildLevelOrder();
    replaceWithSum(root);
    printLevelOrder(root);

    deleteTree(root);
}
