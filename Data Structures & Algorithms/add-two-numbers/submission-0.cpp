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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *iter1 = l1;
        ListNode *iter2 = l2;
        ListNode *res{nullptr};
        ListNode *iterRes{nullptr};

        int temp = 0;
        while (iter1 != nullptr || iter2 != nullptr || temp != 0)
        {
            int num1 = (iter1 != nullptr)? iter1->val : 0;
            int num2 = (iter2 != nullptr)? iter2->val : 0;
            if (iterRes == nullptr) { iterRes = new ListNode((num1+num2+temp)%10); res = iterRes; }
            else {iterRes->next = new ListNode((num1+num2+temp)%10); iterRes = iterRes->next; }
            temp = (num1+num2+temp)/10;
            if (iter1 != nullptr) { iter1 = iter1->next;  }
            if (iter2 != nullptr) { iter2 = iter2->next;  }
        }

        return res;
    }
};
