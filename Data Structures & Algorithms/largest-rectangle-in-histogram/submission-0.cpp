class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>pse(n);
        stack<int>s;
        for(int i=0;i<n;i++){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()){
                pse[i]=-1;
            }
            else{
                pse[i]=s.top();
            }
            s.push(i);
        }
        vector<int>nse(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                nse[i]=n;
            }
            else{
                nse[i]=st.top();
            }
            st.push(i);
        }
        int maxarea=0;
        for(int i=0;i<n;i++){
            int w=nse[i]-pse[i]-1;
            int area= heights[i]*w;
            maxarea=max(maxarea,area);


        }
        return maxarea;

        
    }
};
