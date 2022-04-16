/*
 * Given an array, find the maximum XOR that you can form
 * by picking 2 numbers from the array. Must solve in O(n)
 */
#include <iostream>
#include <vector>

struct Node {
    Node* left;
    Node* right;
};

class Trie {
    public:
        Trie() {
            root = new Node();
        }

        void insert(int n) {
            Node* temp = root;

            for (int i {31}; i >= 0; --i) {
                int bit = (n>>i) & 1;
                if (bit == 0) {
                    if (temp->left == nullptr) {
                        temp->left = new Node();
                    }
                    temp = temp->left;
                } else {
                    if (temp->right == nullptr) {
                        temp->right = new Node();
                    }
                    temp = temp->right;
                }
            }
        }

        int maxXorHelper(int value) {
            int currentAnswer {};
            Node* temp = root;

            for (int i {31}; i >= 0; --i) {
                int bit = (value>>i) & 1;
                if (bit == 0) {
                    // try to find the opposite value
                    if (temp->right != nullptr) {
                        temp = temp->right; 
                        currentAnswer += (1<<i);
                    } else {
                        temp = temp->left;
                    }
                } else {
                    if (temp->left != nullptr) {
                        temp = temp->left;
                        currentAnswer += (1<<i);
                    } else {
                        temp = temp->right;
                    }
                }
            }
            return currentAnswer;
        }

        int maxXor(const std::vector<int> &input) {
            int max_xor {};
            for (auto value : input) {
                insert(value);
                int current_xor = maxXorHelper(value);
                max_xor = std::max(max_xor, current_xor);
            }
            return max_xor;
        }

    private:
        Node* root;
};

int main() {
    std::vector<int> input {3, 10, 5, 8, 2, 25};

    Trie t;
    std::cout << std::boolalpha;
    std::cout << (t.maxXor(input) == 28) << '\n';
}
