class Solution {
public:
    bool solve(vector<int>& arr,int n, int m,int mid)
    {
    int cnt=1;
    int sum=0;
    for(int i=0;i<n;i++)
    {
       sum+=arr[i];
       if(sum>mid)
       {
           cnt++;
           sum=arr[i];
       }
    //    if(stud_cnt==m) return true;
    }

    return (cnt>m);
    }
    int splitArray(vector<int>& arr, int m) {
    int n=arr.size();
    int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);

    while(low<=high)
    {
        int mid=(low+high)/2;

        // int stud=no_stud(arr,n,mid);

        if(solve(arr,n,m,mid)) low=mid+1;
        else high=mid-1;
    }
    //  cout<<low<<endl;
    return low;  
    }
};