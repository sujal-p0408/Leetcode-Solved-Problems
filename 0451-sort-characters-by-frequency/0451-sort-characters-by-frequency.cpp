class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> umap;
        for(auto i: s) umap[i]++;

        priority_queue<pair<int,char>> maxHeap;

        for(auto& it: umap)
        {
            maxHeap.push({it.second,it.first});
        }

        string ans;

        while(!maxHeap.empty())
        {
            ans.append(maxHeap.top().first,maxHeap.top().second);
            maxHeap.pop();
        }

        return ans;
    }
};