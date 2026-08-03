class Solution {
public:
    bool possible(vector<int>& piles,int m,int h){
        int n=piles.size();
        int hr=0;
        for(int i=0;i<n;i++){
            hr+=(piles[i]+m-1)/m;
            
        }
        return (hr<=h);

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int l=1;
        int hi=*max_element(piles.begin(),piles.end());
        int ans=hi;
        while(l<=hi){
            int m=(l+hi)/2;
            if(possible(piles,m,h)){
                ans=m;
                hi=m-1;
            }
            else{
                l=m+1;
            }
        }  
        return ans;      
    }
};
