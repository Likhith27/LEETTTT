class Solution {
public:
    bool isValid(string s) {
       stack<char>st;
       for(char i:s){
         if(i=='('||i=='['||i=='{')st.push(i);
         else{
            if(st.empty() or (st.top()=='(' and i!=')') or (st.top()=='{' and i!='}') or (st.top()=='[' and i!=']')) 
                    return false;
            st.pop();
         }
       }
       return st.empty();
    }
};