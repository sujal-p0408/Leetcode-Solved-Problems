class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> umap;
        for(auto i: s) umap[i]++;

        vector<string> bucket(s.size()+1,"");

        for(auto i: umap)
        {
            bucket[i.second].push_back(i.first);
        }

        string ans;
        for(int i=s.size();i>=1;i--)
        {
            if (!bucket[i].empty()) {   // Check if the bucket is not empty
                for(auto ch: bucket[i]) {
                    ans.append(i, ch); // Append the character i times
                }
            }
        }

        return ans;
    }
};