class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int>freq,end;
        for(auto x:nums)
            freq[x]++;
        for(auto x:nums){
            if(freq[x]==0)continue;
            freq[x]--;
            if(end[x-1]>0)
            {
                end[x-1]--;
                end[x]++;
            }
            else if(freq[x+1]>0&&freq[x+2]>0){
                freq[x+1]--;
                freq[x+2]--;
                end[x+2]++;
            }
            else
                return false;
        }
        return true;
    }
};