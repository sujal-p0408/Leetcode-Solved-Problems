class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> umap;
        // int n=s.length();

        for(auto i: s) umap[i]++;
        
        vector<pair<char,int>> v;

        for(auto& [c,freq] : umap)  v.push_back(make_pair(c, freq));
        sort(v.begin(),v.end(), [&](auto a, auto b) 
        {
            return a.second>b.second;
        });


        string ans;
        for (auto& [c, freq] : v)
            ans.append(freq, c);
        return ans;

    }
};