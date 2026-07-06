#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr){
            return nullptr;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        unordered_map<ListNode*,int> NodeMap;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                slow = head;
                while(slow!=fast){
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};

int main() {
    
    return 0;
}