#include <bits/stdc++.h>
using namespace std;

struct Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data1, Node* next1,Node* prev1) {
        data = data1;
        next = next1;
        prev = prev1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

Node* convert2DLL(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(Node* head){
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

Node* headDeletion(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    head->prev = nullptr;
    temp->next = nullptr;
    delete temp;
    return head;
}

Node* TailDeletion(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* p = head;
    Node* q = head->next;
    while(p->next->next!=NULL){
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    q->prev = NULL;
    delete q;
    return head;
}


int main() {
    vector<int> arr = {12,34,23,39};
    Node* head = convert2DLL(arr);
    head = TailDeletion(head);
    print(head);
    return 0;
}