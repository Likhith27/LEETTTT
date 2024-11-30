class Solution {
public:
    string largestOddNumber(string num) {
         while(num.length()>0 and (num.back()-'0')%2==0)
            num.pop_back();
        return num;

    }
};