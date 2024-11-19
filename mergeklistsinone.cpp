#include<iostream>
#include<vector>
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

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void insertAtTail(int value) {
        Node* new_node = new Node(value);
        if (head == NULL) {  // Linked list is empty
            head = new_node;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

Node* mergeLL(Node* &head1 , Node* head2){

    Node* dummyHeadNode = new Node(-1);

    Node* ptr1 = head1;
    Node* ptr2 = head2;
    Node* ptr3 = dummyHeadNode;

    while(ptr1 && ptr2){
        if(ptr1->val < ptr2->val){
            ptr3->next = ptr1;
            ptr1=ptr1->next;
        }else{
            ptr3->next = ptr2;
            ptr2=ptr2->next;
        }
        ptr3=ptr3->next;
    }

    if(ptr1!=NULL){
        ptr3->next=ptr1;
    }else{
        ptr3->next=ptr2;
    }
    return dummyHeadNode->next;
}

Node* mergeKll(vector<Node*> &lists){

    if(lists.size()==0){
        return NULL;
    }

    while(lists.size()>1){

    Node* mergeHead = mergeLL(lists[0],lists[1]);
    lists.push_back(mergeHead);
    lists.erase(lists.begin());
    lists.erase(lists.begin());
    }
    return lists[0];
}

//head1 head2 head3 head4
//mergedhead1_2 head3 head4
//mergedhead1_2 mergedhead3_4
//mergedhead1_2_3_4


int main() {
    LinkedList ll1;
    ll1.insertAtTail(1);
    ll1.insertAtTail(7);
    ll1.insertAtTail(8);
    ll1.display();

    LinkedList ll2;
    ll2.insertAtTail(2);
    ll2.insertAtTail(4);
    ll2.insertAtTail(5);
    ll2.display();

    LinkedList ll3;
    ll3.insertAtTail(3);
    ll3.insertAtTail(6);
    ll3.display();

    vector<Node*> lists;
    lists.push_back(ll1.head);
    lists.push_back(ll2.head);
    lists.push_back(ll3.head);

    LinkedList mergedLL;
    mergedLL.head = mergeKll(lists);
    mergedLL.display();

    return 0;
}
