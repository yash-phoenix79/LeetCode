class Solution {
public:
    int findComplement(int num) {
        
        int i=31;
        
        while((num&1<<i)==0)
            i--;
        
        while(i>=0)
        {
            num^=(1<<i--);
        }
        
        return num;
        
    }
};