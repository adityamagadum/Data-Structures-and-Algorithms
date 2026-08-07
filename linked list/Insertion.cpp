#include<bits/stdc++.h>
using namespace std;
class Node{

    public:
    int data;
    Node* next;

    public:
    Node(int data1 ,Node* next1){
        data=data1;
        next=next1;
    }
    public:
    Node(int data1) {
        data=data1;
        next=nullptr;
    }
};
Node*  ConvertARR2LL(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=mover->next;
        //mover=temp;
    }
    return head;

}
Node* InsertHead(Node* head,int data){
   
    Node* temp = new Node(data);
    temp->data=data;
    temp->next=head;
    head=temp;
    return head;

}
Node* InsertTail(Node* head,int data){
    Node* temp=new Node(data);

    Node* temp2=head;

    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp;
    return head;


}
Node* InsertATK(Node* head,int value,int k){
    if(head==NULL){
        if(k==1){
            return new Node(value);
        }
        else{
            cout<<"not possible to insert at this pos";
            return NULL;
        }
    }
    if(k==1){
        Node* temp=new Node(value,head);
        return temp;
    }
    int cnt=0;
    Node* temp=head;
    while(temp!=NULL){
        cnt++;
        if(cnt==k-1){
            Node* temp2=new Node(value);
            temp2->next=temp->next;
            temp->next=temp2;
            return head;
        }
        temp=temp->next;
    }
    return head;
}
Node* InsertBEFOREval(Node* head,int value,int bef){
    if(head==NULL){
        return NULL;
    }
    if(head->data==bef){
        Node* temp=new Node(value,head);
        return temp;
    }
    
    Node* temp=head;
    while(temp->next!=NULL){
        
        if(temp->next->data==bef){
            Node* temp2=new Node(value);
            temp2->next=temp->next;
            temp->next=temp2;
            break;
        }
        temp=temp->next;
    }
    return head;
}
void printLINEDLIST(Node* head){
        Node *temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    vector<int> arr={20,5,8,6,7};
    //vector<int> arr={1,2,6,3,4,5,6};
    Node* y= ConvertARR2LL(arr);

    printLINEDLIST(y);

    y=InsertHead(y,11);
    printLINEDLIST(y);
    
    y=InsertTail(y,12);
    printLINEDLIST(y);

    y=InsertATK(y,13,3);
    printLINEDLIST(y);

    
    y=InsertBEFOREval(y,15,13);
    printLINEDLIST(y);




    return 0;

    
    
  
} 