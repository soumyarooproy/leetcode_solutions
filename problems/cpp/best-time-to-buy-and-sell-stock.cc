int maxProfit(vector<int>& prices)
{
    auto min_price = numeric_limits<int>::max();
    auto max_profit = 0;

    for (auto x : prices) {
        min_price = min(min_price, x);
        max_profit = max(max_profit, x - min_price);
    }

    return max_profit;
}
