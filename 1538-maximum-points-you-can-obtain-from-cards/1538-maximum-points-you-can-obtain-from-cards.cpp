class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n=nums.size();
        int leftsum=0;
        for(int i=0;i<k;i++)
        {
           leftsum+=nums[i];
        }
        int r=n-1;
        int res=leftsum;
        for(int i=k-1;i>=0;i--)
        {
          leftsum-=nums[i];
          leftsum+=nums[r];
          r--;

          res=max(res,leftsum);
        }

        return res;
    }
};