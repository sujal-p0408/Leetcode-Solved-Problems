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
ListNode* removeK (ListNode* head, int k) {
if (head == NULL) return head;
if(k == 1) {
ListNode* temp = head;
 head=head->next;
delete temp;
return head;
}
int cnt = 0;
ListNode* temp = head;
ListNode* prev = NULL;
while(temp != NULL) {
cnt++;
if (cnt== k) {
prev->next = prev->next->next;
delete temp;
break;
}
prev = temp;
temp = temp->next;
}
return head;
}
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL) return NULL;
        int cnt=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            cnt++;
            temp=temp->next;
        }

        int new_n=cnt-n+1;
        
        return removeK(head,new_n);
    }
};