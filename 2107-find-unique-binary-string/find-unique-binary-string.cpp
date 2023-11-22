class Solution {
public:
    int n;
    unordered_set<string>st;
    string f(string s)
    {
        if(s.size()==n)
        {
            if(st.find(s)==st.end())
                return s;
            return "";
        }
        string zero = f(s+"0");
        if(zero.size()>0)
            return zero;
        return f(s+"1");
        
    }
    string findDifferentBinaryString(vector<string>& nums) 
    {
        // int n = nums.size();
        // string s;
        // // for every i-th string we go to i-th number and add the opposite of ith number
        // for(int i=0;i<n;i++)
        // {
        //     if(nums[i][i]=='0')
        //         s+='1';
        //     else
        //         s+='0';

        // }
        // return s;
        n = nums.size();
        for(string s:nums)
            st.insert(s);

        return f("");
    }
};