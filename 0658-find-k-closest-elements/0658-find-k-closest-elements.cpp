class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        vector<int> ans;
        priority_queue<pair<int,int>> maxHeap;
        for(int i=0;i<n;i++)
        {
            maxHeap.push({abs(arr[i]-x), arr[i]});
            if(maxHeap.size()>k) maxHeap.pop();
        }

        while(maxHeap.size())
        {
          ans.push_back(maxHeap.top().second);
          maxHeap.pop();
        }
        sort(ans.begin(),ans.end());

        return ans;
        
    }
};