class Solution {
public:
    bool canAliceWin(int n) {
        int flag = 0;
        for(int i=10;i>0;i--){
            if(n-i<0)return flag;
            n-=i;
            flag=!flag;
        }
        return flag;


    }
};