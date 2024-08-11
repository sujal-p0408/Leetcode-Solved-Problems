class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n=arr.size();
        int idx=-1;
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i]<arr[i+1]) 
            {
                idx=i;
                break;
            }
        }

if(idx==-1)
{
    sort(arr.begin(),arr.end());
//    reverse(arr.begin(),arr.end());
    return;
}
        for(int i=n-1;i>=0;i--)
        {
            if(arr[i]>arr[idx])
            {
                swap(arr[i],arr[idx]);
                break;
            }
        }

        sort(arr.begin()+idx+1,arr.end());
    }
};