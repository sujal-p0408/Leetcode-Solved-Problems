class Solution {
public:
    long long solve(vector<int>& piles,int hours)
    {
        long long total=0;
      for(auto x:piles)
      {
        total+=ceil((double)x/(double)hours);
      }
      
      cout<<total<<" ";
      return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        int ans;
        while(l<=r)
        {
            int mid =(l+r)/2;
            long long hours=solve(piles,mid);
         
            if(hours<=h)
            {
              ans=mid;
              r=mid-1;
            }

            else l=mid+1;
        }

        return ans;
    }
};