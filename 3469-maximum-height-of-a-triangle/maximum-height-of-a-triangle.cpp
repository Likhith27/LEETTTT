class Solution {
    int helper(int red,int blue){
        int redlines=sqrt(red);
        int bluelines=(sqrt(1+4*blue)-1)/2;
        if(redlines==bluelines) return 2*redlines;
        else if(redlines>bluelines) return 2*bluelines+1;
        else return 2*redlines;
    }
public:
    int maxHeightOfTriangle(int red, int blue) {
        return max(helper(red,blue),helper(blue,red));
    }
};