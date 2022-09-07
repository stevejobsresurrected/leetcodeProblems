#include <iostream>
#include <vector>
#include <cassert>
#include <random>

using namespace std;

/**
 * first version of getMaxLen: Examine each subarray in the array, divided and identified by 0(s). if the subarray has even number of negative integer, the local
 * maximum length is the length of the subarray itself. However, if it has odd number of negative integers then we have to keep track of first_negative and last_negative
 * to decide which one of these two will cut the subarray shorter. As shown below, it has many variables and not look pretty. 
 */

int getMaxLen(vector<int>& nums) {
    int result = 0;
    int cur_len = 0;
    int first_negative = 0;
    int last_negative = 0;
    bool negative_even = true;

    size_t i = 0;
    while (i < nums.size()) {
        int cut = 0;
        while (i < nums.size() && nums[i] != 0) {
            cur_len++;
            if (nums[i] < 0) {
                if (first_negative == 0) first_negative = cur_len;
                last_negative = cur_len;
                negative_even = !negative_even;
            }
            
            i++;
        }

        cut = min(first_negative, cur_len + 1 - last_negative);
        if (negative_even) result = max(result, cur_len);
        else result = max(result, cur_len - cut);
        i++;
        cur_len = 0;
        first_negative = 0;
        last_negative = 0;
        negative_even = true;
    }

    return result;
}

int main() {
    vector<int> sample = {1,-2,-3,4};
    assert(4 == getMaxLen(sample));

    sample = {0,1,-2,-3,-4};
    assert(3 == getMaxLen(sample));

    sample = {-1,-2,-3,0,1};
    assert(2 == getMaxLen(sample));

    sample = {1,3,-1,1,1,-3,2,1,2,-3,2,3,1};
    assert(10 == getMaxLen(sample));

    sample = {1,2,0,3,-1,-2,-3,0,-1,-2,-4,1,2,0,4,-1,2,3,1,-2,0,-4,-2,1,3,1,2,0,-3,1,-2,3,-1};
    assert(6 == getMaxLen(sample));

    sample = {-2,-1,-3,-1,-5,-2,-4,-3};
    assert(8 == getMaxLen(sample));

    sample = {1,1,2,3,1,2,4,1,2,4,1,2,4};
    assert(13 == getMaxLen(sample));

    sample = {1,9,-8,4,-6,1,-2,1,-5,1,-3,5};
    assert(10 == getMaxLen(sample));

    sample = {0,-1,0,-1,0,-1,0,-1,0,-1,0,-1,0,-1,0,-1,0,-1};
    assert(0 == getMaxLen(sample));

    sample = {1,-2,-3,4,-1,0,4,3,-2,1,4,3,0,-1,-4,-3,1,4,5,6,-1};
    assert(8 == getMaxLen(sample));

    sample = {0,5,3,-5,7,-2,-5,8,-9,6,-2,5,-8,0,9,1,5,0,-1,5,1,5,-5,0,1,0,5,2,-8,5,1,0,5,1,2,-8,5,1,0,5,1,2};
    assert(12 == getMaxLen(sample));

    sample = {1,-1,-1,-4,-1,1,-8,-9,-4,-7,-2,-4,9,-8,-7,2,0,1,4,3,1,5,3,1,5,4,3,4,-1};
    assert(16 == getMaxLen(sample));

    cout << ":)" << endl;
}