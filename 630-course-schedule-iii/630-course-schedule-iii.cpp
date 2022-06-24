class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        
        sort(courses.begin(),courses.end(),[](auto &a,auto &b){
           return a[1]<b[1]; 
        });
        
        priority_queue<int>q;
        int tot=0;
        
        for(auto c:courses){
            int dur=c[0],dead=c[1];
            tot+=dur;
            q.push(dur);
            if(tot>dead){
                tot-=q.top();
                q.pop();
            }
        }
        return q.size();
    }
};