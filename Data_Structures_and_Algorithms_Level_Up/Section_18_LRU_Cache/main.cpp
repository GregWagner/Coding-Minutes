/*
 * Implement a DS for LRU (least receint used) cache
 * which supports the following operations in O91) time.
 *      insert(key, value)
 *      getValue(key)
 *      getMostRecentKey()
 */
#include <iostream>
#include <list>
#include <unordered_map>

struct Node {
    std::string key;
    int value;

    Node(const std::string &key, int value) : key {key}, value {value} {
    }
};

class LRUCache {
public:
    LRUCache(size_t capacity) {
        maxSize = capacity > 1 ? capacity : 1;
    }
    
    void insertKeyValue(const std::string &key, int value) {
        if (m.count(key) != 0) {
            // replace the old value and update
            auto it = m[key];
            it->value = value;
        } else {
            // check if cache is full or not
            if (l.size() == maxSize) {
                // cache full, remove least recently used item
                Node last = l.back();
                m.erase(last.key);      // remove from hashmap
                l.pop_back();           // remove form linked list
            }
            Node n(key, value);
            l.push_front(n);
            m[key] = l.begin();
        }
    }

    int* getValue(std::string key) {
        if (m.find(key) == m.end()) {
            return nullptr;
        }
        auto it = m[key];

        l.push_front(*it);
        l.erase(it);
        m[key] = l.begin();
        return &l.begin()->value;
    }

    std::string mostRecentKey() {
        return l.front().key;
    }

private:
    size_t maxSize;
    std::list<Node> l;
    std::unordered_map<std::string, std::list<Node>::iterator> m;
};

int main() {
    LRUCache lru(3);
	lru.insertKeyValue("mango", 10);
	lru.insertKeyValue("apple", 20);
	lru.insertKeyValue("guava", 30);
    std::cout << lru.mostRecentKey() << '\n';

	lru.insertKeyValue("mango", 40);
    std::cout << lru.mostRecentKey() << '\n';

	int *orders = lru.getValue("mango");
	if(orders != nullptr){
        std::cout << "Order of Mango " << *orders << '\n';
	}

	lru.insertKeyValue("banana", 20);

	if(lru.getValue("apple") == nullptr){
        std::cout << "apple doesn't exist" << '\n';
	}

	if(lru.getValue("guava")==nullptr){
        std::cout << "guava doesn't exist" << '\n';
	}

	if(lru.getValue("banana")==nullptr){
        std::cout << "banana doesn't exist" << '\n';
	}
	if(lru.getValue("mango")==nullptr){
        std::cout << "mango doesn't exist" << '\n';
	}
}
