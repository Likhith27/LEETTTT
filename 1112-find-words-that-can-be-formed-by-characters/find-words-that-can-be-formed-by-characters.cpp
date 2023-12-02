class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        // map<char,int>mp;
        // for(auto ch:chars)
        //     mp[ch]++;
        // bool flag = true;
        // string count = "";
        // for(auto i:words)
        // {
        //     flag = true;
        //     map<char,int>v;
        //     for(auto ch:i)
        //         v[ch]++;
        //     for(auto ch:i)
        //     {
        //         if(v[ch]>mp[ch])
        //             flag = false;
        //         if(flag)
        //             count += i;
        //     }
        // }
        // return count.length();
        unordered_map<char,int> chFreq;
        for(auto ch : chars) chFreq[ch]++;
        bool flag = true;
        string count = "";
        for(auto str : words){
            flag = true;
            unordered_map<char,int> copyFreq;
            for(auto ch : str) copyFreq[ch]++;
            for(auto ch : str) if(copyFreq[ch] > chFreq[ch]) flag = false;
            if(flag) count += str;
        }
        return count.length();
    }
};