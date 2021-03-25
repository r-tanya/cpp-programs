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

public:
    DSLinkedList() {
        head = NULL;
        tail = NULL;
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
    }

    void print() {
        ListNode* tp = head;
        while (tp != NULL) {
            cout << tp->value << "\n";
            tp = tp->next;
        }
    }

    unsigned int numelements() {
        int count = 0;
        ListNode* tp = head;
        while (tp != NULL) {
            count++;
            tp = tp->next;
        }
        return count;
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
                if (tpprev == NULL) {  // To check if current node is head node
                    head = tp->next;
                    tp = head;
                }                
                else {
                    tpprev->next = tp->next;
                    tp = tpprev->next;
                }
                // If found, make previous node's 'next' point to following node
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
