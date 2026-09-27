#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(){


    }
    Node(int data){
        this->data = data;
        this->next = NULL;

    }
};

void insertAtBegin(Node* &head,Node* &tail,int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }else{
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }

}
void traverseLinkList(Node* &head) {

    if (head == NULL || head->next == NULL)
        return;

    Node* evenHead = NULL;
    Node* evenTail = NULL;
    Node* oddHead  = NULL;
    Node* oddTail  = NULL;

    Node* temp = head;

    while (temp != NULL) {

        Node* next = temp->next; 

        temp->next = NULL;  

        if (temp->data % 2 == 0) {

            if (evenHead == NULL) {
                evenHead = temp;
                evenTail = temp;
            } else {
                evenTail->next = temp;
                evenTail = temp;
            }

        } else {

            if (oddHead == NULL) {
                oddHead = temp;
                oddTail = temp;
            } else {
                oddTail->next = temp;
                oddTail = temp;
            }
        }

        temp = next;
    }

    if (oddHead == NULL) return;
    if (evenHead == NULL) {
        head = oddHead;
        return;
    }

    evenTail->next = oddHead;
    head = evenHead;
}
void display(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // data input inside linklist
    insertAtBegin(head, tail, 6);
    insertAtBegin(head, tail, 7);
    insertAtBegin(head, tail, 1);
    insertAtBegin(head, tail, 4);
    insertAtBegin(head, tail, 5);
    insertAtBegin(head, tail, 10);
    insertAtBegin(head, tail, 12);
    insertAtBegin(head, tail, 8);
    insertAtBegin(head, tail, 15);
    insertAtBegin(head, tail, 17);

   //before
    display(head);

    traverseLinkList(head);
    /// after
    display(head);

    return 0;
}



