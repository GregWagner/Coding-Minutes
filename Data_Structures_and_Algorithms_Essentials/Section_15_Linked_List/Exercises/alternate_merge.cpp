/*
 * Given 2 linked lists, insert nodes of the second
 * list into the first list at alternate position
 * of the first list.
 */
#include <iostream>

class node {
public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
        next = NULL;
    }
};

void printList(node* head) {
    node* temp = head;
    while (temp) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "Null\n";
}

node* alternateMerge(node* root1, node* root2) {
    node* answer {};
    if (root1) {
        answer = new node(root1->data);
        root1 = root1->next;
    }
    node* currentNode { answer };
    if (root2) {
        if (answer == nullptr) {
            answer = new node(root2->data);
            root2 = root2->next;
        } else {
            currentNode->next = new node(root2->data);
            root2 = root2->next;
            currentNode = currentNode->next;
        }
    }

    while (root1 || root2) {
        if (root1) {
            currentNode->next = new node(root1->data);
            root1 = root1->next;
            currentNode = currentNode->next;
        }

        if (root2) {
            currentNode->next = new node(root2->data);
            root2 = root2->next;
            currentNode = currentNode->next;
        }
    }
    return answer;
}

int main() {
    int a[] { 5, 7, 17, 13, 11 };
    node* firstHead = new node(5);
    node* currentNode = firstHead;
    for (int i { 1 }; i < 5; ++i) {
        node* temp = new node(a[i]);
        currentNode->next = temp;
        currentNode = temp;
    }
    printList(firstHead);

    int b[] { 12, 10, 2, 4, 6 };
    node* secondHead = new node(12);
    currentNode = secondHead;
    for (int i { 1 }; i < 5; ++i) {
        node* temp = new node(b[i]);
        currentNode->next = temp;
        currentNode = temp;
    }
    printList(secondHead);

    auto answer = alternateMerge(firstHead, secondHead);
    printList(answer);
}
