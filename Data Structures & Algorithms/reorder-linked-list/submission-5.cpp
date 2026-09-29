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
private:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *prev = nullptr;
        ListNode *curr = head;

        while (curr) {
            ListNode *next = curr->next;

            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

public:
    void reorderList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow is now at the halfway point
        // reverse everything from slow onwards

        ListNode *first = head;
        ListNode *second = reverseList(slow->next);
        slow->next = nullptr;

        while (first || second) {
            if (first && second) {
                ListNode *real_first_next = first->next;
                ListNode *real_second_next = second->next;
                first->next = second;
                second->next = real_first_next;
                first = real_first_next;
                second = real_second_next;
            } else if (first) {
                break;
            } else {
                first->next = second;
            }
        }
    }
};
