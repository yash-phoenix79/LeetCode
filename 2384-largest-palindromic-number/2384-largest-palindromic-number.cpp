class Solution {
public:
    string largestPalindromic(string num) {
         
        vector<int>freq(10,0);
        for(auto x:num)
            freq[x-'0']++;
        
        string temp="";
        int i=9;
        while(i>=1){
            while(freq[i]>1){
                temp+='0'+i;
                freq[i]-=2;
            }
            i--;
        }
        
        if(temp!=""&&freq[0]>1){
            int n=freq[0]/2;
            while(n--){
                temp+='0';
                freq[0]-=2;
            }
        }
         string t=temp;
      
        reverse(begin(t),end(t));

        for(int i=9;i>=0;i--){
            if(freq[i]>=1)
            {
                temp+='0'+i;
                break;
            }
        }
                temp+=t;
       
        return temp;
        
    }
};