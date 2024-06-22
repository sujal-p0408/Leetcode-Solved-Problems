class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMax(nums)- sumSubarrayMins(nums);
    }
    long long sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<long long> left(n,0), right(n,0);
        stack<pair<long long,long long>> leftSt;
        stack<pair<long long,long long>> rightSt;

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
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        ans=(ans+( arr[i]*(1LL)*(left[i]*right[i])));
    }
    return ans;
    }

    long long sumSubarrayMax(vector<int>& arr) {
        int n=arr.size();
       vector<long long> left(n,0), right(n,0);
        stack<pair<long long,long long>> leftSt;
        stack<pair<long long,long long>> rightSt;
        for(int i=0;i<n;i++)
        {
            int cnt=1;
            while(!leftSt.empty() && leftSt.top().first<arr[i])
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
            while(!rightSt.empty() && rightSt.top().first<=arr[i])
            {
                cnt+=rightSt.top().second;
                rightSt.pop();
            }
            
            right[i]=cnt;
            rightSt.push({arr[i],cnt});
        }
     long long ans=0;
    for(int i=0;i<n;i++)
    {
        ans=(ans+( arr[i]*(1LL)*(left[i]*right[i])));
    }
    return ans;
    }
};