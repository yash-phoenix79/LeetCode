class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>a1(1),a2(2);
        a1[0]=1;
        a2[0]=1,a2[1]=1;
        
        if(rowIndex==0)
            return a1;
        if(rowIndex==1)
            return a2;
        
        for(int i=1;i<rowIndex;i++){
            a1.resize(i+2);
            a1[0]=a1[i+1]=1;
            for(int j=1;j<=i;j++)
                a1[j]=a2[j]+a2[j-1];
            a2=a1;
        }
        
        return a1;
        
    }
};