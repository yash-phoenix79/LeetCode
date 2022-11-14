class Solution {
public:
    
    vector<int>par;
    
    int getPar(int i){
        if(par[i]!=i)
            par[i]=getPar(par[i]);
        return par[i];
    }
    
    void connect(int a,int b){
        par[getPar(a)]=par[getPar(b)];  
    }
      
    
    bool equationsPossible(vector<string>& eq) {
        
        par=vector<int>(26);
        for(int i=0;i<26;i++)
            par[i]=i;
        
        for(int i=0;i<eq.size();i++){
            if(eq[i][1]=='!'||eq[i][0]==eq[i][3])
                continue;
            connect(eq[i][0]-'a',eq[i][3]-'a');
        }
        
        for(int i=0;i<eq.size();i++){
            if(eq[i][1]=='!')
               if(getPar(eq[i][0]-'a')==getPar(eq[i][3]-'a'))
                    return false;
        }
        
        return true;
        
    }
};