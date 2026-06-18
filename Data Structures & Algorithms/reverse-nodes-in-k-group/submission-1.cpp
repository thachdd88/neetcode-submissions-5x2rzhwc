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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *localHead = new ListNode(-1, nullptr);
        ListNode *final{localHead};        
        ListNode *tail{final};
        int idx{0};
        while (head != nullptr)
        {
            ListNode *node = head;
            head = head->next;

            node->next = localHead->next;
            localHead->next = node;

            if (idx == 0) { tail = node; }
            if (idx == k-1) { localHead = tail; }
            
            idx = (idx+1) % k;
        }
        if (idx < k)
        {
            for (int i = 0; i < idx-1; i++)
            {
                ListNode *node = localHead->next;
                localHead->next = node->next;
                node->next = nullptr;
                tail->next = node;
                tail = node;
            }
        }
        localHead = final;
        final = final->next;
        delete localHead;
        
        return final;
    }
};
