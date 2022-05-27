class Solution {
public:
    vector<vector<string>> ans;
    
    bool check(int x,int y,vector<vector<char>>&Queens){
        int n=Queens.size();
        for(int i=0;i<n;i++){
            if(Queens[i][y]=='Q')return false;
        }
        
        int i=x,j=y;
        
        while(i<n&&j<n){
            if(Queens[i][j]=='Q')return false;
            i++,j++;
        }
        i=x,j=y;
        while(i<n&&j>=0){
            if(Queens[i][j]=='Q')return false;
            i++,j--;
        }
        i=x,j=y;
        while(i>=0&&j>=0){
            if(Queens[i][j]=='Q')return false;
            i--,j--;
        }
        i=x,j=y;
         while(i>=0&&j<n){
            if(Queens[i][j]=='Q')return false;
            i--,j++;
        }
        
        return true;
        
    }
    
    void findQueens(int i,int n,vector<vector<char>>&Queens){
        if(i==n){
            vector<string>res;
            for(int idx=0;idx<n;idx++){
                string t="";
                for(int j=0;j<n;j++)
                    t+=Queens[idx][j];
                res.push_back(t);
            }
            ans.push_back(res);
            return ;
        }
        
        for(int j=0;j<n;j++){
            if(check(i,j,Queens))
            {
                Queens[i][j]='Q';
                findQueens(i+1,n,Queens);
                Queens[i][j]='.';
            }
        }
        
        return ;
    }
    
    vector<vector<string>> solveNQueens(int n) {
         vector<vector<char>> Queens(n,vector<char>(n,'.'));
        findQueens(0,n,Queens);
        return ans;
    }
};