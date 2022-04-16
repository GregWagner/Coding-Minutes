#include <iostream>

struct Node {
        int data;
        Node* next;

        Node(int data) : data {data}, next {} {}
};

void insertAtHead(Node* &head, int data) {
    if (!head) {
        head = new Node(data);
        return;
    }
    Node* n = new Node(data);
    n->next = head;
    head = n;

}

void insertInMiddle(Node* &head, int data, int position) {
    if (position == 0) {
        insertAtHead(head, data);
    } else {
        Node* temp = head;
        for (int jump {1}; jump <= position - 1; ++jump) {
            temp = temp->next;
        }
        Node* node = new Node(data);
        node->next = temp->next;
        temp->next = node;
    }
}

Node* reverseRecursive(Node* &head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    Node* newHead = reverseRecursive(head->next);

    head->next->next = head;
    head->next = nullptr;

    return newHead;
}

Node* reverseIterative(Node* head) {
    Node* previous {};
    Node* current {head};
    while (current != nullptr) {
        Node* temp = current->next;
        current->next = previous;

        previous = current;
        current = temp;
    }
    return previous;
}

// Reverse every k nodes
Node* kReverse(Node* head, int k) {
    if (head == nullptr) {
        return nullptr;
    }
    Node* previous {};
    Node* current {head};
    Node* temp;
    int count {1};
    while (current != nullptr && count <= k) {
        temp = current->next;
        current->next = previous;

        previous = current;
        current = temp;
        ++count;;
    }

    if (temp != nullptr) {
        head->next = kReverse(temp, k);
    }
    return previous;
}

void print(Node* head) {
    while (head) {
        std::cout << head->data << ' ';
        head = head->next;
    }
    std::cout << '\n';
}

// merge 2 sorted linked lists
Node* merge(Node* a, Node* b) {
    if (a == nullptr) {
        return b;
    }
    if (b == nullptr) {
        return a;
    }

    Node* c {};

    if (a->data < b->data) {
        c = a;
        c->next = merge(a->next, b);
    } else {
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}

Node* midPoint(Node* head) {
    Node* slow {head};
    Node* fast {head->next};
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Merge sort using linked list
Node* mergeSort(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Bread at the middle
    Node* mid = midPoint(head);
    Node* a = head;
    Node* b = mid->next;
    mid->next = nullptr;

    a = mergeSort(a);
    b = mergeSort(b);

    return merge(a, b);
}

int main() {
    Node* head = nullptr;
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 0);

    insertInMiddle(head, 100, 3);

    print(head);

    head = reverseRecursive(head);
    print(head);
    head = reverseIterative(head);
    print(head);

    head = kReverse(head, 3);
    print(head);

    Node* a = nullptr;
    insertAtHead(a, 10);
    insertAtHead(a, 7);
    insertAtHead(a, 5);
    insertAtHead(a, 1);

    Node* b = nullptr;
    insertAtHead(b, 6);
    insertAtHead(b, 3);
    insertAtHead(b, 2);

    head = merge(a, b);
    print(head);

    a = mergeSort(a);
    print(a);
}
