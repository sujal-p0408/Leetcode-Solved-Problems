class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        int n=hand.size();
        if(n%k!=0) return false;
        priority_queue<int,vector<int>, greater<int>> minHeap;

        for(int i: hand)
        {
            minHeap.push(i);
        } 
       int prev=-1, curr=0;
        vector<int> temp;
       while(!minHeap.empty())
       {
        int t=minHeap.top();
        minHeap.pop();

         if(prev==-1 || t-prev==1)
         {
            prev=t;
            curr++;
         }

         else
         {
            temp.push_back(t);
         }

         if(curr==k)
         {
            prev=-1;
            curr=0;

            for(auto i: temp)
            {
                minHeap.push(i);
            }

            temp={};
         }
       }

       return !(curr>0);
    }
};