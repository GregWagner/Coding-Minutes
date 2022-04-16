/*
 * Given a list of words and an mxn board where every cell has one
 * character. Find all possible words that are part of the list and
 * can be formed by a sequence of adjacent characters from the board.
 * Note that we can move to any of 8 adjacent characters, but a word
 * should not have multiple instances of the same cell.
 *
 * 1) Create a trie of the words you are looking at
 *
 * Hint 1 - 8-way DFS search from every cell
 * Hint 2 - Trie willl guide and control the search.
 */
#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <climits>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define M 3
#define N 4

class Node {
    public:
        Node(char data) : data {data} {
        }

        char data;
        std::unordered_map<char, Node*> children;
        std::string word = "";
        bool isTerminal {};
};

class Trie {
    public:
        Node* root;

        Trie() {
            root = new Node('\0');
        }

        void addWord(const std::string& word) {
            Node* temp = root;
            for (char ch : word) {
                if (temp->children.count(ch) == 0) {
                    temp->children[ch] = new Node(ch);
                }
                temp = temp->children[ch];
            }
            temp->isTerminal = true;
            temp->word = word;
        }
#if 0
        bool search(const std::string& word) {
            Node* temp = root;
            for (char ch : word) {
                if (temp->children.count(ch) == 0){
                    return false;
                }
                temp = temp->children[ch];
            }
            return temp->isTerminal;
        }
#endif
};

void dfs(char board[M][N], Node* node, int i, int j, bool visited[M][N],
        std::unordered_set<std::string> &output) {
    char ch {board[i][j]};
    if (node->children.count(ch) == 0) {
        return;
    }

    // otherwise trie contains this node
    visited[i][j] = true;
    node = node->children[ch];

    if (node->isTerminal) {
        output.insert(node->word);
    }

    // explore the neighbors
    int dx[] {0, 1, 1, 1, 0, -1, -1, -1};
    int dy[] {-1, -1, 0, 1, 1, 1, 0, -1};

    for (int k {}; k < 8; ++k) {
        int new_i = i + dx[k];
        int new_j = j + dy[k];

        // check if in bounds and not visisted
        if (new_i >= 0 && new_i < M && new_j >= 0 && new_j < N
                && !visited[new_i][new_j]) {
            dfs(board, node, new_i, new_j, visited, output);
        }
    }
    // backtrack
    visited[i][j] = false;
}

int main() {

    std::vector<std::string> words {"SNAKE", "FOR", "QUEZ", "SNACK",
        "SNACKS", "GO", "TUNES", "CAT"};
    Trie tree;

    for (const auto& word : words) {
        tree.addWord(word);
    }

    char board[M][N] {
        {'S', 'E', 'R', 'T'},
        {'U', 'N', 'K', 'S'},
        {'T', 'C', 'A', 'T'}};

    // container to store words that are found in dfs search
    std::unordered_set<std::string> output;
    bool visited[M][N] {};

    // 8-way DFS search from every ell
    for (int i {}; i < M; ++i) {
        for (int j {}; j < N; ++j) {
            dfs(board, tree.root, i, j, visited, output);

            // reset visited array after every search (while backtracking)
        }
    }
    // print the output
    for (auto word : output) {
        std::cout << word << '\n'; 
    }
}
