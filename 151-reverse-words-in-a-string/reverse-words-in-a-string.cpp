class Solution {
public:
    string reverseWords(string s) 
    {
        stringstream ss(s);
        string res="";
        string word="";
        while(ss>>word)
        {
            res = word + " "+res;
        }
        return res.substr(0,res.size()-1);
    }
        
    
};