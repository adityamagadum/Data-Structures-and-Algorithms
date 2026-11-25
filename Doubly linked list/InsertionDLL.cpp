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

Node* InsertionBefHead(Node* head,int val)
{

    Node* newnode=new Node(val,head,NULL);
    head->back=newnode;
    newnode->next=head;
    head=newnode;
    return head;
}
Node* InsertionAFTERHead(Node* head,int val)
{

    Node* newnode=new Node(val);
    newnode->back=head;
    newnode->next=head->next;

    if (head->next != nullptr)
        head->next->back=newnode;

    head->next=newnode;


    return head;
}

int main(){
    vector<int> arr={1,2,3,4,5};
    Node* head=CONVERTarrayTODLL(arr);
    displayForward(head);

    head=InsertionBefHead(head,5);
    displayForward(head);

    head=InsertionAFTERHead(head,10);
    displayForward(head);


    return 0;
}