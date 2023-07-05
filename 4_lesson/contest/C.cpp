#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> prices(N);
    for (int i = 0; i < N; i++) {
        cin >> prices[i];
    }
    
    const int INF = numeric_limits<int>::max();
    int buyIndex = -1;
    int sellIndex = -1;
    int maxProfit = 0;
    int minPrice = INF;
    
    for (int i = 0; i < N; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
            buyIndex = i;
        }
        
        if (prices[i] - minPrice > maxProfit) {
            maxProfit = prices[i] - minPrice;
            sellIndex = i;
        }
    }
    
    if (buyIndex == -1 || sellIndex == -1) {
        cout << "-1 -1" << endl;
    } else {
        cout << buyIndex + 1 << " " << sellIndex + 1 << endl;
    }
    
    return 0;
}
