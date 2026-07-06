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


Node* reverseDLL(Node* head){
    Node* temp = head;
    stack<int> st;
    while(temp!=nullptr){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp!=nullptr){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

Node* reversedLL(Node* head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    Node* curr = head;
    while(curr!=nullptr){
        Node* temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;

        head = curr;
        curr = temp; 
    }
    return head;
}

int main() {
    vector<int> arr = {12,34,23,39};
    Node* head = convert2DLL(arr);
    head = reversedLL(head);
    print(head);
    return 0;
}