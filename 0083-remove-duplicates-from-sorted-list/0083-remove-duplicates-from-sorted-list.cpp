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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *temp=head;
        set<int>st;
        while (temp!=NULL) {
            st.insert(temp->val);
            temp=temp->next;
        }
        ListNode *head1=NULL, *tail;
        for (auto it: st) {
            ListNode *newNode=new ListNode(it);
            if (head1==NULL) {
                head1=newNode; tail=newNode;
            }
            else {
                tail->next=newNode;
                tail=newNode;
            }
        }
        return head1;
    }
};