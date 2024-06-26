class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        int x=solve(nums,k);
        int y=solve(nums,k-1);
        cout<<x<<" "<<y<<endl;
        return x-y;
    }

    int solve(vector<int>& nums, int k)
    {
        if(k<0) return 0;
      int n=nums.size();
      int l=0;
      int r=0;
      int sum=0;
      int cnt=0;

      while(r<n)
      {
        sum+=nums[r];
        
        while(sum>k)
        {
            sum-=nums[l];
            l++;
        }

        cnt+=r-l+1;
        r++;
      }

      return cnt;
    }
};