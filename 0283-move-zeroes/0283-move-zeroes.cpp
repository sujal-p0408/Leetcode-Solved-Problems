class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int j=0;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=0) arr[j]=arr[i],j++;
        }
        for(int i=j;i<n;i++)
        {
            arr[i]=0;
        }
    }
};