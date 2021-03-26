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
        /*New node is manipulated to point to the node that
        the head pointer was originally pointing to
        Then head pointer is made to reference the new node*/
        }
        num_elements++;
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
        //Removes all instances of element
        
        bool found = false;
        ListNode* tpprev = NULL;
        ListNode* tp = head;

        while (tp != NULL) {
            if (tp->value == element) {
                found = true;
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
    
    DSLinkedList<int> myll;

    for (int i = 0; i < 7; i++) {
        myll.append(i);
    }
    myll.append(7);
    myll.remove(0);
    myll.remove(7);
    myll.prepend(0);

    myll.print();
    cout << endl << "No of elements is " << myll.numelements() << endl;

    if (myll.find(1)) cout << "Found 1\n";
    if (!myll.find(100)) cout << "Not found 100\n";
    
    system("pause");
    return 0;
}