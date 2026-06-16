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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *res{nullptr};
        ListNode *temp{nullptr};
        while (list1 != nullptr || list2 != nullptr)
        {
            ListNode **list12{nullptr};
            if (list1 == nullptr) { list12 = &list2; }
            else if (list2 == nullptr)  { list12 = &list1; }
            else
            {         
                list12 = (list1->val <= list2->val)? &list1 : &list2; 
            }
            if (temp == nullptr)
            {
                temp = *list12;
                res = temp;
            }
            else
            {     
                temp->next = *list12;     
                temp = temp->next;   
            }
            *list12 = (*list12)->next;
        }

        return res;
    }
};
