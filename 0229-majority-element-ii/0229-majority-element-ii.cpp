class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        map<int,int> mp;
        int mini=n/3;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]] > mini)
            {
                if(ans.size()==0) ans.push_back(nums[i]);
                else if(ans[0]!=nums[i]) ans.push_back(nums[i]);
            }

            if(ans.size()==2) break;
        }

        return ans;
    }
};