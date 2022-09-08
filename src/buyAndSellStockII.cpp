#include <iostream>
#include <vector>
#include <cassert>
#include <random>

using namespace std;

/**
 * This problem is very simple. Simply calculate all the increase through the array.
 * 
 * Ez Pz
 */
int maxProfit(vector<int>& prices) {
    int result = 0;
    for (size_t i = 1; i < prices.size(); i++) {
        int upDown = prices[i] - prices[i - 1];
        result += upDown > 0 ? upDown : 0; 
    }

    return result;
}

int main() {
    vector<int> sample = {7,1,5,3,6,4};
    assert(7 == maxProfit(sample));

    sample = {1,2,3,4,5};
    assert(4 == maxProfit(sample));

    sample = {7,6,4,3,1};
    assert(0 == maxProfit(sample));

    sample = {18,21,19,25,29,13,17,14,19,21,8,15};
    assert(31 == maxProfit(sample));

    sample = {0,5,7,3,9,7,12,0,15,17,9,11,13};
    assert(39 == maxProfit(sample));

    sample = {4};
    assert(0 == maxProfit(sample));

    sample = {5,1,3,8,6,8,6,8,6,8,7,9,1,11,16,5,9};
    assert(34 == maxProfit(sample));

    sample = {46,23,35,11,29,35,24,18,11,15,16,4,12,0,15,31,19,42};
    assert(103 == maxProfit(sample));

    sample = {684,327,974,861,289,514,637,898,776,1245,1563,0,3,7};
    assert(2050 == maxProfit(sample));

    sample = {87,93,115,121,99,142,86,109,48,75,97,134,101,89,88,81,96,105,79,91,129};
    assert(260 == maxProfit(sample));

    sample = {7,1,4,8,9,12,14,11,15,21,0,5,6};
    assert(29 == maxProfit(sample));

    sample = {0,100};
    assert(100 == maxProfit(sample));

    sample = {211,207,241,160,183,188,191,198,201,214,215,198,230,250,1000};
    assert(891 == maxProfit(sample)); 

    srand(time(NULL));
    int count = 200;
    int total_up = 0;
    sample.clear();
    sample.emplace_back(rand() % 100);
    for (size_t i = 1; i < count; i++)
    {
        int cur = rand() % 500;
        if (rand() % 2) {
            total_up += cur;
            sample.emplace_back(sample[i - 1] + cur);
        }
        else {
            int temp = sample[i - 1] - cur <= 0 ? 0 : sample[i - 1] - cur;
            sample.emplace_back(temp);
        }
    }

    cout << ":)" << endl;
    assert(total_up == maxProfit(sample));
    
}
