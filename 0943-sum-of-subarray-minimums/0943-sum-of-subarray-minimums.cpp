class Solution {
public:
const int MOD=1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> left(n,0), right(n,0);
        stack<pair<int,int>> leftSt;
        stack<pair<int,int>> rightSt;

        for(int i=0;i<n;i++)
        {
            int cnt=1;
            while(!leftSt.empty() && leftSt.top().first>arr[i])
            {
                cnt+=leftSt.top().second;
                leftSt.pop();
            }
            
            left[i]=cnt;
            leftSt.push({arr[i],cnt});
        }

        for(int i=n-1;i>=0;i--)
        {
            int cnt=1;
            while(!rightSt.empty() && rightSt.top().first>=arr[i])
            {
                cnt+=rightSt.top().second;
                rightSt.pop();
            }
            
            right[i]=cnt;
            rightSt.push({arr[i],cnt});
        }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans=(ans+(arr[i]*(1LL)*(left[i]*right[i])%MOD)%MOD)%MOD;
    }
    return ans;
    }
};