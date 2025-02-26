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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        int cnt1=0,cnt2=0;

        while(temp1!=NULL)
        {
            temp1=temp1->next;
            cnt1++;
        }
        while(temp2!=NULL)
        {
            temp2=temp2->next;
            cnt2++;
        }
        cout<<cnt1<<" "<<cnt2<<endl;
        int diff=abs(cnt1-cnt2);
         cout<<diff<<endl;
        if(cnt1>cnt2)
        {
            while(diff--)
            {
                headA=headA->next;
            }
        }

        else
        {
           while(diff--)
            {
                headB=headB->next;
            }
        }

        while(headA!=headB)
        {
            headA=headA->next;
            headB=headB->next;
        }

        
        return headA;
    }
};