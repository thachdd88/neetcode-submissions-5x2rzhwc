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
        ListNode *slow{head}, *fast{nullptr};
        if (head != nullptr) { fast = head->next; }
        bool found = false;
        while (fast != nullptr && slow != nullptr)
        {
            if (fast == slow)
            {
                found = true;
                break;
            }
            slow = slow->next;
            fast = (fast->next != nullptr)? fast->next->next : nullptr;            
        }
        return found;
    }
};
