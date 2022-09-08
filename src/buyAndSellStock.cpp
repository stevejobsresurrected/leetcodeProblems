#include <iostream>
#include <vector>
#include <cassert>
#include <random>

using namespace std;

int maxProfit(vector<int>& prices) {
    int cur_min = prices[0];
    int cur_max = 0;

    for (size_t i = 0; i < prices.size(); i++) {
        cur_max = max(cur_max, prices[i] - cur_min);
        cur_min = min(cur_min, prices[i]);
    }

    return cur_max;
}

int main() {
    vector<int> sample = {7,1,5,3,6,4};
    assert(5 == maxProfit(sample));

    sample = {7,6,4,3,1};
    assert(0 == maxProfit(sample));

    sample = {1,2,3,4,5,6,9};
    assert(8 == maxProfit(sample));

    sample = {5,5,5,5,5,5,3,2,1};
    assert(0 == maxProfit(sample));

    sample = {3,5,6,7,8,2,5,6};
    assert(5 == maxProfit(sample));

    sample = {13,14,15,17,19,21,9,1,3,5,3,4,7,12};
    assert(11 == maxProfit(sample));

    sample = {5,8,6,12,9,17,14,9,3,16,13,7,6,1,1,2,13,0};
    assert(13 == maxProfit(sample));

    sample = {195,68,250,192,86,53,209,621,61,83,70,198,461,248,68,104,68,24};
    assert(568 == maxProfit(sample));

    sample = {6,5,4,3,2,1,2,3,4,5};
    assert(4 == maxProfit(sample));

    sample = {76,43,17,19,25,18,17,20,24,23,21,21,8,9,16,13,15,19};
    assert(11 == maxProfit(sample));

    sample = {7};
    assert(0 == maxProfit(sample));

    sample = {11,9,1,3,5,9,8,7,13,9,8,14,9,8,4,12};
    assert(13 == maxProfit(sample));

    sample = {10,29,47,21,14,21,61,29,17,69};
    assert(59 == maxProfit(sample));

    sample = {100,98,77,89,83,71,76,61,53,65,49,42,31,47,39,21,20,30,25,19,29,17};
    assert(16 == maxProfit(sample));
}