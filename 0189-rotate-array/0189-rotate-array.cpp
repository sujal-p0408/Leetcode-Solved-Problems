class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n=arr.size();
        if (n == 0)
    return;
  k = k % n;
  if (k > n)
    return;
  
  vector<int> temp(n);

  for(int i=0;i<k;i++)
  {
    temp[i]=arr[n-k+i];
  }

for(int i=k;i<n;i++)
{
    temp[i]=arr[i-k];
}

for(int i=0;i<temp.size();i++)
{
    arr[i]=temp[i];
}
    }
};