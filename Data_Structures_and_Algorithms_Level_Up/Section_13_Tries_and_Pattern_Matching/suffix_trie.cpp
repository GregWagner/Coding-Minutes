#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>

class Node {
    public:
        Node(char data) : data {data} {
        }

        friend class SuffixTrie;

    private:
        char data;
        std::unordered_map<char, Node*> map;
        bool isTerminal {};
};

class SuffixTrie {
    public:
        SuffixTrie() {
            root = new Node('\0');
        }

        void insert_helper(const std::string& word) {
            Node* temp = root;
            for (char ch : word) {
                if (temp->map.count(ch) == 0) {
                    Node* node = new Node(ch);
                    temp->map[ch] = node;
                }
                temp = temp->map[ch];
            }
            temp->isTerminal = true;
        }

        void insert(std::string word) {
            // pick all substrings from (i, eos)
            for (int i {}; word[i] != '\0'; ++i) {
                insert_helper(word.substr(i));
            }
        }

        bool search(const std::string& word) {
            Node* temp = root;
            for (char ch : word) {
                if (temp->map.count(ch) == 0){
                    return false;
                }
                temp = temp->map[ch];
            }
            return temp->isTerminal;
        }

    private:
        Node* root;
};

int main() {
    // Simplified Suffix Trie
    std::string input = "hello";
    std::string suffixes[] = {"lo", "ell", "hello"};

    SuffixTrie t;
    t.insert(input);

    for (auto sf : suffixes) {
        std::cout << (t.search(sf) ? "yes" : "no") << '\n';
    }
}
