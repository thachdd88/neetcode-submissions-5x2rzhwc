/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *newHead{nullptr};
        if (head != nullptr)
        {
            map<Node*, Node*> copyMap{};      
            Node *newNode = new Node(head->val);  
            newHead = newNode;
            copyMap[nullptr] = nullptr;
            copyMap[head] = newHead;
            Node *iter = head->next;
            while (iter != nullptr)
            {
                newNode->next = new Node(iter->val);
                copyMap[iter] = newNode->next;
                newNode = newNode->next;
                iter = iter->next;
            }

            iter = head;
            newNode = newHead;
            while (iter != nullptr)
            {         
                newNode->random = copyMap[iter->random];
                iter = iter->next;
                newNode = newNode->next;
            }
        }
        return newHead;
    }
};
