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
    ListNode* rotateRight(ListNode* head, int k) {

        if(head==NULL || head->next==NULL || k==0) return head;
        ListNode* temp=head;
        ListNode* tail=head;
        int n=1;

        while(tail->next!=NULL)
        {
            tail=tail->next;
            n++;
        }
        k%=n;
        if(k==0) return head;

        tail->next=head;
        // int traverse=n-k-1;
        // while(traverse)
        // {
        //     temp=temp->next;
        //     traverse--;
        // }
        for(int i=1;i<(n-k);i++)
        {
            temp=temp->next;
        }
        cout<<temp->val;
        head=temp->next;
        temp->next=NULL;

        return head;
    }
};