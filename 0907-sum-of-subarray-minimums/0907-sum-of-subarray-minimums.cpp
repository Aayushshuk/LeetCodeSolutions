class Solution {
public:
    vector<int> findnextSmallerelement(vector<int>& arr){
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            nse[i] = !st.empty()? st.top() : n;

            st.push(i);
        }
        return nse;
    }
    vector<int> findpreviousSmallerelement(vector<int> & arrs){
        int n = arrs.size();
        vector<int> pse(n);
        stack<int> st;
        for(int i=0; i<=n-1;i++){
            while(!st.empty() && arrs[st.top()] > arrs[i]){
                st.pop();
            }
            pse[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }
        return pse;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = findnextSmallerelement(arr);
        vector<int> pse = findpreviousSmallerelement(arr);
        int total = 0;
        int mod = 1e9 + 7;
        for(int i=0; i<n; i++){
            int left = i - pse[i];
            int right = nse[i] - i;
            long long freq = left * right * 1LL;
            int val = (freq* 1LL * arr[i]) % mod;
            total = (total+val) % mod;
        }
        return total;
    }
};