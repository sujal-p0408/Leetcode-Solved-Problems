class Solution {
public:
vector<int> findNSL(vector<int>& arr, int n)
    {
        stack<pair<int,int>> st;
        vector<int> ans(n,-1);
        int pseudoIndex=-1;
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && st.top().first>=arr[i])
            {
                st.pop();
            }
            
              if(!st.empty()) ans[i]=(st.top().second); 
              
              st.push({arr[i],i});
        }
        
    return ans;
    }
    
    vector<int> findNSR(vector<int>& arr, int n)
    {
        stack<pair<int,int>> st;
        
        int pseudoIndex=n;
        vector<int> ans(n,n);
        
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top().first>=arr[i])
            {
                st.pop();
            }
            
              if(!st.empty()) ans[i]=(st.top().second); 
              
              st.push({arr[i],i});
        }
        
    return ans;
    }
    int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
        vector<int> left=findNSL(arr, n);
        vector<int> right=findNSR(arr, n);
        
        vector<int> ans;
        
        int MaxArea=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            int curr_Area=arr[i]*(right[i]-left[i]-1);
            MaxArea=max(MaxArea,curr_Area);
        }
        
        return MaxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(); //rows
        if(n==0) return 0;
        int m=matrix[0].size(); //columns
        
        vector<int> v(m,0);
        // for(int j=0;j<m;j++)
        // {
        //    v.push_back(matrix[0][j]);
        // }
        int res=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='1')  v[j]+=1;

                else v[j]=0;
            }
            
        res=max(res,largestRectangleArea(v));
        // cout<<res<<" ";
        }
        
        return res;
    }
};