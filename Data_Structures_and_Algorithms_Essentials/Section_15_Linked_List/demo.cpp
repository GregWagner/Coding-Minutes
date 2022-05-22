#include <iostream>

class List;

class Node {
public:
    Node(int d)
        : data(d)
        , next(nullptr) {
    }

    ~Node() {
        delete next;
    }

    int getData() const {
        return data;
    }

    friend class List;

private:
    int data;
    Node* next;
};

class List {
public:
    List()
        : head(nullptr)
        , tail(nullptr) {
    }

    ~List() {
        Node* currentNode = head;
        while (currentNode != nullptr) {
            head = currentNode->next;
            currentNode->next = nullptr;
            delete currentNode;
            currentNode = head;
        }
        head = tail = nullptr;
    }

    Node* begin() const {
        return head;
    }

    void print() const {
        Node* currentNode = head;
        while (currentNode != nullptr) {
            std::cout << currentNode->getData() << " -> ";
            currentNode = currentNode->next;
        }
        std::cout << "null\n";
    }

    void push_front(int data) {
        Node* node = new Node(data);
        if (head == nullptr) {
            head = tail = node;
        } else {
            node->next = head;
            head = node;
        }
    }

    void pop_front() {
        Node* temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
    }

    void push_back(int data) {
        Node* node = new Node(data);
        if (head == nullptr) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    Node* deleteTail() {
        if (head == nullptr) {
            return nullptr;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return head;
        }
        Node* previousNode {};
        Node* currentNode = head;
        while (currentNode->next) {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
        delete previousNode->next;
        previousNode->next = nullptr;
        tail = previousNode;
        return head;
    }

    void pop_back() {
        Node* previousNode {};
        Node* currentNode = head;
        while (currentNode->next) {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
        delete previousNode->next;
        previousNode->next = nullptr;
    }

    void insert(int data, int position) {
        if (position == 0) {
            push_front(data);
            return;
        }
        Node* currentNode = head;
        for (int index { 1 }; index <= position - 1; ++index) {
            if (currentNode->next == nullptr) {
                std::cerr << "Invald insertation position.\n";
                return;
            }
            currentNode = currentNode->next;
        }
        Node* node = new Node(data);
        node->next = currentNode->next;
        currentNode->next = node;
    }

    void remove(int position) {
        if (head == nullptr) {
            std::cerr << "List is empty\n";
            return;
        }
        Node* currentNode = head;
        int index { 1 };
        while (index < position - 1 && currentNode->next) {
            currentNode = currentNode->next;
            ++index;
        }
        if (currentNode->next == nullptr) {
            std::cerr << "Trying to delete a node not in list\n";
            return;
        }
        Node* tempNode = currentNode->next;
        currentNode->next = tempNode->next;
        delete tempNode;
    }

    bool search(int key) const {
        Node* currentNode = head;
        while (currentNode != nullptr) {
            if (head->getData() == key) {
                return true;
            }
            currentNode = head->next;
        }
        return false;
    }

    bool searchRecursive(Node* currentNode, int key) const {
        if (currentNode == nullptr) {
            return false;
        }
        if (currentNode->getData() == key) {
            return true;
        }
        return searchRecursive(currentNode->next, key);
    }

    int recursiveSearch(int key) {
        return searchHelper(head, key);
    }

    void reverse() {
        Node* currentNode = head;
        Node* previousNode = {};
        while (currentNode != nullptr) {
            Node* nextNode = currentNode->next;
            currentNode->next = previousNode;
            previousNode = currentNode;
            currentNode = nextNode;
        }
        head = previousNode;
    }

private:
    Node* head;
    Node* tail;

    int searchHelper(Node* currentNode, int key) {
        if (currentNode == nullptr) {
            return -1;
        }
        if (currentNode->getData() == key) {
            return 0;
        }
        int index = searchHelper(currentNode->next, key);
        return (index == -1 ? -1 : index + 1);
    }
};

int main() {
    List list;
    ;
    list.push_front(1);
    list.push_front(3);
    list.print();

    list.push_back(4);
    list.print();

    list.insert(5, 2);
    list.insert(6, 2);
    list.print();

    list.pop_front();
    list.print();

    list.deleteTail();
    list.print();
    list.push_back(99);
    list.print();

    list.reverse();
    list.print();

    list.deleteTail();
    list.print();
}
