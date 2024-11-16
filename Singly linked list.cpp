/* 1.	Implementing Linked Lists:
o	Implement singly linked lists with methods for insertion, deletion, and traversal.
o	Implement doubly linked lists with methods for insertion, deletion, and traversal.
o	Implement circular linked lists with methods for insertion, deletion, and traversal*/

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
// Implement doubly linked lists with methods for insertion, deletion, and traversal.
#include <iostream>
using namespace std;

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node* prev;
        Node(int val) : data(val), next(nullptr), prev(nullptr) {}
    };
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

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
            newNode->prev = temp;
        }
    }

    void deleteNode(int key) {
        Node* temp = head;

        while (temp && temp->data != key) {
            temp = temp->next;
        }

        if (!temp) return; // Key not found

        if (temp->prev) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next; // Delete head
        }

        if (temp->next) {
            temp->next->prev = temp->prev;
        }

        delete temp;
    }

    void traverse() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyLinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    cout << "Doubly Linked List:" << endl;
    list.traverse();

    list.deleteNode(20);
    cout << "After deletion:" << endl;
    list.traverse();

    return 0;
}

// Implement circular linked lists with methods for insertion, deletion, and traversal
#include <iostream>
using namespace std;

class CircularLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };
    Node* tail;

public:
    CircularLinkedList() : tail(nullptr) {}

    void insert(int data) {
        Node* newNode = new Node(data);
        if (!tail) {
            tail = newNode;
            tail->next = tail; // Points to itself
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteNode(int key) {
        if (!tail) return; // Empty list

        Node* curr = tail->next;
        Node* prev = tail;

        do {
            if (curr->data == key) {
                if (curr == tail && curr->next == tail) { // Single node
                    tail = nullptr;
                } else {
                    prev->next = curr->next;
                    if (curr == tail) {
                        tail = prev; // Update tail if needed
                    }
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != tail->next);
    }

    void traverse() {
        if (!tail) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = tail->next;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << "(back to start)" << endl;
    }
};

int main() {
    CircularLinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    cout << "Circular Linked List:" << endl;
    list.traverse();

    list.deleteNode(20);
    cout << "After deletion:" << endl;
    list.traverse();

    return 0;
}

/* Linked List Implementation:
o	Create classes SinglyLinkedList, DoublyLinkedList, and CircularLinkedList.*/
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

        if (!temp) return;

        if (!prev) {
            head = temp->next;
        } else {
            prev->next = temp->next;
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
// Postfix Calculator:
// o	Write a class PostfixCalculator that evaluates postfix expressions using a stack.
#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

class PostfixCalculator {
public:
    int evaluate(const string& expression) {
        stack<int> s;
        stringstream ss(expression);
        string token;

        while (ss >> token) {
            if (isdigit(token[0])) {
                s.push(stoi(token));
            } else {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();

                switch (token[0]) {
                    case '+': s.push(a + b); break;
                    case '-': s.push(a - b); break;
                    case '*': s.push(a * b); break;
                    case '/': s.push(a / b); break;
                }
            }
        }

        return s.top();
    }
};

int main() {
    PostfixCalculator calc;
    string expression = "3 4 + 2 * 7 /"; // Example: (3 + 4) * 2 / 7
    cout << "Result: " << calc.evaluate(expression) << endl;
    return 0;
}
// Queue-Based Ticketing System:
// o	Write a class TicketQueue that simulates a ticketing system using a queue. Include methods to add tickets to the queue and to process them.
#include <iostream>
#include <queue>
using namespace std;

class TicketQueue {
private:
    queue<int> tickets;
    int nextTicket;

public:
    TicketQueue() : nextTicket(1) {}

    void addTicket() {
        tickets.push(nextTicket++);
        cout << "Ticket added: " << nextTicket - 1 << endl;
    }

    void processTicket() {
        if (tickets.empty()) {
            cout << "No tickets to process." << endl;
        } else {
            cout << "Processing ticket: " << tickets.front() << endl;
            tickets.pop();
        }
    }

    void displayQueue() {
        if (tickets.empty()) {
            cout << "Queue is empty." << endl;
        } else {
            queue<int> temp = tickets;
            while (!temp.empty()) {
                cout << temp.front() << " ";
                temp.pop();
            }
            cout << endl;
        }
    }
};

int main() {
    TicketQueue queue;
    queue.addTicket();
    queue.addTicket();
    queue.processTicket();
    queue.displayQueue();
    return 0;
}

/*Priority Queue Implementation:
o	Write a class PriorityQueue that uses a heap to manage elements based on their priority.*/
#include <iostream>
#include <queue>
using namespace std;

class PriorityQueue {
private:
    priority_queue<int> maxHeap;

public:
    void insert(int data) {
        maxHeap.push(data);
        cout << "Inserted: " << data << endl;
    }

    void deleteMax() {
        if (maxHeap.empty()) {
            cout << "Priority queue is empty." << endl;
        } else {
            cout << "Removed max: " << maxHeap.top() << endl;
            maxHeap.pop();
        }
    }

    void display() {
        priority_queue<int> temp = maxHeap;
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    pq.insert(10);
    pq.insert(20);
    pq.insert(15);
    pq.display();
    pq.deleteMax();
    pq.display();
    return 0;
}
