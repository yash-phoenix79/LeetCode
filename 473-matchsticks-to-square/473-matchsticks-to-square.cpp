class Solution {
public:
    
    bool ch(vector<int>ch){
        int t=ch[0];
        if(t!=ch[1]||t!=ch[2]||t!=ch[3])
            return false;
        return true;
    }
    
    bool check(int idx,vector<int>& mat,int tar,vector<int>side){
        
        if(idx==mat.size()){
            if(ch(side))
                return true;
            return false;
        }
        
        for(int i=0;i<4;i++){
            if(side[i]+mat[idx]>tar)
                continue;
            int j=i-1;
            while(j>=0){
                if(side[j]==side[i])
                    break;
                j--;
            }
            if(j!=-1)
                continue;
            side[i]+=mat[idx];
            if(check(idx+1,mat,tar,side))
                return true;
            side[i]-=mat[idx];
        }
        return false;
    }
    
    bool makesquare(vector<int>& mat) {
        
      int n=mat.size();
        if(n==0)
            return true;
        int sum=0;
        for(int i=0;i<mat.size();i++)
            sum+=mat[i];
        
        if(sum%4)
            return false;
        int tar=sum/4;
        
        vector<int>side(4,0);
        
        sort(mat.begin(),mat.end(),greater<int>());
        return check(0,mat,tar,side);
        
    }
};