class Solution {
public:
    int leastInterval(vector<char>& tasks, int k) {
    unordered_map<char,int> map;
    for(auto i: tasks)
    {
        map[i]++;
    }  
    priority_queue<int> maxHeap;
    for(auto i: map)
    {
        maxHeap.push(i.second);
    }   
    int ans=0;
    while(!maxHeap.empty())
    {
        vector<int> temp;
        for(int i=0;i<=k;i++)
        {
            if(!maxHeap.empty())
            {
                temp.push_back(maxHeap.top());
                maxHeap.pop();
            }
        }

        for(int i=0;i<temp.size();i++)
        {
            if(--temp[i]>0) maxHeap.push(temp[i]);
        }

        ans+= maxHeap.empty() ? temp.size() : k+1;
    }
      return ans;
    }
};