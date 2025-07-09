class Node{
public:
int data;  // data of the node
Node* next; // next pointer of the node
 Node(int data1, Node* next1){  // constructor of the node with both the data and the pointer
data=data1;
next=next1;
}
Node(int data1){
data=data1;
next=nullptr;
}
};


// deleting the last node of the list
Node * deleteTail(Node* head){
    if(head==nullptr) return nullptr;
    if(head->next==nullptr){
        delete head;
        return nullptr;
    }
    Node* curr=head;
    while(curr->next->next!=nullptr){
        curr=curr->next;
    }
    delete curr->next;
    curr->next=nullptr;
    return head;
}