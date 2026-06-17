/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode *fast{head}, *slow{nullptr};
        if (head != nullptr) { slow = head->next; }
        bool found = false;
        while (fast != nullptr && slow != nullptr)
        {
            if (fast == slow)
            {
                found = true;
                break;
            }
            fast = fast->next;
            slow = (slow->next != nullptr)? slow->next->next : nullptr;            
        }
        return found;
    }
};
