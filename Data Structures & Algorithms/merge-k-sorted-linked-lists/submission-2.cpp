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

        bool allNull = false;
        ListNode *minNode{nullptr};
        do
        {
            minNode = nullptr;
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
            if (minNode != nullptr)
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
        } while (minNode != nullptr);
        return final;
    }
};
