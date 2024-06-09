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
        ListNode* fast=head;
        ListNode* slow=head;

        while(n)
        {
            n--;
            fast=fast->next;
        }
         if(fast==NULL)  //when n==size of LL then and it wants to delete the first node
         {
         return head->next;
         }
        while(fast->next!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
        
        ListNode* temp=slow->next;
        slow->next=temp->next;
        delete temp;

        return head;
    }
};