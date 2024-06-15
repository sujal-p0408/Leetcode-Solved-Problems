class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int,int> umap;

        for(int i=nums2.size()-1;i>=0;i--)
        {
            int ele=nums2[i];
            while(!s.empty() && s.top()<=ele) s.pop();

            int res= (s.empty()) ? -1: s.top();
            umap.insert({ele,res});

            s.push(ele);
        }

        vector<int> ans;
        for(auto x: nums1)
        {
            ans.push_back(umap[x]);
        }

        return ans;
    }
};