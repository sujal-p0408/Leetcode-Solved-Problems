class Solution {
public:
    vector<int> sieve(int n)
{
  vector<bool>isPrime(n+1,true);
  vector<int> v;
  
  isPrime[0]=true;
  isPrime[1]=true;

  for(int i=2;i*i<=n;i++)  // marking T=Prime, F=Not Prime
  {
    if(isPrime[i])
    {
        for(int j=i*i;j<=n;j=j+i)
        {
          isPrime[j]=false;
        }
    }
  }

  for(int i=2;i<=n;i++) //pushing all trues to the array
  {
    if(isPrime[i]) v.push_back(i);
  }
  return v;
 
 
}
    int nonSpecialCount(int l, int r) {
        int total=r-l+1;
        int sqroot=sqrt(r);
        vector<int> prime= sieve(sqroot);
     
        int cnt=0;
   for(int i=0;i<prime.size();i++)
   {
    // cout<<v[i]<<" ";
    int sqr= prime[i]*prime[i];
    if(l<=sqr && sqr<=r) cnt++;
   
   }

   return total-cnt;
    }
};