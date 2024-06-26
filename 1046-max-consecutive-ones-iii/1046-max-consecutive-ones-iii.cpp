class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int r=0;
        
        int max1s=0;
        int cntZero=0;

        while(r<n)
        {
          if(nums[r]==0) cntZero++;
        
          if(cntZero > k)  // If zero count exceeds k, shrink the window from the left till it comes in the range of 0's
          {
            if(nums[l]==0) cntZero--;
            l++;
          }
          
         else max1s=max(max1s,r-l+1); // max1s get increases only if we get new bigger window
          r++;
        }
        return max1s;
    }
};