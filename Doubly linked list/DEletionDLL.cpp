#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* back;
    Node(int data1,Node* next1,Node* back1){
        data=data1;
        next=next1;
        back=back1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }

};
Node* CONVERTarrayTODLL(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* prev=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        temp->back=prev;
        prev->next=temp;
        prev=temp;

    }
    return head;
 
}
void displayForward(Node* head) {
    Node* temp = head;
    cout << "Forward List: ";
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
Node* DeleteForward(Node* head)
{
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node* prev=head;
    head=head->next;

    prev->next=NULL;
    head->back=NULL;
    
    delete prev;
    return head;

}
Node* DeleteBackward(Node* head)
{
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node* tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    Node* prev=tail->back;
    prev->next=NULL;
    tail->back=NULL;

    delete tail;

    return head;

}
Node* DeleteFROM_kthPlace(Node* head,int k){
    Node* temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(cnt==k) break;
        temp =temp->next;
    }
    Node* prev=temp->back;
    Node* front=temp->next;
    if(prev==NULL && front==NULL){
        delete temp;
        return NULL;
    }
    else if(prev==NULL){
        head=DeleteForward(head);
        return head;
    }
    else if(front==NULL){
        head=DeleteBackward(head);
        return head;
    }
    else{
    prev->next=front;
    front->back=prev;
    temp=NULL;
    delete temp;

    }

    return head;

}
void DeleteNode(Node* temp){
    Node* prev=temp->back;
    Node* front=temp->next;

    if(front==NULL){
        prev->next=NULL;
        temp->back=NULL;
        delete temp;
        return;
    }
    prev->next=front;
    front->back=prev;
    temp=NULL;
    delete temp;

}
int main(){
    vector<int> arr={1,2,3,4,5};
    Node* head=CONVERTarrayTODLL(arr);
    displayForward(head);

    head=DeleteForward(head);
    displayForward(head);

    head=DeleteBackward(head);
    displayForward(head);

    head=DeleteFROM_kthPlace(head,2);
    displayForward(head);

    DeleteNode(head->next);
    displayForward(head);

    return 0;
}