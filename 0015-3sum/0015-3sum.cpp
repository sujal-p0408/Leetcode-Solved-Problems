class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            int j=i+1;
            int k=n-1;

            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k];

                if(sum==0)
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(j<k && nums[j]==nums[j+1]) j++;
                    if(j<k) j++;
                    while(j<k && nums[k]==nums[k-1]) k--;
                   if(j<k) k--;
                }

                if(sum<0)
                {
                    while(j<k && nums[j]==nums[j+1]) j++;
                   if(j<k) j++;
                }

                 if(sum>0)
                {
                    while(j<k && nums[k]==nums[k-1]) k--;
                  if(j<k)  k--;
                }
            }

            while(i<n-1 && nums[i]==nums[i+1]) i++;
        }

        return ans;
    }
};