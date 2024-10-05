class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> umap;
        for(int i=0;i<n;i++)
        {
            umap[nums[i]]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> minHeappair;
        for(auto i: umap)
        {
          minHeappair.push({i.second,i.first});
          if(minHeappair.size()>k) minHeappair.pop();
        }

        vector<int> ans;
        while(minHeappair.size())
        {
            ans.push_back(minHeappair.top().second);
            minHeappair.pop();
        }

        return ans;
    }
};