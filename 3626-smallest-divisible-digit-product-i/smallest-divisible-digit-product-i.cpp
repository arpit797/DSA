class Solution {
public:
    int digitProduct(int num) {
        int product = 1;
        while (num > 0) {
            product *= (num % 10);   // ek ek digit nikaal ke multiply karo
            num /= 10;
        }
        return product;
    }

    int smallestNumber(int n, int t) {
        while (true) {
            if (digitProduct(n) % t == 0) {
                return n;             // condition match ho gayi, yahi answer hai
            }
            n++;                      // warna next number try karo
        }
    }
};