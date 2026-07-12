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
int main(){
    vector<int> arr={20,5,6,7};
    Node* y= ConvertARR2LL(arr);
    cout<<y->data<<endl;
    cout<<y<<endl;
    Node *temp=y;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    

}