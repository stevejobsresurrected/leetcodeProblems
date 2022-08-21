#include <iostream>
#include <vector>
#include <cassert>
#include <random>

using namespace std;

/**
 * Everything is an add or not add game in problem. Either add the subarray because the subarray adds to the maxium or
 * discard the subarray because it subtracts from the maxium. 
 * cur_max, represents current maximum subarray, while cur_sum represents current sum of the current subarray
 * as long as cur_sum remains positive, it can add to the future possible array as we traverse
 * Only when cur_sum becomes negative, we know that current subarray will not add to maxium, thus can abandon the
 * current subarray to start a new subarray, which possibly might be the maximum subarray
 * 
 * The concern was that there might be a moment where it is better not to add current positive integer to current subarray
 * because at that point, it is perfectly possible that the positive integer is not big enough to negate the one or more 
 * negative integers, but that issue was accounted for by updating cur_max only when cur_sum grows larger than cur_max
 * Whenever we encounter negative section in our subarray, we have to decide whether to include the negative section, that is whether
 * the positive section on the either side(or both) is(are) big enough to negate the negatives. if both sides are large enough, we can include
 * the negative section but if not, we have to pick either left or right section for our maxium
 * when cur_sum becomes 0, as we traverse from left to right of the array, it indicates that the current negative section now negates 
 * the left side. What about same scenario but right side situation? we simply account that by keeping track of cur_max
 * cur_sum going below cur_max as we traverse indicate that negative sections were large enough to negate positive sections
 * However, since we are remembering cur_max, we stil know our maximum subarray, in our current subarray
 */

int maxSubArray(vector<int>& nums) {
    int cur_max = nums[0];
    int cur_sum = 0;

    for (size_t i = 0; i < nums.size(); i++) {
        cur_sum += nums[i];
        cur_max = max(cur_sum, cur_max);
        cur_sum = cur_sum < 0 ? 0 : cur_sum;
    }
    

    return cur_max;
}

int main() {
    vector<int> sample = {5,4,-1,7,8};
    assert(23 == maxSubArray(sample));

    sample = {1};
    assert(1 == maxSubArray(sample));

    sample = {-2};
    assert(-2 == maxSubArray(sample));

    sample = {-2,1,-3,4,-1,2,1,-5,4};
    assert(6 == maxSubArray(sample));

    sample = {1,-2,3,6,-7,5,-9,0,1,-1};
    assert(9 == maxSubArray(sample));

    sample = {1,1,1,1,1,1,1,1,1,-8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,-21};
    assert(17 == maxSubArray(sample));

    sample = {-23,-1,-45,-3,-8,-9,-10,-14,-21};
    assert(-1 == maxSubArray(sample));

    sample = {13,9,6,3,-23,21,-5,-12, 9,-17,4,9,-28,19,11,-28,27,36,21,-59,-36,47};
    assert(86 == maxSubArray(sample));

    sample = {1,-1,2,-2,3,-3,4,-4,5,-5,6,-6,7,-7,8,-8,9,-9};
    assert(9 == maxSubArray(sample));

    sample = {-14,-21,15,3,-8,-3,13,-9,12,6,-11,13};
    assert(31 == maxSubArray(sample)); 

    sample.clear();
    vector<int> slns = {19,69,122,29,0,-5,19,7,65,52};
    for (size_t i = 0; i < 10; i++) {
        int size = rand() % 30;
        for (size_t j = 0; j < size; j++) {
            int elem = rand() % 20;
            int sign = rand() % 2;
            if (sign) elem *= -1;
            sample.emplace_back(elem);
        }

        assert(slns[i] == maxSubArray(sample));
        sample.clear();

    }

    cout << ":) " << endl;
}