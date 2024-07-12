class Solution {
public:
    string longestPrefix(string s) {
        int n=s.length();
        vector<int>kmp(n+1,0);
        kmp[0]=-1;
        //ababab
        //0,0,1,2,3,4
        int i=0;//iterative pointer
        int j=-1;//jumping pointer
        while(i<n)
        {
            while(j!=-1 and s[i]!=s[j])
                j=kmp[j];
            j++;
            i++;
            kmp[i]=j;
        }
        return s.substr(0,kmp[n]);
        // int maxi=INT_MIN;
        // int ind=-1;
        // for(int i=0;i<=n;i++)
        // {
        //     if(kmp[i]>maxi){
        //         maxi=kmp[i];
        //         ind = i;
        //     }
        // }
        // return s.substr(ind,maxi);
    }
};