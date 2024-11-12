#include<iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;

    Node(int data){
        val=data;
        next=NULL;
    }
};

void insertAtHead(Node* &head , int val){
    Node* new_node = new Node(val);
    new_node->next = head;
    head = new_node;
}

void insertAtTail(Node* &head , int val){
    Node* new_node = new Node(val);
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }

    temp->next=new_node;  //temp reached the the last node

}

void insertAtPosition(Node* &head , int val , int pos){

    if(pos==0){
        insertAtHead(head,val);
        return;
    }

    Node* new_node = new Node(val);
    Node* temp = head;
    int curr_pos=0;;
    while(curr_pos!=pos-1){
        temp=temp->next;
        curr_pos++;
    }

    //temp is pointing at last position (pos-1)
    new_node->next = temp->next;
    temp->next = new_node;
}

void display(Node* head){

    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){

    Node* head = NULL;
    insertAtHead(head,2);
    display(head);
    insertAtHead(head,1);
    display(head);
    insertAtTail(head,4);
    display(head);
    insertAtPosition(head,3,2);
    display(head);

}