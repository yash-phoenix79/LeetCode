class Solution {
public:
    
    int gcd(int a ,int b){
        while(b){
            a=a%b;
            swap(a,b);
        }
        return a;
    }
    
    int maxPoints(vector<vector<int>>& poi) {
     
        int n=poi.size();
        int res=0;
    
        for(int i=0;i<n;i++){
            int dup=1;
             unordered_map<string,int>m;
            for(int j=i+1;j<n;j++)
            {
            if(poi[i][0]==poi[j][0]&&poi[i][1]==poi[j][1])
                dup++;
                else{
                    int dy=poi[i][1]-poi[j][1];
                    int dx=poi[i][0]-poi[j][0];
                    int d=gcd(dx,dy);
                    m[(to_string(dx/d)+'_'+to_string(dy/d))]++;
                }
            }
            res=max(res,dup);
            for(auto x:m){
                res=max(res,x.second+dup);
            }
         
        }
        
        return res;
        
    }
};