class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[ans])
            {
                ans=i;
            }
        }

        return ans;
    }
};