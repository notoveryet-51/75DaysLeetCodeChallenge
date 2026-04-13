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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp,*prev=NULL;
        temp=head;
        int count=1;
        while (temp->next!=NULL) {
            temp=temp->next;    count++;
        }
        if (count==1)   {
            head=NULL; return head;
        }
        n=count-n+1;    count=1;
        temp=head;
        if (n==1)   return head->next;
        while (count<n) {
            prev=temp;
            temp=temp->next;
            count++;
        }
        prev->next=temp->next;
        return head;
    }
};