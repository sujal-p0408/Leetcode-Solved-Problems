class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> ans={-1,-1};

        if (n == 0) {
            return ans; // Handle the case when the input vector is empty.
        }

        int lb=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int ub=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
     
     
     if(lb==n || nums[lb]!=target)
    {
        return ans;
    }

      return {lb,ub-1};
    }
};