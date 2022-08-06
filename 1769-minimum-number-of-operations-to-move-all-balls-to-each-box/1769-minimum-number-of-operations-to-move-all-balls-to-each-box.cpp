class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.length();
        
        vector<int>res;
        
        for(int i=0;i<n;i++){
            int t=0;
            for(int j=0;j<n;j++)
                if(boxes[j]=='1'&&j!=i)
                    t+=abs(i-j);
            res.push_back(t);
        }
        return res;
    }
};