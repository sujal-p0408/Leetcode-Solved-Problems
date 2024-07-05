class Solution {
public:
    int mySqrt(int x) {
        int l=1;
        int r=x;
        int ans=r;
        while(l<=r)
        {
            long long mid=l+(r-l)/2;
            long long  val=mid*mid;
            if(val<= (long long) x)
            {
              ans=mid;
              l=mid+1;
            }

            else r=mid-1;
        }

        return ans;
    }
};