class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int minprice=prices[0];
        int maxprof=0;
        for(int i=1;i<n;i++){
            minprice=min(minprice,prices[i]);
            int prof=prices[i]-minprice;
            maxprof=max(prof,maxprof);
           

        }
        return maxprof;
        
    }
};