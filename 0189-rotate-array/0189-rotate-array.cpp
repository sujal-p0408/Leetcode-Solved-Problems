class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
         if (n == 0)
    return;
  k = k % n;
  if (k > n)
    return;
        int rotate=n-k;
        reverse(nums.begin(),nums.begin()+rotate);
        reverse(nums.begin()+rotate,nums.end());
        reverse(nums.begin(),nums.end());
    }
};