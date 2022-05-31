class Solution {
public:
    
    double find(vector<int>& nums1,int n, vector<int>& nums2,int m){
        if(n>m)
            return find(nums2,m,nums1,n);
        
        int l=0,r=n;
        int cut1=(l+r)>>1;
        
        int cut2=(m+n+1)/2-cut1;
        
        while(l<=r){
            cut1=(l+r)>>1;
            cut2=(m+n+1)/2-cut1;
            int l1=cut1==0?INT_MIN:nums1[cut1-1];
            int l2=cut2==0?INT_MIN:nums2[cut2-1];
            int r1=cut1==n?INT_MAX:nums1[cut1];
            int r2=cut2==m?INT_MAX:nums2[cut2];
            
            if(l1<=r2&&l2<=r1){
                if((m+n)%2!=0)
              return max(l1,l2);
                return ( max(l1,l2)+min(r1,r2))/2.0;
            }
            else if(l1>r2){
                r=cut1-1;
            }
            else
                l=cut1+1;
        }
        
        return -1;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n=nums1.size(),m=nums2.size();
        
    return find(nums1,n,nums2,m);
        
    }
};