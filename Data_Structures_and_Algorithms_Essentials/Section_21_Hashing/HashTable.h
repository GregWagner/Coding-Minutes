#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>

template <typename T>
class Node {
public:
    Node(const std::string& key, T value)
        : key { key }
        , value { value }
        , next {} {
    }

    ~Node() {
        delete next;
    }

    std::string key;
    T value;
    Node* next;
};

template <typename T>
class Hashtable {
public:
    Hashtable(int default_size = 7)
        : currentSize {}
        , tableSize { default_size } {
        table = new Node<T>*[tableSize];
        clearTable();
    }

    void insert(const std::string& key, T value) {
        int index { hashFunc(key) };
        Node<T>* n = new Node<T>(key, value);
        // add to the front of the liist
        n->next = table[index];
        table[index] = n;

        ++currentSize;
        float loadFactor = static_cast<float>(currentSize) / tableSize;
        if (loadFactor > 0.7) {
            rehash();
        }
    }

    T* search(const std::string& key) {
        int index { hashFunc(key) };
        Node<T>* temp = table[index];
        while (temp != nullptr) {
            if (temp->key == key) {
                return &temp->value;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    T& operator[](std::string key) {
        T* valueFound = search(key);
        if (valueFound == nullptr) {
            T object;
            insert(key, object);
            valueFound = search(key);
        }
        return *valueFound;
    }

    bool isPresent(std::string key) {
        return search(key) != nullptr;
    }

    void erase(std::string& key) {
    }

    void print() {
        for (int i {}; i < tableSize; ++i) {
            std::cout << "Bucket " << i << " -> ";
            Node<T>* temp = table[i];
            while (temp != nullptr) {
                std::cout << '(' << temp->key << ", " << temp->value << ") ";
                temp = temp->next;
            }
            std::cout << '\n';
        }
    }

private:
    Node<T>** table;
    int currentSize {};
    int tableSize {};

    int hashFunc(std::string key) {
        int index {};
        int power { 1 };
        for (auto ch : key) {
            index = (index + ch * power) % tableSize;
            power = (power * 29) % tableSize;
        }
        return index;
    }

    void clearTable() {
        currentSize = 0;
        for (int i {}; i < tableSize; ++i) {
            table[i] = nullptr;
        }
    }

    void rehash() {
        Node<T>** oldTable = table;
        int oldTableSize = tableSize;

        tableSize = tableSize * 2 + 1;
        table = new Node<T>*[tableSize];
        clearTable();

        // copy elements from old table to new
        for (int i {}; i < oldTableSize; ++i) {
            Node<T>* temp = oldTable[i];
            while (temp != nullptr) {
                insert(temp->key, temp->value);
                temp = temp->next;
            }
            if (oldTable[i] != nullptr) {
                delete oldTable[i];
            }
        }
        delete[] oldTable;
    }
};

#endif
