class Solution {
public:
    int totalMoney(int n) {
        // int k = n/7;
        // int m = n%7;

        // int total = ((k*(k-1))/2)*7;
        // total += k*28;
        // total += ((m*(m-1))/2) +(k*m);
        // return total;
        int w = n / 7;
        int d = n % 7;
        return (n * (w + 7) + d * (d + w - 6)) >> 1;
    }
};