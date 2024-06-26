class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=0;
        
        int maxi_len=0;
        while(r<n)
        {
            if(nums[r]==1)
            {
                maxi_len=max(maxi_len,r-l+1);
            }

            else
            {
                l=r+1;
            }
            r++;
        }

        return maxi_len;
    }
};