class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
         int cnt1 = 0;
         int cnt2 = 0;
        int cand1 = 0;
        int cand2 = 0;
        vector<int> ans;
        for (int num : nums) {
            if (cnt1 == 0 && num!=cand2) {
                cnt1=1;
                cand1 = num;
            }

           else if (cnt2 == 0 && num!=cand1) {
            cnt2=1;
                cand2 = num;
            }
            
            else if (num == cand1) {
                cnt1++;
            }
            
            else if (num == cand2) {
                cnt2++;
            }
             else {
                cnt1--,cnt2--;
            }
        }
        cnt1=0,cnt2=0;
        int mini=nums.size()/3+1;
       for(int i=0;i<nums.size();i++)
       {
        if(nums[i]==cand1) cnt1++;
        else if(nums[i]==cand2) cnt2++;
       }

       if(cnt1>=mini) ans.push_back(cand1);
       if(cnt2>=mini) ans.push_back(cand2);
  
  return ans;
    }
};