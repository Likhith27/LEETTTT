class Solution {
    // int maxRows(int balls) {
    //     // Calculate the maximum number of complete rows that can be formed with the given balls
    //     return static_cast<int>((-1 + std::sqrt(1 + 8.0 * balls)) / 2);
    // }
    
    int helper(int red, int blue) {
        int height = 0;
        int row = 1;
        bool useRed = true; // Start with red balls

        while (true) {
            if (useRed) {
                if (red >= row) {
                    red -= row;
                    height++;
                } else {
                    break;
                }
            } else {
                if (blue >= row) {
                    blue -= row;
                    height++;
                } else {
                    break;
                }
            }
            useRed = !useRed;
            row++;
        }
        
        return height;
    }

public:
    int maxHeightOfTriangle(int red, int blue) {
        return max(helper(red, blue), helper(blue, red));
    }
};
