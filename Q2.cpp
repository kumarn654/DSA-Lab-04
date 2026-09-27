#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;

    }

    ~Node(){
        while(this->next!=NULL){
            delete next;
        }

    }


};
void insertAtBegin(Node* &head,Node* &tail,int data){
    Node* temp = new Node(data);

   if(head == NULL){
        head = temp;
        tail = temp;
        tail->next = head;
   }else{
        temp->next = head;
        head = temp;
        tail->next = head;
   }

}
void insertAtLast(Node* &head,Node* &tail,int data){
    Node* temp = new Node(data);

    if(head == NULL){
        head = temp;
        tail = temp;
        tail->next = head;

    }else{
        tail->next = temp;
        tail = temp;
        tail->next = head;

    }

}
void insertAtPosition(Node* &head,Node* &tail,int position,int data){
   
    if(head == NULL){
        Node* newNode = new Node(data);

        head = newNode;
        tail = newNode;
        tail->next = head;
    }
   
    else{

    int size = 1;
    Node* startPoint = head;
    while(startPoint->next!=head){
        startPoint = startPoint->next;
        size++;
    }
    if(position< 1 || position> size){
        cout<<"Invalid Psoition!"<<endl;
        return;
    }

    if(position == 1){
        insertAtBegin(head,tail,data);
        return;
    }

    int count =1;
    Node* temp = head;

    while(count < position-1){
        temp = temp->next;
        count++;
    }

    if(temp->next==head){
        insertAtLast(head,tail,data);
        return;
    }

    Node* newNode = new Node(data); 
    newNode->next = temp->next;
    temp->next = newNode;
}

}
void deletionFromBegin(Node* &head,Node* &tail){
    if(head == NULL){
        return;
    }
    else if(head == tail){
        delete head;
        head = NULL;
        tail = NULL;
    }
    else{
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        tail->next = head;
    }
}

void deleteFromLast(Node* &head,Node* &tail){
    if(head == NULL){
        return;

    }else if(head == tail){
        delete head;
        head = NULL;
        tail = NULL;

    }
    else{
        Node* temp = head;
        while(temp->next!= tail){
            temp = temp->next;
        }
        tail = temp;
        temp = temp->next;
        tail->next = NULL;
        delete temp;
        tail->next = head;
    }
}
void deleteFromPosition(Node* &head,Node* &tail,int position){
    if(head == NULL){
        return;

    }
    else if(head == tail && position == 1){
        delete  head;
        head  = NULL;
        tail = NULL;

    }
    
    else{
        int size =1;
        if(position == 1){
            deletionFromBegin(head,tail);
            return;
        }

        Node* previous = NULL;
        Node* current = head;
        int count = 1;
         // count the size of linklist
        Node* temp = head;
        temp = temp->next;
        while(temp != head){
            temp = temp->next;
            size++;
        }
        if(position < 1 || position > size){
            cout<<"Invalid Position"<<endl;
            return;
        } 
        while(count <position){
            previous = current;
            current = current->next;
            count++;
        }
       
        if(previous->next == tail){
            deleteFromLast(head,tail);
            return;
        }

        previous->next = current->next;
        current->next = NULL;
        delete current;
       

    }
}
void display(Node* &head){

    if(head == NULL){
            return;
    }

    Node* temp = head;


    do{
    
        cout<<temp->data<<" ";
        temp = temp->next;
        
      
    }while(temp!=head);
    cout<<endl;
    
}


int main(){
     
    Node* node1 = new Node(5);
    Node* head = node1;
    Node* tail = node1;
    tail->next = head;

  
    insertAtBegin(head,tail,6);
    display(head);

    
    insertAtBegin(head,tail,7);
    display(head);

    
    insertAtLast(head,tail,8);
    display(head);

    
    insertAtPosition(head,tail,3,9);
    display(head);

    deletionFromBegin(head,tail);
    display(head);

    deleteFromLast(head,tail);
    display(head);

    return 0;
}