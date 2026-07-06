#include <bits/stdc++.h>
using namespace std;

class Node {
public: // Corrected from 'Public'
    int data;       // the data value
    Node* next;     // pointer to the next node

    // Constructor with data and next pointer
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data
    Node(int data1) {
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
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

//brute force approach
Node* findMiddle(Node* head){
    if(head==nullptr || head->next == nullptr){
        return head;
    }
    Node* temp = head;
    int cnt = 0;
    while(temp!=nullptr){
        cnt++;
        temp = temp->next;
    }
    int mid = cnt/2 + 1;
    temp = head;
    while(temp!=nullptr){
        mid = mid - 1;
        if(mid == 0){
            break;
        }
        temp = temp->next;
    }
    return temp;
}

Node* FindMiddle(Node* head){
    Node* fast = head;
    Node* slow = head;
    while(fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}



int main() {
    vector<int> arr = {4, 5, 8, 7, 0};
    // Node* y = new Node(arr[0]);

    // cout << y << '\n';        // prints the memory address
    // cout << y->data << '\n';  // prints the data stored at that address

    Node* head = convert2LL(arr);  
    print(head);
    Node* midNode = FindMiddle(head);
    cout<<"the middle node is : "<<midNode->data<<endl;
    return 0;
}