#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* previous;

    Node(){

    }

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->previous = NULL;

    }

    ~Node(){

        if(this->next!=NULL && this->previous!=NULL){
            delete this->next;
            delete this->previous;
        }
    }
};
void insertAtBegin(Node* &head,Node* &tail,int data){

    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        head->previous = tail;
        tail->next = head;  
    }else{
        Node* temp = new Node(data);
        temp->next = head;
        head->previous = temp;
        head = temp;
        head->previous = tail;
        tail->next = head;
    }
}
void insertAtLast(Node* &head,Node* &tail,int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        head->previous = tail;
        tail->next = head;  
    }else{
        Node* temp = new Node(data);
        tail->next = temp;
        temp->previous = head;
        tail = temp;
        head->previous = tail;
        tail->next = head;
        
    }

}
void insertAtPosition(Node* &head,Node* &tail,int position,int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        head->previous = tail;
        tail->next = head;
    }else{
       

        if(position==1){
            insertAtBegin(head,tail,data);
            return;

        }

        Node* temp = head;
        int count= 1;

        while(count < position-1){
            temp = temp->next;
            count++;
        }
        // insert at last 
        if(temp->next ==tail){
            insertAtLast(head,tail,data);
            return;
        }

        // create new node
        Node* newNode = new Node(data);
        newNode->previous = temp;
        newNode->next = temp->next;

        temp->next->previous = newNode;
        temp->next = newNode;


    }
}

void deleteAtPosition(Node* &head,Node* &tail,int position){
    if(head == NULL){
        cout<<"List is Empty!"<<endl;
        return;
    }
    else if(head == tail && position == 1){
        delete head;
        head = NULL;
        tail = NULL;
    }
    else{
        


        if(position==1){
            Node* temp = head;
            head = head->next;
            temp->next = NULL;
            head->previous = tail;
            tail->next = head;
            delete temp;
            return;
        }
        Node* temp = head;
        Node* old = NULL;   // just back previous pointer
        int count = 1;

        while(count < position){
            old = temp;
            temp = temp->next;
            count++;
        }

        // delete last node

        if(old->next == tail){
            tail = old;
            old = old->next;  // temp move at last node
            tail->next = NULL;
            old->previous = NULL;
            head->previous = tail;
            tail->next = head;
            delete old;
            return;
        }

        // delete at specific position
        old->next = temp->next;
        temp->next->previous = old;
        temp->previous = NULL;
        temp->next = NULL;
        delete temp;
    }
}

void display(Node* &head){
    if(head == NULL){
        cout<<"List is Empty!";
        return;
    }else{
        Node* temp = head;
        
        do{
            cout<<temp->data<<" ";
            temp = temp->next;
        }while(temp!=head);
        cout<<endl;
    }
   
}
int main(){

    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;
    head->previous  = tail;
    tail->next = head;

    insertAtBegin(head,tail,2);
    display(head);

    insertAtLast(head,tail,3);
    display(head);
    
    insertAtPosition(head,tail,3,10);
    display(head);

    deleteAtPosition(head,tail,2);
    display(head);   

    return 0;
}