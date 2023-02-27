/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return combine(0, 0, grid.size(), grid);
    }
    
    Node* combine(int x, int y, int n, vector<vector<int>>& grid) {
        if(n == 1) {
            return new Node(grid[x][y], true);
        }
        else {
            Node *tl, *tr, *bl, *br;
            tl = combine(x, y, n / 2, grid);
            tr = combine(x, y + n / 2, n / 2, grid);
            bl = combine(x + n / 2, y, n / 2, grid);
            br = combine(x + n / 2, y + n / 2, n / 2, grid);
            
            if(tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf && tl->val == tr->val && tr->val == bl->val && bl->val == br->val) {
                delete tl, tr, bl, br;
                return new Node(grid[x][y], true);
            }
            else {
                return new Node(1, false, tl, tr, bl, br);
            }
        }
    }
};