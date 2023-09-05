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

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head) return head;

        Node *temp = head;

        size_t len;
        for (len = 0; temp; len++)
            temp = temp->next;

        unordered_map<Node *, Node *> save;
        Node *new_head = new Node(0), *cur = new_head;
        save[head] = cur;
        *cur = *head;
        head = head->next;

        for (size_t i = 1; i < len; i++)
        {
            cur->next = new Node(0);
            cur = cur->next;
            save[head] = cur;
            *cur = *head;
            head = head->next;
        }

        cur = new_head;

        for (size_t i = 0; i < len; i++)
        {
            if (cur->random != nullptr)
                cur->random = save[cur->random];
            cur = cur->next;
        }

        return new_head;
    }
};