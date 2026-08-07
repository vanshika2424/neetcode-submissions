class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        if(n>m) return findMedianSortedArrays(nums2,nums1);
        int left=(n+m+1)/2;
        int s=0;
        int e=n;
        while(s<=e){
            int m1=(s+e)/2;
            int m2=left-m1;
            int r1=INT_MAX;
            int r2=INT_MAX;
            int l1=INT_MIN;
            int l2=INT_MIN;
            if(m1<n) r1=nums1[m1];
            if(m2<m) r2=nums2[m2];
            if(m1>0) l1=nums1[m1-1];
            if(m2>0) l2=nums2[m2-1];
            if(l1<=r2 && l2<=r1){
                if((n+m)%2==1){
                    return (double) max(l1,l2);
                }
                return (double)(max(l1,l2)+min(r1,r2))/2.0;
            }
            else if(l1>r2){
                e=m1-1;
            }
            else{
                s=m1+1;

            }
        }
        return -1;
        
    }
};
