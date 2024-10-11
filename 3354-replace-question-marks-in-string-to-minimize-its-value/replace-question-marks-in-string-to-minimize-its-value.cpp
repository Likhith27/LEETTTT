class Solution {
public:
    string minimizeStringValue(string s) {
        int n = s.length();
        vector<int>freq(26,0);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='?')cnt++;
            else freq[s[i]-'a']++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<26;i++)
        {
            pq.push({freq[i],i});
        }
        string add="";
        while(cnt--)
        {
            auto cur = pq.top();
            pq.pop();
            add.push_back(cur.second+'a');
            cur.first++;
            cout<<cur.first<<" "<<cur.second<<endl;
            pq.push(cur);
            // cout<<cur.first<<" "<<cur.second<<endl;
        }
        sort(add.begin(),add.end());
        int j =0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='?')
            {
                s[i]=add[j++];
            }
        }
        return s;
    }
};