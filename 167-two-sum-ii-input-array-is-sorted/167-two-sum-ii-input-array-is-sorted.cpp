class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int l=0,r=numbers.size()-1;
        
        while(l<r){
            if(numbers[l]+numbers[r]==target){
                break;
            }
            else if(numbers[l]+numbers[r]<target){
                l++;
                while(l<r&&numbers[l]==numbers[l-1])
                    l++;
            }
            else{
                r--;
                while(l<r&&numbers[r]==numbers[r+1])
                    r--;
            }
        }
        
        vector<int>ans={l+1,r+1};
        
        return ans;
    }
};