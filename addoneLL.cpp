#include <bits/stdc++.h>
using namespace std;

// Node class representing a single digit in the linked list
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// LinkedList class to manage node-level operations
class LinkedList {
public:
    // function to insert digit at the end
    Node* append(Node* head, int value) {
        Node* newNode = new Node(value);
        if (!head) {
            return newNode;
        }
        Node* current = head;
        while (current->next)
            current = current->next;
        current->next = newNode;
        return head;
    }

    // Function to print the list
    void printList(Node* head) {
        Node* current = head;
        while (current) {
            cout << current->data;
            current = current->next;
        }
        cout << endl;
    }
};

// Solution class having the addOne logic 
class Solution {
public:

    Node* reverseLL(Node* node){
        Node* prev = nullptr;
        Node* curr = node;
        while(curr){
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    Node* addOne(Node* head){
        head = reverseLL(head);
        Node* curr = head;
        int carry = 1;
        while(curr && carry){
            int sum = curr->data+carry;
            curr->data = sum%10;
            carry = sum/10;
            if(!curr->next && carry){
                curr->next = new Node(carry);
                carry = 0;
            }
            curr = curr->next;
        }
        return reverseLL(head);
    }
};

int main() {
    Node* head = nullptr;
    LinkedList ll;
    Solution sol;

    // Example: Number 129 (1 -> 2 -> 9)
    head = ll.append(head, 9);
    head = ll.append(head, 9);
    head = ll.append(head, 9);

    cout << "Original Number: ";
    ll.printList(head);

    head = sol.addOne(head);

    cout << "After Adding One: ";
    ll.printList(head);

    return 0;
}