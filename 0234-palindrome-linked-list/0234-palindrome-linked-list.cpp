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
ListNode* reverseLinkedList(ListNode* head) {
    // Base case:
    // If the linked list is empty or has only one node,
    // return the head as it is already reversed.
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    // Recursive step:
    // Reverse the linked list starting 
    // from the second node (head->next).
    ListNode* newHead = reverseLinkedList(head->next);
    
    // Save a reference to the node following
    // the current 'head' node.
    ListNode* front = head->next;
    
    // Make the 'front' node point to the current
    // 'head' node in the reversed order.
    front->next = head;
    
    // Break the link from the current 'head' node
    // to the 'front' node to avoid cycles.
    head->next = NULL;
    
    // Return the 'newHead,' which is the new
    // head of the reversed linked list.
    return newHead;
}
    bool isPalindrome(ListNode* head) {
       ListNode* slow=head;
       ListNode* fast=head;

       while(fast->next!=NULL && fast->next->next!=NULL)
       {
        slow=slow->next;
        fast=fast->next->next;
       }

       ListNode* newHead = reverseLinkedList(slow->next);

       ListNode* first=head;
       ListNode* second=newHead;

       while(second!=NULL)
       {
        if(first->val != second->val) return 0;
        first=first->next;
        second=second->next;
       }

       return true;
    }
};