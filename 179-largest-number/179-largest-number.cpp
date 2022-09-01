class Solution {
public:
    string largestNumber(vector<int>& nums) {
     int n=nums.size();
        vector<string>temp(n);
        for(int i=0;i<n;i++)
            temp[i]=to_string(nums[i]);
        sort(begin(temp),end(temp),[](auto &a,auto &b){
           return a+b>b+a; 
        });
        string res="";
        for(auto x:temp)
            res+=x;
        int i=0;
        while(i<res.size()-1&&res[i]=='0')
            res.erase(0,1);
        return res;
    }
};