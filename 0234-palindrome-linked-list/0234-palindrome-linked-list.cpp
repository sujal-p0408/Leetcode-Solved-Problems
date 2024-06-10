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
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        ListNode* temp=head;

        while(temp!=NULL)
        {
            arr.push_back(temp->val);
            temp=temp->next;
        }
      
      vector<int> arr_old=arr;
      reverse(arr.begin(),arr.end());
      if(arr_old==arr) return true;
      return false;
    }
};