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
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) return;
        ListNode *slow = head, *fast = head, *temp;
        // Step 1: find middle
        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // Step 2: split and reverse second half
        temp = slow->next;
        slow->next = NULL;
        ListNode *prev = NULL, *curr = temp, *next;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // Step 3: merge two halves
        ListNode *first = head;
        ListNode *second = prev;
        while (second != NULL) {
            ListNode *t1 = first->next;
            ListNode *t2 = second->next;
            first->next = second;
            second->next = t1;
            first = t1;
            second = t2;
        }
    }
};