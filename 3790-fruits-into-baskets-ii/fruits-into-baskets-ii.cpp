class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
       int n = fruits.size();
       vector<bool>arr(n,false);
       int res=0;
       for(int i=0;i<n;i++){
         bool placed = false;
         for(int j=0;j<n;j++){
            if(!arr[j] and baskets[j]>=fruits[i])
            {
                arr[j]=true;

                
                placed=true;
                break;
            }
         }
         if(!placed)res++;
       }
       return res;  
    }

};