#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>

class Node {
    public:
        Node(char data) : data {data} {
        }

        char data;
        std::unordered_map<char, Node*> children;
        bool isTerminal {};
};

class Trie {
    public:
        Trie() {
            root = new Node('\0');
        }

        void insert(const std::string& word) {
            Node* temp = root;
            for (char ch : word) {
                if (temp->children.count(ch) == 0) {
                    Node* node = new Node(ch);
                    temp->children[ch] = node;
                }
                temp = temp->children[ch];
            }
            temp->isTerminal = true;
        }

        Node* root;
};

void searchHelper(Trie &t, const std::string& document,
        size_t i, std::unordered_map<std::string, bool> &m) {

    Node* temp = t.root;
    for (size_t j {i}; j < document.size(); ++j) {
        char ch = document[j];
        if (temp->children.count(ch) == 0) {
            return;
        }
        temp = temp->children[ch];
        if (temp->isTerminal) {
            // history part
            std::string out = document.substr(i, j - i + 1);
            m[out] = true;
        }
    }
}

void documentSearch(const std::string& document,
        const std::vector<std::string> words) {
    // create a trie ot words
    Trie t;
    for (auto word : words) {
        t.insert(word);
    }

    // searching
    std::unordered_map<std::string, bool> m;
    for (size_t i {}; i < document.size(); ++i) {
        searchHelper(t, document, i, m);
    }

    // check which words are marked as true in hashmap
    for (auto word : words) {
        std::cout << word << " : " << (m[word] ? "True" : "False") << '\n';
    }
}

int main() {
    std::string document = "litttle cute cat loves to code in c++, java & python";
    std::vector<std::string> words= {"cute cat", "ttle", "cat", "quick", "big"};
    
    documentSearch(document, words);
}
