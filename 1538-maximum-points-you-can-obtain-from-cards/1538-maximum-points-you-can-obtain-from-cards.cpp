class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
         int n=nums.size();
         
        for(int i=0;i<k;i++)
        {
            nums.push_back(nums[i]);
        }
        
       
        int l=n-k;
        int r=l+k-1;
        int sum=0;

        for(int i=l;i<=r;i++)
        {
            sum+=nums[i];
        }
        
        n=nums.size();
        int res=sum;

        while(r<n-1)
        {
          sum-=nums[l];
          l++;
          r++;
          sum+=nums[r];

          res=max(res,sum);
        }

        return res;
    }
};