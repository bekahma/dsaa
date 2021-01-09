/*
 Rebecca Ma
 Joseph Ma
 Teemo
 2021-01-08
*/

#include <iostream>
#include <string>
using namespace std;

#define SIZE 20

// Basic program to link "student numbers" to their names.

class Node {
public:
    int studentID; // key
    string studentName;   // val
    Node *next;
    
    Node(){
        studentID = 0;
        studentName = "";
        next = NULL;
    }

    Node(int id, string name){
        studentID = id;
        studentName = name;
        next = NULL;
    }

    Node(int id, string name, Node *nextptr){
        studentID = id;
        studentName = name;
        next = nextptr;
    }
};

const int hashAlgo = 2;
/*
all are mod by size at the end
0 - do nothing to input
1 - multiply by 3 and add 1
2 - sum all digits
*/
int hashed(int input){
    int hash = input;
    int sum;
    switch(hashAlgo){
    case 1:
        hash = (hash*3) + 1;
        break;
    case 2:
        sum = hash % 10;
        while(hash){
            hash /= 10;
            sum += hash % 10;
        }
        hash = sum;
        break;
    default:
        break;
    }
    return hash % SIZE;
}

Node* handbook[SIZE];

// assuming no repeated IDs
void insert(int id, string name){
    /*
    get hashed id
    get the node pointer in the array handbook at the hash
    insert to start
    */
    int temp = hashed(id);
    Node* ptr = handbook[temp]; // first block of handbook at location temp
    Node* cur = new Node(id, name, ptr); // student that's being inserted
    handbook[temp] = cur;
    return;
}

string getStudent(int id){
    /*
    get hashed id
    get pointer in array
    iterate through linked list to find id
    return student name
    */
    int temp = hashed(id);
    Node* ptr = handbook[temp];
    
    while(ptr) {
        if(id == ptr -> studentID) {
            return ptr -> studentName;
        }
        ptr = ptr -> next;
    }
    
    return to_string(id) + " is not enrolled at Ma University.";
}

void printHandbook(){
    for(int i = 0; i < SIZE; i++) {
        Node* ptr = handbook[i];
        if(ptr){
            cout << i << endl;
            while(ptr) {
                cout << ptr -> studentID << ": " << ptr -> studentName << endl;
                ptr = ptr -> next;
            }
            cout << endl;
        }
    }
}

int main(){
    switch(hashAlgo){
    case 0:
        cout << "No change";
        break;
    case 1:
        cout << "Multiply by 3 and add one";
        break;
    case 2:
        cout << "Sum all the digits";
        break;
    default:
        break;
    }
    cout << ", and mod by 20" << endl;
    cout << endl;

    for(int i = 0; i < SIZE; i++){
        handbook[i] = NULL;
    }
    
    insert(98034821, "Teemo");
    insert(74637213, "Vladimir");
    insert(45813541, "Wand Lady");
    /*
    cout << getStudent(98034821) << endl;
    cout << getStudent(45813541) << endl;
    cout << getStudent(74637213) << endl;
    cout << getStudent(43219876) << endl;

    cout << endl;
    */
    printHandbook();

    cout << endl;

    return 0;
}