#include <iostream>
using namespace std;

class SinglyLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    void insert(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void deleteNode(int key) {
        Node* temp = head;
        Node* prev = nullptr;

        while (temp && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (!temp) return; // Key not found

        if (!prev) {
            head = temp->next; // Delete head
        } else {
            prev->next = temp->next; // Delete non-head node
        }

        delete temp;
    }

    void traverse() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
int main() {
    SinglyLinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    cout << "Singly Linked List:" << endl;
    list.traverse();

    list.deleteNode(20);
    cout << "After deletion:" << endl;
    list.traverse();

    return 0;
}
