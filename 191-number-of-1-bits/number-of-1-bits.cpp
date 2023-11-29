class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
       int count = 0;
    
        while(n) 
        {
            n &= (n - 1);
            count++;
        }
        
        return count; 
        // return __builtin_popcount(n);
    }
    // trick is by the time n reaches zero number of times we do & between n and n-1 is the number of ones in the given number
};