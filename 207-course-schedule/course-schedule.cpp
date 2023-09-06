class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int>adj[n];
        vector<int>indegree(n,0);
        queue<int>q;
        vector<int>v;
        for(auto i:prerequisites)
        {
            adj[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            v.push_back(node);
            for(auto i:adj[node])
            {
                indegree[i]--;
                if(indegree[i]==0)
                    q.push(i);
            }
        }
        return v.size()==n;

    }
};