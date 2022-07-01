class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        int tot_stu=students.size();
        int cir_stu=0,sq_stu=0;
        
        for(auto i:students){
            if(i==0)
                cir_stu++;
            else
                sq_stu++;
        }
        
        for(auto i:sandwiches){
            if(i==0){
                if(cir_stu>0){
                    cir_stu--;
                  
                }
                else
                    return sq_stu;
            }
            else{
                if(sq_stu>0){
                    sq_stu--;
                    
                }
                else
                    return cir_stu;
            }
        }
        return 0;
    }
};