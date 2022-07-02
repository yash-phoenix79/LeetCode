class Solution {
public:
    int maxArea(int h, int w, vector<int>& hori, vector<int>& verti) {
        
        int n=hori.size();
        int m=verti.size();
        
        sort(begin(hori),end(hori));
        sort(begin(verti),end(verti));
        
       
        int hor=hori[0],ver=verti[0];
        
        hor=max(hor,h-hori[n-1]);
        ver=max(ver,w-verti[m-1]);
        
        for(int i=1;i<n;i++)
            hor=max(hor,hori[i]-hori[i-1]);
        
        for(int i=1;i<m;i++)
            ver=max(ver,verti[i]-verti[i-1]);
        
        long long res=(long long)hor*ver;
        
        return (res)%1000000007;
        
    }
};