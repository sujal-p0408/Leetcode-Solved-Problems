class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n=t.size();
        stack<pair<int,int>> st;
        vector<int> NGR(n,0);

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top().first<=t[i]) st.pop();

            if(!st.empty()) NGR[i]=st.top().second;

            st.push({t[i],i});
        }
      for(int i=0;i<n;i++)
      {
        if(NGR[i]) NGR[i]-=i;
      }

      return NGR;
    }
};