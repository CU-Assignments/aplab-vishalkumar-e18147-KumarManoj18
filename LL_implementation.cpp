#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void removeNode(int value) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Node with value " << value << " removed.\n";
            return;
        }

        Node* current = head;
        while (current->next && current->next->data != value) {
            current = current->next;
        }

        if (current->next) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            cout << "Node with value " << value << " removed.\n";
        } else {
            cout << "Value " << value << " not found in the list.\n";
        }
    }

    // Print the list
    void printList() const {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        Node* current = head;
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL\n";
    }

    // Reverse the list
    void reverseList() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current) {
            next = current->next; 
            current->next = prev; 
            prev = current;       
            current = next;       
        }

        head = prev; 
        cout << "List reversed.\n";
    }

    ~SinglyLinkedList() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    SinglyLinkedList list;

    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtHead(30);
    list.printList(); 

    list.removeNode(20);
    list.printList(); 

    list.reverseList();
    list.printList(); 
    list.removeNode(40); 
    return 0;
}
