class Solution {
public:
        bool check(vector<int>& A) {
            int cnt=0;
        for (int i = 0; i < A.size(); ++i)
           { if (A[i] > A[(i + 1) % A.size()])
                cnt++;
           }
        return cnt<=1;
    }
};