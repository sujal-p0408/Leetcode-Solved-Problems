class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
         int n=piles.size();
         long long sum =0;
         for(long long pile : piles){
            sum+=pile;
         }
         int mini = (sum+h-1)/h;
         //  int mini = ceil((double)sum/(double)h);
         int maxi=*max_element(piles.begin(),piles.end());
          
         int l=mini;
         int r=maxi;
         
        while (l <= r) {
            int k = (l + r) / 2;
            int t = 0;
            for (int pile : piles) {
                t += (pile + k - 1) / k;
            }
            if (t <= h) {
                r = k-1;
            } else {
                l = k + 1;
            }
        }
         return l;
        
    }
};