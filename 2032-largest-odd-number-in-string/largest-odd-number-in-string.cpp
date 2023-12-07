class Solution {
public:
    string largestOddNumber(string num) {
        // long long int maxi=0;
        // for(int i=0;i<num.size();i++)
        // {
        //     for(int j=i;j<num.size();j++)
        //     {
        //         string k = num.substr(i,j-i+1);
        //         long long int m = stoi(k);
        //         if(m>maxi and m%2!=0)
        //             maxi = m;
        //     }
        // }
        // if(maxi==0)
        //     return "";
        // else
        //     return to_string(maxi);
        while(num.length()>0 && (num.back() - '0')%2 == 0)
        {
            num.pop_back();
        }
        return num;
    }
};