#include <iostream>

class node {
  public:
    int data;
    node *next;
    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void printList(node *head) {
    node *temp = head;
    while (temp) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "Null\n";
}

node *bubble_sort_LinkedList_itr(node *head) {
    bool swapMade = true;
    node *currentNode = head;
    while (swapMade) {
        swapMade = false;
        currentNode = head;

        while (currentNode->next) {
            if (currentNode->data > currentNode->next->data) {
                swapMade = true;
                int temp = currentNode->data;
                currentNode->data = currentNode->next->data;
                currentNode->next->data = temp;
            }
            currentNode = currentNode->next;
        }
    }
    return head;
}

int main() {
    int a[]{30, 20, 5};
    node *head = new node(10);
    node *currentNode = head;
    for (int i{}; i < 3; ++i) {
        node *temp = new node(a[i]);
        currentNode->next = temp;
        currentNode = temp;
    }

    auto answer = bubble_sort_LinkedList_itr(head);
    printList(answer);
}
