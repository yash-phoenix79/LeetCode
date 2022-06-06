class Solution {
public:
    vector<string> findRestaurant(vector<string>& l1, vector<string>& l2) {
        vector<string>res;
        int idx,mini=INT_MAX;
        for(int i=0;i<l1.size();i++){
            for(int j=0;j<l2.size();j++){
                if(l1[i]==l2[j]){
                    if(i+j<mini){
                        res.clear();
                        res.push_back(l1[i]);
                        mini=i+j;
                    }
                    else if(i+j==mini)
                        res.push_back(l1[i]);
                }
            }
        }
        return res;
    }
};