#include "HashTable.h"
#include <iostream>

int main() {
    Hashtable<int> h;
    h.insert("Mango", 100);
    h.insert("Apple", 120);
    h.insert("Banana", 140);
    h.insert("Orange", 123);
    h.insert("Kiwi", 200);
    h.insert("Papapya", 200);
    h.insert("Litchi", 200);

    h.print();

    auto* results = h.search("Orange");
    if (results) {
        std::cout << "Price of an orange is $" << *results << '\n';
    }
    results = h.search("greg");
    if (results) {
        std::cout << "Something went wrong\n";
    } else {
        std::cout << "Item not found\n";
    }

    h["Pickle"] = 123;
    h["Pickle"] += 10;
    h.print();
    std::cout << "Cost of a pickle is " << h["Pickle"] << '\n';
}
