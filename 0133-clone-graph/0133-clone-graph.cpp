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

class Solution
{
public:
    unordered_map<Node *, Node *> is_gone;
    
    Node *cloneGraph(Node *node)
    {
        if (node == nullptr || is_gone.count(node))
            return is_gone[node];

        Node *new_node = new Node(node->val);
        is_gone[node] = new_node;

        for (auto &&i : node->neighbors)
            new_node->neighbors.push_back(cloneGraph(i));

        return new_node;
    }
};