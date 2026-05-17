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
    ListNode* addTwoNumbers(ListNode* linkedList1, ListNode* linkedList2) {
        ListNode *t1=linkedList1,*t2=linkedList2,*newNode,*head=NULL,*tail;
        int carry=0;
        while (t1!=NULL && t2!=NULL) {
            int cal=t1->val+t2->val+carry;
            newNode=new ListNode(cal%10);
            if (head==NULL) {
                head=newNode;   tail=newNode;
            }
            else {
                tail->next=newNode;
                tail=tail->next;;
            }
            if (cal>9) carry=1;
            else carry=0;
            t1=t1->next;    t2=t2->next;
        }
        while (t1!=NULL) {
            int cal=t1->val+carry;
            newNode=new ListNode(cal%10);
            tail->next=newNode;
            tail=tail->next;
            if (cal>9) carry=1;
            else carry=0;
            t1=t1->next;
        }
        while (t2!=NULL) {
            int cal=t2->val+carry;
            newNode=new ListNode(cal%10);
            tail->next=newNode;
            tail=tail->next;
            if (cal>9) carry=1;
            else carry=0;
            t2=t2->next;
        }
        if (carry==1) {
            newNode=new ListNode(1);
            tail->next=newNode;
        }
        return head;
    }
};