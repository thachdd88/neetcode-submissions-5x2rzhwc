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
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        ListNode* final{nullptr};
        ListNode* tail{nullptr};

#if 1
        bool allNull = false;
        while (!allNull)
        {
            ListNode *minNode{nullptr};
            int minIdx{-1};
            for (int i = 0; i < lists.size(); i++)
            {
                if (lists[i] != nullptr)
                {
                    if (minNode == nullptr || minNode->val >= lists[i]->val)
                    {
                        minIdx = i;
                        minNode = lists[i];
                    }
                }
            }
            if (minNode == nullptr) { allNull = true; }
            else
            {
                lists[minIdx] = lists[minIdx]->next;
                minNode->next = nullptr;
                if (tail == nullptr)
                {
                    final = minNode;
                    tail = final;
                }
                else
                {
                    tail->next = minNode;
                    tail = tail->next;
                }
            }
        }
#else
        for (int i = 0; i < lists.size(); i++)
        {
            ListNode *listHead = lists[i];
            while (listHead != nullptr)
            {
                ListNode *node = listHead;
                listHead = listHead->next;
                final = insertNode(final, node);
            }
        }
#endif
        return final;
    }
    ListNode *insertNode(ListNode *head, ListNode *node)
    {
        if (head == nullptr || head->val >= node->val)
        {
            node->next = head;
            head = node;
        }
        else
        {
            ListNode *iter{head};
            while (iter->next != nullptr && iter->next->val < node->val) { iter = iter->next; }

            node->next = iter->next;
            iter->next = node;
        }
        return head;
    }
};
