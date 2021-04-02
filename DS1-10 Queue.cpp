#include <iostream>
#include <string>

using namespace std;

template <class T>

class Queue{

    // internal presentation of list node
    struct ListNode {
        T value;
        ListNode* next;
        ListNode(T value1, ListNode* next1 = NULL) {
            value = value1;   next = next1;
        }
    };

    ListNode* front;
    ListNode* rear;

    unsigned int num_elements;

public:
    Queue() {
        front = NULL;
        rear = NULL;
        num_elements = 0;
    }

    void enqueue(T val) {
        ListNode* newNode = new ListNode(val);
        if (front == NULL) {
            front = newNode;
            rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
        num_elements++;
    }

    T dequeue() {
        if (front == NULL) return false;
        
        ListNode* tmp = front;
        front = front->next;
        T val = tmp->value;
        num_elements--;
        delete tmp;  

        return val;
    }

    void print() {
        ListNode* tp = front;
        while (tp != NULL) {
            cout << tp->value << "\n";
            tp = tp->next;
        }
    }

    unsigned int numelements() {
        return num_elements;
    }

    bool find(T needle) {
        ListNode* tp = front;
        while (tp != NULL) {
            if (tp->value == needle) return true;
            tp = tp->next;
        }
        return false;
    }

    ~Queue() {
        //cout << "Destructor called\n";
        ListNode* tmp = front;
        ListNode* prev;
        while (tmp) {
            prev = tmp;
            tmp = tmp->next;
            delete prev;
        }
    }
};

int main() {

    Queue<int> myq;

    for (int i = 1; i < 7; i++) myq.enqueue(i);
    for (int i = 1; i < 7; i++) cout << myq.dequeue() << endl;

    system("pause");
    return 0;
}