#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int data) {
        val = data;
        next = NULL;
    }
};

int main() {
    // Create nodes
    Node* n1 = new Node(6);
    Node* n2 = new Node(5);
    Node* n3 = new Node(4);
    Node* n4 = new Node(3);

    // Link the nodes
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    // Print the values and next pointers
    Node* current = n1;
    while(current != NULL) {
        cout <<  current->val <<" (" << current->next << ")" << "->";
        current = current->next;
    }

}
