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
Node* DeleteHead(Node* head){
    if(head==NULL) return head;
    Node* temp=head;
    head=head->next;
    delete temp;
    return head;

}
Node* DeleteTail(Node* head){
    if(head==NULL || head->next==NULL) return NULL;
    Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;

    }
    delete temp->next;
    temp->next=NULL;
    return head;

}
Node* DeleteFRPOSition(Node* head,int key){
    if(head==NULL) return head;

    if(key==1){
        head=DeleteHead(head);
        return head;

    }
    int cnt=0;
    Node* temp=head;
    Node* prv=NULL;
    while(temp!=NULL){
        cnt++;
        if(cnt==key){
            prv->next=prv->next->next;
            free(temp);
            break;
        }
        prv=temp;
        temp=temp->next;
    }
    return head;

}
Node* DeleteBYVAlue(Node* head,int value){
    if(head==NULL) return head;

    if(head->data==value){
        head=DeleteHead(head);
        return head;

    }
  
    Node* temp=head;
    Node* prv=NULL;
    while(temp!=NULL){
        
        if(temp->data==value){
            prv->next=prv->next->next;
            delete temp;
            break;
        }
        prv=temp;
        temp=temp->next;
    }
    return head;

}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    Node* removeElements(Node* head, int val) {

        if(head==NULL) return head;

        while(head!=NULL && head->data==val){
            Node* temp=head;
            head=head->next;
            delete temp;
        }

        Node* temp=head;
        Node* prvs=NULL;

        while(temp!=NULL){
            if(temp->data==val){
                prvs->next=temp->next;
                delete temp;
                temp=prvs->next;

            }
            else{
                prvs=temp;
                temp=temp->next;
            }
        }
        return head;
        
    }
};
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
    cout<<y->data<<endl;
    cout<<y<<endl;
    printLINEDLIST(y);

    y=DeleteHead(y);
    printLINEDLIST(y);

    y=DeleteTail(y);
    printLINEDLIST(y);

    y=DeleteFRPOSition(y,1);
    printLINEDLIST(y);
    
     y=DeleteBYVAlue(y,6);
    printLINEDLIST(y);

    Solution s1;
    vector<int> arr2={1,2,6,3,4,5,6};
    Node* h1= ConvertARR2LL(arr2);
    s1.removeElements(h1,6);
    printLINEDLIST(h1);




    return 0;

    
    
  
}