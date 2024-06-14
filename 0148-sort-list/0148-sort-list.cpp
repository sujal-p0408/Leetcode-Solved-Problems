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
 ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* t1=list1;
    ListNode* t2=list2;
    ListNode* dummy_node = new ListNode(-1);
    ListNode* temp=dummy_node;
    
    while(t1!=NULL && t2!=NULL)
    {
        if((t1->val) <= (t2->val))
        {
            temp->next=t1;
            temp=t1;
            t1=t1->next;
            
        }
        else
        {
            temp->next=t2;
            temp=t2;
            t2=t2->next;
            
        }
    }
    if(t1)
    {
        temp->next=t1;
    }
    
    else 
    {
        temp->next=t2;
    }
    
    return dummy_node->next;
    }
 ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        // if(fast->next==NULL) return slow;
        return slow;
    }

    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* middle=middleNode(head);
        ListNode* leftHead=head;
        ListNode* rightHead=middle->next;
        middle->next=NULL;
        leftHead=sortList(leftHead);
        rightHead=sortList(rightHead);

        return mergeTwoLists(leftHead,rightHead);
    }
};