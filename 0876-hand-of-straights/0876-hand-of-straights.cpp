class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        int n=hand.size();
        if(n%k!=0) return false;
        // priority_queue<int> 
        sort(hand.begin(),hand.end());
        while(!hand.empty())
        {
          int smallest=hand[0];
          for(int i=1;i<k;i++)
          {
            if (std::find(hand.begin(), hand.end(), smallest + i) == hand.end()) return false;
            else
            {
                auto it = std::find(hand.begin(), hand.end(), smallest+i); 
if (it != hand.end()) {
    hand.erase(it); 
}
            }
          }
          auto it = std::find(hand.begin(), hand.end(), smallest);
          hand.erase(it);

    }
    return true;
    }
};