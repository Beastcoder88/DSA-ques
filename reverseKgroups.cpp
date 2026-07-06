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
class solution{
public:
    Node* reverseLL(Node* head){
        Node* prev = nullptr;
        Node* curr = head;
        while(curr){
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    Node* getKthNode(Node* curr,int k){
        while(curr && k>0){
            curr = curr->next;
            k--;
        }
        return curr;
    }

    Node* reverseKGroup(Node* head,int k){
        Node* dummy = new Node(0);
        dummy->next = head;
        Node* groupPrev = dummy;
        while(true){
            Node* kth = getKthNode(groupPrev,k);
            if(!kth) break;
            Node* groupNext = kth->next; 
            //isolate
            Node* groupStart = groupPrev->next;
            kth->next = nullptr;
            //reverse k grous
            Node* reversedK = reverseLL(groupStart);

            //connect
            groupPrev->next = reversedK;

            groupStart->next = groupNext;

            groupPrev = groupStart;

        }
        return dummy->next;
    } 

};

int main(){
    solution obj;
    // Creating the linked list: 1->2->3->4->5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int k = 3;

    // Reversing in groups of k
    Node* result = obj.reverseKGroup(head, k);

    // Printing the reversed list
    while (result != NULL) {
        cout << result->data << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}