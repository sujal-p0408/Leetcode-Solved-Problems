class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int l=1;
        int r=n-2;
        int mid;
        int maxi=*max_element(nums.begin(),nums.end());
        if(n==1) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;
        if(nums[0]>nums[1]) return 0;

        while(l<=r)
        {
          mid=(l+r)/2;
          if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
          return mid;
          
        //   if mid is not peak then either it's right element or left element can be peak
        //   ex. 3,2,1 here mid is 2 but not peak hence peak can be 1 or 3 (here 3 is greater hance shifted there)
          else if(nums[mid+1]>nums[mid]) l=mid+1; 
          else if(nums[mid-1]>nums[mid]) r=mid-1;
    }
   return 0;
    } 
};