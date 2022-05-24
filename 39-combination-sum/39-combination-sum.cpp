class Solution {
public:
    
    void findCombo(vector<int>& cand,vector<int>temp,int idx,int curSum,int target,vector<vector<int>>&res){
        if(curSum>target)
            return;
        if(curSum==target){
            res.push_back(temp);
            return;
        }
        
        for(int i=idx;i<cand.size();i++){
            temp.push_back(cand[i]);
            curSum+=cand[i];
            findCombo(cand,temp,i,curSum,target,res);
            curSum-=cand[i];
            temp.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        vector<vector<int>>res;
        vector<int>temp;
        int curSum=0;
        
        findCombo(cand,temp,0,curSum,target,res);
        return res;
    }
};