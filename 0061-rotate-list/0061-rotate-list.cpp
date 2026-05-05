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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return head;

        auto temp = head;

        int cnt;
        for (cnt = 0; temp->next; cnt++)
            temp = temp->next;

        auto final_one = temp;

        k %= cnt + 1;
        k = cnt - k;
        temp = head;
        final_one->next = head;

        while (k--)
            temp = temp->next;

        head = temp->next;
        temp->next = nullptr;

        return head;
    }
};