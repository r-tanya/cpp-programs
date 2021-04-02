#include <iostream>
#include <string>

using namespace std;

template <class T>
class DSLinkedList {

    // internal presentation of list node
    struct ListNode {
        T value;
        ListNode* next;
        ListNode(T value1, ListNode* next1 = NULL) {
            value = value1;   next = next1;
        }
    };

    ListNode* head;
    ListNode* tail;

    unsigned int num_elements;

public:
    DSLinkedList() {
        head = NULL;
        tail = NULL;
        num_elements = 0;
    }

    void append(T val) {
        ListNode* newNode = new ListNode(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        num_elements++;
    }

    void prepend(T element) {
        ListNode* newNode = new ListNode(element);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
        num_elements++;
    }

    T del_first() {
        if (head == NULL) return false;

        ListNode* tmp = head;
        head = head->next;
        T val = tmp->value;
        num_elements--;
        delete tmp;

        return val;
    }

    void print() {
        ListNode* tp = head;
        while (tp != NULL) {
            cout << tp->value << "\n";
            tp = tp->next;
        }
    }

    unsigned int numelements() {
        return num_elements;
    }

    bool find(T needle) {
        ListNode* tp = head;
        while (tp != NULL) {
            if (tp->value == needle) return true;
            tp = tp->next;
        }
        return false;
    }

    bool remove(T element) {
        // Removes all instances of element
        bool found = false;
        ListNode* tpprev = NULL;
        ListNode* tp = head;

        while (tp != NULL) {
            if (tp->value == element) {
                found = true;
                ListNode* delme = tp;
                if (tpprev == NULL) {  // To check if current node is head node
                    head = tp->next;
                    tp = head;
                }
                else {
                    tpprev->next = tp->next;
                    tp = tpprev->next;
                }
                // If found, make previous node's 'next' point to following node
                num_elements--;
                delete delme;
            }
            else {
                if (tpprev == NULL) {
                    tpprev = tp;
                    tp = tp->next;
                }
                else {
                    tp = tp->next;
                    tpprev = tpprev->next;
                }
                // If not found, move to the next
            }
        }
        return found;
    }

    ~DSLinkedList() {
        //cout << "Destructor called\n";
        ListNode* tmp = head;
        ListNode* prev;
        while (tmp) {
            prev = tmp;
            tmp = tmp->next;
            delete prev;
        }
    }
};

int main() {
    
    // Queue
    DSLinkedList<int> queue;
    for (int i = 1; i < 7; i++) queue.append(i);  // enqueue
    queue.print();
    for (int i = 1; i < 7; i++) cout << queue.del_first() << endl;  // dequeue
    
    // Stack
    DSLinkedList<int> stack;
    for (int i = 1; i < 4; i++) stack.prepend(i);  // push
    for (int i = 1; i < 4; i++) cout << stack.del_first() << endl;  // pop

    system("pause");
    return 0;
}