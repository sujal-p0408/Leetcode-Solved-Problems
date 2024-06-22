class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
                // number of operation greater than length we return an empty string
        if(num.length() <= k)   
            return "0";
        
        // k is 0 , no need of removing /  preforming any operation
        if(k == 0)
            return num;
            
        stack<char> st;
        string ans="";
        
        st.push(num[0]);
        for(int i=1;i<n;i++)
        {
            while(!st.empty() && k>0 && num[i]<st.top())
            {
                k--;
                st.pop();
            }
           
            st.push(num[i]);

            // popping preceding zeroes
            if(st.size() == 1 && num[i] == '0')
                st.pop();
        }

        while(k>0 && !st.empty()) st.pop(),k--;

        if(st.empty()) return "0";
        
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }

 reverse(ans.begin(),ans.end());
        return ans;
    }
};