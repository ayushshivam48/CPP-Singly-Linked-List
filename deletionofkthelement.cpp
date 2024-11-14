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

void updateAtPosition(Node* &head , int k , int val){

    Node* temp = head;
    int curr_pos=0;

    while(curr_pos!=k){
        temp=temp->next;
        curr_pos++;
    }

    //temp will be pointing to the kth pos
    temp->val=val;
}

void deleteAtHeadPosition(Node* &head){

    Node* temp = head; //node to be deleted
    head = head->next;
    free(temp);
}

void deleteAtEndPosition(Node* &head){

    Node* sec_lst = head;
    while(sec_lst->next->next!=NULL){
        sec_lst=sec_lst->next;
    }

    //now sec lst point to sec last node
    Node* temp = sec_lst->next;  // node to be deleted
    sec_lst->next=NULL;
    free(temp);
}

void deleteAtPosition(Node* &head , int pos){

    if(pos==0){
        deleteAtHeadPosition(head);
        return;
    }

    int curr_pos=0;
    Node* prev=head;
    while(curr_pos!=pos-1){
        prev=prev->next;
        curr_pos++;
    }

    //prev is pointing to node at pos-1
    Node* temp=prev->next;
    prev->next=prev->next->next;
    free(temp);
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
    insertAtHead(head,5);
    display(head);
    insertAtHead(head,1);
    display(head);
    insertAtTail(head,4);
    display(head);
    insertAtPosition(head,3,2);
    display(head);
    updateAtPosition(head,1,2);
    display(head);
    deleteAtHeadPosition(head);
    display(head);
    deleteAtEndPosition(head);
    display(head);
    deleteAtPosition(head,1);
    display(head);
}