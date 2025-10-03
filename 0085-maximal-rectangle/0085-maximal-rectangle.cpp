class Solution {
private:
    int largestRectangle(vector<int>& prefixSum){
        int n = (int)prefixSum.size();
        stack<int> st;
        int largestArea=0;

        for(int i=0; i<n;i++){
            while(!st.empty() && prefixSum[st.top()] > prefixSum[i]){
                int element = st.top();
                st.pop();
                int pse = st.empty()? -1: st.top();
                int nse =i;
                int area = prefixSum[element] *(nse -pse -1);
                largestArea = max(area, largestArea);
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse =n;
            int element = st.top();
            st.pop();

            int pse = st.empty()?-1:st.top();
            int area = prefixSum[element] * (nse-pse-1);
            largestArea = max(largestArea, area);
        }
        return largestArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int n = (int)matrix.size();
        int m = (int)matrix[0].size();
         vector<int>prefixSum(m,0);
        int maxArea =0;
        for(int j=0; j<n;j++){
            for(int i=0; i<m;i++){
                if(matrix[j][i] == '1') {
                    prefixSum[i]+=1;
                }
                else{
                    prefixSum[i] =0;
                }
            }
            int area = largestRectangle(prefixSum);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};