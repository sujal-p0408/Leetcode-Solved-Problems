class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> PrefSum(n);
        PrefSum[0]=nums[0];
        for(int i=1;i<n;i++)
        { 
           PrefSum[i]=PrefSum[i-1]+nums[i];
        }


        return PrefSum;
    }
};