class Solution {
public:
    string reverseWords(string s) {
    //    getline(cin,s);
       stringstream ss(s);
       string ans="";
       string word="";
       while(ss>>word){
         ans = word+" "+ans;
       } 
       return ans.substr(0,ans.size()-1);
    }
};