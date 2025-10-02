class Solution {
private:
    vector<int> findNextSmallerElement(vector<int>& arr){
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            nse[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }
        return nse;
    }
    vector<int> findPreviousSmallerElement(vector<int>& array){
        int n = array.size();
        vector<int> pse(n);
        stack<int> st;
        for(int i=0; i<n;i++){
            while(!st.empty() && array[st.top()] > array[i]){
                st.pop();
            }
            pse[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }
        return pse;
    }
    long long minimumSubArrayRanges(vector<int>& arr){
        int n = arr.size();
        vector<int> NextSmallerElement = findNextSmallerElement(arr);
        vector<int> PreviousSmallerElement = findPreviousSmallerElement(arr);
        long long total =0;
        for(int i=0; i<n;i++){
            int left = i - PreviousSmallerElement[i];
            int right = NextSmallerElement[i] - i;
            long long freq = right * left * 1LL;
            int sde = (freq *1LL*arr[i]);
            total += sde;
        }
        return total;
    }
    vector<int> findNextGreaterElement(vector<int>& numbers){
        int n = numbers.size();
        vector<int> nge(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && numbers[st.top()] <= numbers[i]){
                st.pop();
            }
            nge[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }
        return nge;
    }
    vector<int> findPreviousGreaterElement(vector<int>& numbers){
        int n = numbers.size();
        vector<int> pge(n);
        stack<int> stpge;
        for(int i=0;i<n;i++){
            while(!stpge.empty() && numbers[stpge.top()] < numbers[i]){
                stpge.pop();
            }
            pge[i] = !stpge.empty() ? stpge.top() : -1;
            stpge.push(i);
        }
        return pge;
    }
    long long maximumSubArrayRanges(vector<int>& number){
        int n = number.size();
        vector<int> NextGreaterElement = findNextGreaterElement(number);
        vector<int> PreviousGreaterElement = findPreviousGreaterElement(number);
        long long total = 0;
        for(int i=0; i<n;i++){
            int left = i - PreviousGreaterElement[i];
            int right = NextGreaterElement[i] - i;
            long long freq = left * right * 1LL;
            int val = (freq * 1LL  * number[i]);
            total += val;
        }
        return total;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        return maximumSubArrayRanges(nums) - minimumSubArrayRanges(nums);
    }
};