#include <bits/stdc++.h>
using namespace std;

struct Node{
public:
    int data;
    Node* next;

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

Node* HeadDeletion(Node* head){
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

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
 
Node* TailDeletion(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    return head;
}

Node* removeK(Node* head,int k){
    if(head == NULL) return head;
    if(k == 1){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head; 
    }
    int cnt = 0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        cnt++;
        if(cnt == k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* removeEL(Node* head,int el){
    if(head == NULL) return head;
    if(head->data == el){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head; 
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        if(temp->data == el){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main() {
    vector<int> arr = {34,56,48,26};
    Node* head = convert2LL(arr);
    head = removeEL(head,48);
    print(head);
    return 0;
}