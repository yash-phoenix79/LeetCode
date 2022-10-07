class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        
        priority_queue<pair<int,int>>pq1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq2;
        
        priority_queue<int,vector<int>,greater<int>>pq3;
        
        for(int i=0;i<nums2.size();i++)
        {
            pq1.push({nums2[i],i});
            pq2.push({nums2[i],i});
            pq3.push(nums1[i]);
        }
        
        while(!pq3.empty()){
            if(pq2.top().first<pq3.top()){
                nums1[pq2.top().second]=pq3.top();
                pq2.pop();
            }
            else{
                nums1[pq1.top().second]=pq3.top();
                pq1.pop();
            }
            pq3.pop();
        }
        
        return nums1;
        
    }
};