/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
         if(head==NULL || head->next==NULL) return NULL;

        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast)  {slow=head;
            break;
            }
        }
        while(slow!=fast)
        {
            if(slow->next) slow=slow->next;
            if(fast->next) fast=fast->next;
        }
        if(slow==fast && fast->next!=NULL && fast->next->next!=NULL) return slow;
        return NULL;
    }
};