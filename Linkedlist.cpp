The linked list program:
#include <iostream>

// Node structure
struct Node {
    int data;
    Node* next;
};

// LinkedList class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Insert at head
    void insert(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // Insert at tail
    void insertAtTail(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Delete at head
    void deleteAtHead() {
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Print list
    void print() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList list;
    list.insertAtTail(5);
    list.insertAtTail(10);
    list.insertAtTail(15);

    std::cout << "Linked List: ";
    list.print();

    list.deleteAtHead();
    std::cout << "After deleting head: ";
    list.print();

    return 0;
}
```
Output:

```
Linked List: 5 10 15 
After deleting head: 10 15
```
