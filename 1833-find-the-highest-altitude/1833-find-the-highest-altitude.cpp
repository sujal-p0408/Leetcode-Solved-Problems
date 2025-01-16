class Solution {
public:
    int largestAltitude(vector<int>& nums) {
        int n=nums.size()+1;
        vector<int> PrefSum(n);
        PrefSum[0]=0;
        // PrefSum[1]=nums[0];
        int maxi=0;
        for(int i=1;i<n;i++)
        { 
           PrefSum[i]=PrefSum[i-1]+nums[i-1];
           maxi=max(maxi,PrefSum[i]);
        }

        return maxi;
    }
};