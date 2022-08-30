class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        
        int n=mat.size();
        
     if(mat==target)
         return true;
        
        
        for(int k=0;k<3;k++){
             for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++)
                swap(mat[i][j],mat[j][i]);
        }
        for(int i=0;i<n;i++)
            reverse(mat[i].begin(),mat[i].end());
              if(mat==target)
        return true;
        }
       
  
            return false;
    }
    

};