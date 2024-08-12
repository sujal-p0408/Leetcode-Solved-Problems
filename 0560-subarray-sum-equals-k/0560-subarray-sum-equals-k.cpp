class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> p_sum(n);
        p_sum[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            p_sum[i]=p_sum[i-1]+nums[i];
        }

        unordered_map<int,int> mp;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(p_sum[i]==k) cnt++;

            if(mp.find(p_sum[i]-k)!=mp.end())
            {
                cnt+=mp[p_sum[i]-k];
            }

            mp[p_sum[i]]++;
        }
        
        return cnt;
    }
};