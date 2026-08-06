class Solution {
public:
    int smallestNumber(int n, int t) {
        for (int num = n; num < n + 10; ++num) {
            if (getDigitProduct(num) % t == 0) {
                return num;
            }
        }
        return -1; 

    }

private:
    int getDigitProduct(int num) {
        int product = 1;
        while (num > 0) {
            product *= num % 10;
            num /= 10;
        }
        return product;
    }
};   
