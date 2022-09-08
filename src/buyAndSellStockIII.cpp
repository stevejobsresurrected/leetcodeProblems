#include <iostream>
#include <vector>
#include <cassert>
#include <random>

using namespace std;

/**
 * 
 */
int maxProfit(vector<int>& prices) {
    int n = prices.size();
        int held = -1 * prices[0];
        int reset = 0;
        int sold = -100000;

        for (size_t i = 1; i < n; i++) {
            int temp = sold;
            
            sold = held + prices[i];
            held = max(held, reset - prices[i]);
            reset = max(temp, reset);
        }

        return max(reset, sold);
}

int main() {
    vector<int> sample = {7,1,5,3,6,4};
    assert(5 == maxProfit(sample));

    sample = {1,5,2,11,3,15};
    assert(16 == maxProfit(sample));

    sample = {1,2,3,5,7,9,3,7,11,2,5,8};
    assert(17 == maxProfit(sample));

    sample = {1,2,3,0,2};
    assert(3 == maxProfit(sample));

    sample = {1,2,3,4,5};
    assert(4 == maxProfit(sample));

    sample = {7,6,4,3,1};
    assert(0 == maxProfit(sample));

    sample = {18,21,19,25,29,13,17,14,19,21,8,15};
    assert(23 == maxProfit(sample));

    sample = {0,5,7,3,9,7,12,0,15,17,9,11,13};
    assert(30 == maxProfit(sample));

    sample = {4};
    assert(0 == maxProfit(sample));

    sample = {5,1,3,8,6,8,6,8,6,8,7,9,1,11,16,5,9};
    assert(24 == maxProfit(sample));

    sample = {46,23,35,11,29,35,24,18,11,15,16,4,12,0,15,31,19,42};
    assert(71 == maxProfit(sample));

    sample = {684,327,974,861,289,514,637,898,776,245,563,0,3,7};
    assert(1578 == maxProfit(sample));

    sample = {87,93,115,121,99,142,86,109,48,75,97,134,101,89,88,81,96,105,79,91,129};
    assert(222 == maxProfit(sample));

    sample = {7,1,4,8,9,12,14,11,15,21,0,5,6};
    assert(22 == maxProfit(sample));

    sample = {0,100};
    assert(100 == maxProfit(sample));

    sample = {211,207,241,160,183,188,191,198,201,214,215,198,230,250,1000};
    assert(867 == maxProfit(sample)); 
}