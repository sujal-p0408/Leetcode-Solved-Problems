class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();

        priority_queue<pair<int,pair<int,int>>> pq;

        for(int i=0;i<n;i++)
        {
            // pq.push({(points[i][0]*points[i][0])+(points[i][1]*points[i][1])},{(points[i][0],points[i][1])});
            
             int dist = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
            
            // Push the distance and point into the priority queue
            pq.push({dist, {points[i][0], points[i][1]}});

            if(pq.size()>k)
            pq.pop();
        }
        vector<vector<int>> ans;
        while(pq.size())
        {
            pair<int,int> temp=pq.top().second;
            ans.push_back({temp.first,temp.second});
            pq.pop();
        }

        return ans;
    }
};