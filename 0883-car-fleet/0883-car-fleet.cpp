class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> pos;
        int n=position.size();
        for(int i=0;i<n;i++)
        {
            double time=(double) (target-position[i])/speed[i];
            pos.push_back({position[i],time});
        }
        sort(pos.begin(),pos.end());
        
        int cnt=0;
        double maxi=-1.0;
        for(int i=n-1;i>=0;i--)
        {
            if(pos[i].second>maxi) {
                maxi=pos[i].second;
                cout<<maxi<<" ";
                cnt++;
            }
        }
        return cnt;
    }
};