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

        ListNode *prev{nullptr};
        ListNode *curr{head};

        while (curr) {
            ListNode *next{curr->next};
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

        ListNode *slow{head};
        ListNode *fast{head};

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow is at the middle
        ListNode *first{head};
        ListNode *second{reverseList(slow->next)};

        slow->next = nullptr;

        while (second) {
            ListNode *temp_first{first->next};
            ListNode *temp_second{second->next};
            first->next = second;
            second->next = temp_first;
            first = temp_first;
            second = temp_second;
        }
    }
};
