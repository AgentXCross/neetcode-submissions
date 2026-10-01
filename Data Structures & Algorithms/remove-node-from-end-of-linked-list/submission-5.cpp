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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode dummy{0, head};

        ListNode *slow{&dummy};
        ListNode *fast{&dummy};

        // have fast always be n nodes ahead of slow
        for (int i{0}; i < n; ++i) {
            fast = fast->next;
        }

        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode *to_remove{slow->next};
        slow->next = slow->next->next;

        if (to_remove == head) {
            return head->next;
        } else {
            return head;
        }
    }
};
