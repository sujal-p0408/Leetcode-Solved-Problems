class Solution {
public:
    string frequencySort(string s) {
        int umap[128]={0};
        
        for(auto i: s) umap[i]++;

        sort(s.begin(),s.end(), [&](char a, char b) 
        {
            return umap[a]>umap[b] || (umap[a]==umap[b] && a>b);
        });

        return s;
    }
};