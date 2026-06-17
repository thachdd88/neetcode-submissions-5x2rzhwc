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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *preNode = dummy;
        ListNode *lastNode = head;
        for (int i = 0; i < n-1 && lastNode != nullptr; i++) { lastNode = lastNode->next; }
        if (lastNode != nullptr)
        {
            while (lastNode->next != nullptr)
            {
                preNode = preNode->next;
                lastNode = lastNode->next;
            }
            if (preNode->next == head)
            {
                head = head->next;
                delete preNode->next;
            }
            else
            {
                ListNode *tmp = preNode->next;
                preNode->next = tmp->next;
                delete tmp;
            }
        }

        delete dummy;
        return head;
    }
};
