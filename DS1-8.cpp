#include <iostream>
#include <string>

using namespace std;

template <class T>
struct ListNode
{
    T value;
    ListNode<T>* next;
    ListNode(T value1, ListNode<T>* next1 = NULL)
    {
        value = value1;
        next = next1;
    }
};

int main()
{
    ListNode<double>* numberList = NULL;
    double number;
    
    cout << "Please input numbers. Enter 0 when finished: " << endl;
    cin >> number;
    while (number != 0)
    {
        numberList = new ListNode<double>(number, numberList);
        cin >> number;
    }
    
    cout << endl << "The contents of the list are: " << endl; 
    ListNode<double>* ptr = numberList;
    while (ptr != NULL)
    {
        cout << ptr->value << "  "; // Process node
        ptr = ptr->next;            // Move to next node
    }
    cout << endl << endl;
    
    system("pause");
    return 0;
}
