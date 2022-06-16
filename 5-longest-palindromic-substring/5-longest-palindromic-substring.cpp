class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length(),cnt,l,r;
        
        string ans="",temp;
        
        for(int i=0;i<n;i++){
            cnt=1;
            l=i-1,r=i+1;
            while(l>=0&&r<n&&s[l]==s[r]){
                l--;
                r++;
                cnt+=2;
            }
            l++,r--;
            temp=s.substr(l,cnt);
            if(cnt>ans.size())
                ans=temp;
        }
        
        for(int i=0;i<n;i++){
            cnt=0;
            l=i,r=i+1;
            while(l>=0&&r<n&&s[l]==s[r])
            {
                l--;
                r++;
                cnt+=2;
            }
            l++,r--;
            temp=s.substr(l,cnt);
             if(cnt>ans.size())
                ans=temp;
        }
        
        return ans;
    }
};