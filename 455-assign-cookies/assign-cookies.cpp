class Solution {
public:
    
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = g.size();
        int n = s.size();
        // int sum=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int sum=0;
        int i=0,j=0;
        while(i<n and j<m)
        {
            if(s[i]>=g[j]){
                sum+=1;
                i++;
                j++;
            }
            else if(s[i]<g[j])
            {
                i++;
            }
            // else
            //     j++;

        }
        return sum;
    }
};