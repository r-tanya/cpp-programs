#include <iostream>
#include <string>
#include <assert.h>
#include "DSLL.h"

using namespace std;

string check_ok(string expression)
{
    DSStack<char> paren_stack;

    for (char& c : expression) {
        if (c == '(' || c == ')') paren_stack.push(c);
    }

    char side = ')';
    bool ok = true;
    while (!paren_stack.is_empty()) {
        if (paren_stack.pop() != side) ok = false;

        if (side == ')') side = '(';
        else side = ')';
    }
    if (side == '(') ok = false;

    if (ok) return "ok";
    else return "not ok";
}

float get_float_between_strings(string source, string first, string second) {
    int flen = first.length();
    if (source.find(first) == string::npos) return 0;
    int start = source.find(first) + flen;
    string rest = source.substr(start);
    int end = rest.find(second);
    rest = rest.substr(0, end);
    return stof(rest);
}

struct PairNode {
    string person_name;
    int phone;
    PairNode* next;
    PairNode(string name, int aphone, PairNode* next1 = NULL) {
        person_name = name;
        phone = aphone;
        next = next1;
    }
};

class Phonebook {

    struct PairList {
        PairNode* head;
        PairNode* tail;
        PairNode* curr;
        PairList() {
            head = NULL;
            tail = NULL;
            curr = NULL;
        }
    };
    PairList list[26];
    unsigned int no_of_people;

public:

    int retrieve(string name) {
        char c = name.at(0);
        PairNode* tp = list[c - 97].head;
        while (tp != NULL) {
            if (tp->person_name == name) return tp->phone;
            tp = tp->next;
        }
        return 0;
    }

    void add_person(string name, int phone) {
        char c = name.at(0);
        PairNode* newNode = new PairNode(name, phone);
        if (list[c - 97].head == NULL) {
            list[c - 97].head = newNode;
            list[c - 97].tail = newNode;
        }
        else if (name < list[c - 97].head->person_name) {
            newNode->next = list[c - 97].head;
            list[c - 97].head = newNode;
        }
        else {
            PairNode* tp = list[c - 97].head->next;
            PairNode* tpprev = list[c - 97].head;
            while (tp != NULL) {
                if (name < tp->person_name) {
                    tpprev->next = newNode;
                    newNode->next = tp;
                    break;
                }
                tp = tp->next;
                tpprev = tpprev->next;
            }
            tpprev->next = newNode;
        }
        no_of_people++;
    }

};

int main()
{
    //1
    
    string expression1 = "()";
    string expression2 = "3 * (2 + 6)";
    string expression3 = "4 * (2";
    string expression4 = ") 1 (";
    cout << expression1 << " " << check_ok(expression1) << endl;
    cout << expression2 << " " << check_ok(expression2) << endl;
    cout << expression3 << " " << check_ok(expression3) << endl;
    cout << expression4 << " " << check_ok(expression4) << endl;

    //2

    cout << "\nPlease enter your input in the form 'The value of Bitcoin was X, now it is Y:'\n";
    string input;
    getline(cin, input);
    input.append(" ");

    float value_then = get_float_between_strings(input, "was ", ",");
    float value_now = get_float_between_strings(input, "is ", ". ");
    float investment_value = (100) / (value_then / value_now);

    cout.precision(5);
    cout << "If you invested $100, the value would be " << investment_value << " now.\n\n";

    // 3

    Phonebook myphonebook;

    myphonebook.add_person("anna", 1057777809);
    myphonebook.add_person("alice", 1057771276);
    myphonebook.add_person("amy", 1057776512);
    myphonebook.add_person("ava", 1057770275);
    myphonebook.add_person("leo", 1057779000);
    myphonebook.add_person("lewis", 1057770988);
    myphonebook.add_person("zacchaeus", 1057771846);
    
    cout << myphonebook.retrieve("anna") << endl;
    cout << myphonebook.retrieve("alice") << endl;
    cout << myphonebook.retrieve("amy") << endl;
    cout << myphonebook.retrieve("ava") << endl;
    cout << myphonebook.retrieve("leo") << endl;
    cout << myphonebook.retrieve("lewis") << endl;
    cout << myphonebook.retrieve("zacchaeus") << endl;
    cout << myphonebook.retrieve("diana") << endl;

    system("pause");
    return 0;
}