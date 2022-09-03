class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        
        vector<int>num={1,2,3,4,5,6,7,8,9};
        for(int i=2;i<=n;i++){
            vector<int>num2;
            for(auto x:num){
                int y=x%10;
                if(y+k<=9){
                    if(find(num2.begin(),num2.end(),x*10+y+k)==num2.end())
                        num2.push_back(x*10+y+k);
                }
                   
                if(y-k>=0){
                    if(find(num2.begin(),num2.end(),x*10+y-k)==num2.end())
                        num2.push_back(x*10+y-k);
                }
            }
            num=num2;
        }
        return num;
    }
};