#include<bits/stdc++.h>
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

int checkIfPresent(Node* head,int val){
    Node* temp = head;
    while(temp){
        if(temp->data == val) return 1;
        temp = temp->next;
    }
    return -1;
}

int lengthOfLL(Node* head){
    int cnt = 0;
    Node* temp = head;
    while(temp){
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

int main() {
    vector<int> arr = {4, 5, 8, 7, 0};
    Node* y = new Node(arr[0]);

    cout << y << '\n';        // prints the memory address
    cout << y->data << '\n';  // prints the data stored at that address

    Node* head = convert2LL(arr);
    // Node* temp = head;
    // while(temp){
    //     cout<<temp->data<<" ";
    //     temp = temp->next;
    // }
    // cout<<endl;
    // int m = lengthOfLL(head);
    // cout<<m;
    cout<< checkIfPresent(head,7);

    delete y; // good practice to free memory
    return 0;
}