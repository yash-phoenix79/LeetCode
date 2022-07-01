class Solution {
public:
    int maximumUnits(vector<vector<int>>& box, int size) {
     
        int res=0;
        sort(begin(box),end(box),[](auto &a,auto &b){
           return a[1]>b[1]; 
        });
        
      for(auto i:box){
          if(size==0)
              break;
          else if(size>=i[0]){
              size-=i[0];
              res+=(i[0]*i[1]);
          }
          else {
              res+=(size*i[1]);
                    size=0;
          }
      }
        
        return res;
    }
};