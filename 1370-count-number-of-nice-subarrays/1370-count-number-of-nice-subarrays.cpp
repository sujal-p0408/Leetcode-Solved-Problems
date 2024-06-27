class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int x=solve(nums,k);
        int y=solve(nums,k-1);
        cout<<x<<" "<<y<<endl;
        return x-y;
    }

    int solve(vector<int>& nums, int k)
    {
        int n=nums.size();
        int l=0;
        int r=0;
        int Oddcnt=0;
        int ans=0;
        
        if(k<0) return 0;
        while(r<n)
        {
            if(nums[r]&1) Oddcnt++;

            while(Oddcnt>k)
            {
                if(nums[l]&1) Oddcnt--;
                l++;
            }
            
            if(Oddcnt<=k)
            ans+=r-l+1;

            r++;
        }

        return ans;
    }
};