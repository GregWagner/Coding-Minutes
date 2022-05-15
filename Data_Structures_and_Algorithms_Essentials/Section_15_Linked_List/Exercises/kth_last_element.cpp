/*
 * Implrmrny a function that returns the Kth last element
 * of the linked list in a single pass. You can assume k
 * will be less than the lenngth of the linked list.
 * Hint: Use 2 pointer
 */

#include <iostream>

class node {
  public:
    int data;
    node *next;

    node(int data) {
        this->data = data;
        next = nullptr;
    }
};

int kthLastElement(node *head, int k) {
    node *firstPtr{head};
    node *secondPtr{head};

    for (int i{}; i < k; ++i) {
        secondPtr = secondPtr->next;
    }

    while (secondPtr) {
        secondPtr = secondPtr->next;
        firstPtr = firstPtr->next;
    }
    return firstPtr->data;
}

int main() {
    node *head = new node(7);
    for (int i{6}; i > 0; --i) {
        node *temp = new node(i);
        temp->next = head;
        head = temp;
    }

    node *temp = head;
    while (temp) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "Null\n";

    std::cout << kthLastElement(head, 3) << '\n';
}
