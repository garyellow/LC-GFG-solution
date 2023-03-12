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


class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        auto compare = [](ListNode *lhs, ListNode *rhs) { return lhs->val > rhs->val; };
        priority_queue<ListNode *, vector<ListNode *>, decltype(compare)> pq(compare);

        for (auto &&i : lists)
            if (i != nullptr)
                pq.push(i);

        if (pq.empty())
            return nullptr;

        ListNode *head = pq.top();
        if (pq.top()->next != nullptr)
            pq.push(pq.top()->next);
        
        pq.pop();

        for (ListNode *cur = head; pq.size(); cur = cur->next)
        {
            cur->next = pq.top();
            if (pq.top()->next != nullptr)
                pq.push(pq.top()->next);
            
            pq.pop();
        }

        return head;
    }
};