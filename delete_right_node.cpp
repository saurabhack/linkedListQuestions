//Delete nodes having greater value on right
#include<iostream>
#include<vector>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }

};
node* deleteRight(node* head){
    vector<int> arr;
    node* current=head;
    while(current!=NULL){
        arr.push_back(current->data);
        current=current->next;
    }
    vector<int> st;
    for(int i=0;i<arr.size();i++){
        bool flag=false;
        for(int j=i+1;j<arr.size();j++){
            if(arr[j]>arr[i]){
                flag=true;
                break;
            }
        }
        if(!flag){
            st.push_back(arr[i]);
        }
    }
    node* newNode=new node(-1);
    node* a=newNode;
    for(int i=0;i<st.size();i++){
        a->next=new node(st[i]);
        a=a->next;
    }
    return newNode->next; 
}
void push(node* &head,int val){
    node* newNode=new node(val);
    if(head==NULL){
        head=newNode;
        return;
    }
    node* current=head;
    while(current->next!=NULL){
        current=current->next;
    }
    current->next=newNode;
}
void display(node* head){
    node* current=head;
    while(current!=NULL){
        cout<<current->data<<"->";
        current=current->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
node* head=NULL;
push(head,12); 
push(head,15);
push(head,10);
push(head,11);
push(head,5);
push(head,6);
push(head,2);
push(head,3);
display(head);
node* newHead=deleteRight(head);
display(newHead);
return 0;

}