class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        vector<int> result;
        priority_queue<int> maxHeap;  

        for (const auto& query : queries) {
            int distance = abs(query[0]) + abs(query[1]);
            
            if (maxHeap.size() < k) 
            {
                maxHeap.push(distance);  
            } 
            else if (distance < maxHeap.top()) 
            {
                maxHeap.pop();           
                maxHeap.push(distance); 
            }
            if (maxHeap.size() < k) 
            {
                result.push_back(-1);   
            } 
            else 
            {
                result.push_back(maxHeap.top());  
            }
        }
        return result;
    }
};