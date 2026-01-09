/*
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
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;

        queue<Node*> q;
        map<Node*, Node*> m;

        Node* head = new Node();
        head->val = node->val;
        m[node] = head;
        q.push(node);

        while (!q.empty()) {
            Node* next = q.front();
            q.pop();
            for (auto n : next->neighbors) {
                if (m.find(n) == m.end()) {
                    Node* c = new Node();
                    c->val = n->val;
                    m[n] = c;
                    q.push(n);
                }
                m[next]->neighbors.push_back(m[n]);
            }
        }
        return head;
    }
};
