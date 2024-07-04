class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];

        int l=1;
        int r=n-2;
        int mid;

        while(l<=r)
        {
            mid=(l+r)/2;

            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
            return nums[mid];
            if(mid%2!=0 && nums[mid]==nums[mid+1]) r=mid-1;
            else if(mid%2==0 && nums[mid]==nums[mid-1]) r=mid-2;
            else if(mid%2==0 && nums[mid]==nums[mid+1]) l=mid+2;
            else if(mid%2!=0 && nums[mid]==nums[mid-1]) l=mid+1;
        }
        return 0;
    }
};