class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int cnt_single=0;
        int cnt_double=0;

        for(int i=0;i<nums.size();i++)
        {
            string str=to_string(nums[i]);
            if(str.size()==1) cnt_single+=nums[i];
            else cnt_double+=nums[i];
        }

        if(cnt_single==cnt_double) return false;
        return true;
    }
};