/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) 
    {
        Node* res{nullptr};
        if (node)
        {
            map<int, Node*> mapNodes{};
            queue<Node*> queueNodes{};
            queueNodes.push(node);
            while (!queueNodes.empty())
            {
                Node *origin = queueNodes.front();
                queueNodes.pop();
                if (mapNodes.find(origin->val) == mapNodes.end()) { mapNodes[origin->val] = new Node(origin->val); }
                for (auto &neighbor : origin->neighbors)
                {
                    if (mapNodes.find(neighbor->val) == mapNodes.end()) 
                    { 
                        mapNodes[neighbor->val] = new Node(neighbor->val); 
                        queueNodes.push(neighbor);
                    }
                    mapNodes[origin->val]->neighbors.push_back(mapNodes[neighbor->val]);

                }
            }
            res = mapNodes[1];
        }

        return res;
    }
};
