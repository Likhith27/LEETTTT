class Solution {
public:
    // vector<int> sortByBits(vector<int>& arr) 
    // {
    //     int n = arr.size();
    //     vector<int> v;
    //     map<int,int>mp;
    //     for(int i=0;i<n;i++)
    //     {
    //         mp[arr[i]] = __builtin_popcount(arr[i]);
    //     }
    //     vector<int,int>v;
    //     for(auto i:ump)
    //     {
    //         v.push_back({i.second,i.first});
    //     }
    //     return v;
        
    // }
    static bool compare(const int& a, const int& b){
        int c1 = __builtin_popcount(a);
        int c2 = __builtin_popcount(b);
        if(c1 == c2)
            return a < b;
        return c1 < c2;
    }
    vector<int> sortByBits(vector<int>& arr) {
        std::sort(arr.begin(),arr.end(), compare);
        return arr;
    }
};