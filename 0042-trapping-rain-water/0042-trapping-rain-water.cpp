class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> left(n);
        vector<int> right(n);
        vector<int> maxHeight(n);

        int left_max=height[0];
        int right_max=height[n-1];

        for(int i=0;i<n;i++)
        {
        //   maxHeight[i]=min(left_max[i])
             left_max=max(left_max,height[i]);
             left[i]=left_max;
            //  cout<<left[i]<<" ";
        }
        // cout<<endl;
          for(int i=n-1;i>=0;i--)
        {
        //   maxHeight[i]=min(left_max[i])
             right_max=max(right_max,height[i]);
             right[i]=right_max;
            //  cout<<left[i]<<" ";
        }
//  cout<<endl;
        for(int i=0;i<n;i++)
        {
            maxHeight[i]=min(left[i],right[i])-height[i];
        }
    
        return accumulate(maxHeight.begin(),maxHeight.end(),0);
    }
};