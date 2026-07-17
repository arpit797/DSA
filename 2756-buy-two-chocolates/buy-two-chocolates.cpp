class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int first = INT_MAX;
        int second = INT_MAX;

        for (int price : prices) {
            if (price < first) {
                second = first;
                first = price;
            } 
            else if (price < second) {
                second = price;
            }
        }

        int cost = first + second;

        if (cost <= money)
            return money - cost;

        return money;
    }
};