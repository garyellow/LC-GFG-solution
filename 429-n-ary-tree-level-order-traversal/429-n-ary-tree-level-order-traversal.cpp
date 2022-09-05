/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        
        if(root)
        {
            queue<Node*> bfs({root});

            while(bfs.size())
            {
                vector<int> temp;
                for(int n = bfs.size(); n--;)
                {
                    temp.push_back(bfs.front()->val);

                    for(auto && c : bfs.front()->children)
                        bfs.push(c);

                    bfs.pop();
                }

                ans.push_back(temp);
            }
        }
        
        return ans;
    }
};