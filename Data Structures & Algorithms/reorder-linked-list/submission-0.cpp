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
    void reorderList(ListNode* head) {
        if (head != nullptr && head->next != nullptr)
        {
            ListNode *preTail = head;
            while (preTail->next->next != nullptr) { preTail = preTail->next; }
            if (preTail != head)
            {
                preTail->next->next = head->next;
                head->next = preTail->next;
                preTail->next = nullptr;
                reorderList(head->next->next);
            }
        }
    }
};
