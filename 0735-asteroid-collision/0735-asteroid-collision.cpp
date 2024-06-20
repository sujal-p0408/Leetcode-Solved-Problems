class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {

        int n=arr.size();
        
        stack<int> st;

        for(int i=0;i<n;i++)
        {
            if(st.empty() || arr[i]>0) st.push(arr[i]);

            else
            {
                while(!st.empty() && st.top()>0 && abs(arr[i])>st.top())
                st.pop();

                if(!st.empty() && abs(arr[i]) == st.top()) st.pop();

                else if(st.empty() || st.top() < 0) {
                        st.push(arr[i]);
                    }
            }
        }

        
        int st_n=st.size();
        vector<int> ans(st_n);
    for(int i=st_n-1;i>=0;i--)
    {
        ans[i]=st.top();
        st.pop();
    }

    return ans;
    }
};