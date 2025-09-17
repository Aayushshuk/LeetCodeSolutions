class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        Solve(0,"",0,0,num,target,ans);
        return ans;
    }
    void Solve(int index,string sumPath, long long  sum, long long  prev, string num, long long target, vector<string>& ans)
    {
        if(index == num.size()){
            if(sum == target){
                ans.push_back(sumPath);
            }
            return;
        }
        for(int j = index; j<num.size();j++)
        {
            if(j>index && num[index] == '0'){
                break;
            }
            long number = stol(num.substr(index,j-index+1));

            string temppath = num.substr(index, j-index+1);

            if(index==0)
            {
                Solve(j+1, temppath, number, number, num ,target,ans);
            }
            else
            {
                Solve(j+1, sumPath + '+' + temppath, sum+number,number,num,target,ans);
                Solve(j+1, sumPath + '-' + temppath, sum-number,-number, num, target, ans);
                Solve(j+1, sumPath + '*' + temppath, sum-prev +(number*prev), number*prev, num, target,ans);
            }
        }
    }
};