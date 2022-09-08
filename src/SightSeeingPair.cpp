#include <iostream>
#include <vector>
#include <cassert>
#include <random>

using namespace std;
/**
 * Key takeaway: The distance between two sightseeing pairs must not exclude sum of the pairs, making the score negative
 * Idea 1: keep track of max_add. From 0 to i, max_add is maximum possible add to nums[i + 1], Thus, the cur_max at nums[i] would be max_add + nums[i];
 * We need to update max_add properly. Every time we step forward it is going to decrease by 1, due to the distance. We need to compare it to nums[i] thus
 * max_add = max(max_add - 1, nums[i]);
 * 
 * Damn I solved this problem in 13 minutes feel damn so good
 */
int maxScoreSightseeingPair(vector<int>& values) {
    int max_add = values[0];
    int cur_max = 0;

    for (size_t i = 1; i < values.size(); i++) {
        max_add--;
        cur_max = max(cur_max, max_add + values[i]);
        max_add = max(max_add, values[i]);
    }

    return cur_max;
}

int main () {
    vector<int> sample = {8,1,5,2,6};
    assert(11 == maxScoreSightseeingPair(sample));

    sample = {1,2};
    assert(2 == maxScoreSightseeingPair(sample));

    sample = {1,1};
    assert(1 == maxScoreSightseeingPair(sample));

    sample = {9,1,2,2,1,4,12};
    assert(15 == maxScoreSightseeingPair(sample));

    sample = {4,3,2,1,7,4,1,2,16};
    assert(19 == maxScoreSightseeingPair(sample));

    sample = {48,12,25,13,23,11,7,14,1,19,1,1,1,1,14,1,1,1,1,9,1,1,1,5,2,3,1,1,37};
    assert(71 == maxScoreSightseeingPair(sample));

    sample = {19,1,2,1,1,8,1,1,2,2,12,8,1,2,9,8};
    assert(22 == maxScoreSightseeingPair(sample));

    sample = {5,6,7,8,9,10,7,8,1,13,5,3,9,1,10,6};
    assert(19 == maxScoreSightseeingPair(sample));

    sample = {1,9,2,8,4,6,2,8,9,4,6,1,2,9,8,4,6,1,9,2,1,8,5,7,1,2,9};
    assert(16 == maxScoreSightseeingPair(sample));

    sample = {1,2,8,6,1,2,4,8,1,2,6,4,9,3,4,8};
    assert(14 == maxScoreSightseeingPair(sample));

    sample = {13,1,1,1,1,4,1,1,5,1,1,1,1,1,1,9,1,1,1,1,1,1,1,1,1,1,1,15,1,1,7,1,1,1,1,1,9,1,1,1,1,21};
    assert(25 == maxScoreSightseeingPair(sample));

    sample = {15,1,1,1,1,1,1,1,1,1,1,1,1,1,1,12,8};
    assert(19 == maxScoreSightseeingPair(sample));

    sample = {19,8,6,1,2,9,17,6,1,2,4,7,1,20,5,17,8,25,12,8,4,6,12,4,8,7,12,54,8,1,2,5,6,41,2,8};
    assert(89 == maxScoreSightseeingPair(sample));

    cout << ":)" << endl;
}