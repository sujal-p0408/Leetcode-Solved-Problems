class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=k;
        
        int l=0;
        int r=0;
        
        int maxi=0;
        while(r<n)
        {
            if(nums[r]==1)
            {
                maxi=max(maxi,r-l+1);
                 r++;
            }

            else if(nums[r]==0 && cnt)
            {
                cnt--;
                maxi=max(maxi,r-l+1);
                 r++;
            }

            else
            {
                l++;
                r=l;
                cnt=k;
            }
        }

        return maxi;
    }
};