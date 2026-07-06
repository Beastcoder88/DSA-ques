#include<bits/stdc++.h>
using namespace std;

struct Node{
public:
    int data;
    Node* next;

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convert2LL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void print(Node* head){
    while (head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

Node* HeadInsertion(Node* head, int val){
    Node* temp = new Node(val,head);
    return temp;
}

Node* tailInsertion(Node* head,int val){
    if(head == NULL) return new Node(val);
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    Node* newNode = new Node(val);
    temp->next = newNode;
    return head;
}

Node* KthInsertion(Node* head,int val,int k){
    if(head == NULL){
        if(k==1) return new Node(val);
        else return NULL;
    }
    if(k==1){
        Node* temp = new Node(val,head);
        return temp;
    }
    int cnt = 0;
    Node* temp = head;
    while(temp!=NULL){
        cnt++;
        if(cnt==(k-1)){
            Node* x = new Node(val,temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

Node* InsertBeforeValue(Node* head,int val,int n){
    if(head == NULL){
        return NULL;
    }
    if(head->data == n) return new Node(val,head);
    Node* temp = head;
    while(temp!=NULL){
        if(temp->next->data==n){
            Node* x = new Node(val,temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main() {
    vector<int> arr = {12,34,23,39};
    Node* head = convert2LL(arr);
    head = InsertBeforeValue(head,99,23);
    print(head);
    return 0;
}