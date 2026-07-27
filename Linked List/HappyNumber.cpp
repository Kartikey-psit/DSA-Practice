class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> visited;
        
        // Continue until n becomes 1 or we find a cycle
        while (n != 1 && visited.find(n) == visited.end()) {
            visited.insert(n);
            n = getNext(n);
        }
        
        return n == 1;
    }

private:
    // Helper function to calculate sum of squares of digits
    int getNext(int n) {
        int totalSum = 0;
        while (n > 0) {
            int d = n % 10;
            n = n / 10;
            totalSum += d * d;
        }
        return totalSum;
    }
};   
