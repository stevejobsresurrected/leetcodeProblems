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

int getMaxLenV1(vector<int>& nums) {
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

/**
 * second version of getMaxLen is to keep track of two variables pos_len and neg_len
 * pos_len is maximum length of local positive product subarray
 * neg_len is maximum length of local negative product subarray.
 * When encountering a positive integer, pos * pos is just greater positive number and neg * positive is just smaller negative number further from 0
 * When encountering a negative integer, these two will swap. However, there are some edge cases to be careful of, which I failed to implement in my first trial
 * 
 * edge case 1 when encountering a positive number: neg_len being zero means there was not a single negative number. Thus, multiplying positive only serves to
 * maximize the positive combo chain, rather than maximizing scale of the negative combo chain. Thus, we need to leave neg_len to zero until we encounter our
 * first negative integer
 * 
 * edge case 2 when encountering a negative number: When we encounter first negatie integer of our current subarray, neg_len will be 0, thanks to the edge case 1 above
 * When we swap pos_len and neg_len when we first encounter zero therefore, pos_len doesn't get updated to the correct value, because there was no negative value
 * In this case, we have to start over our pos_len count. My concern was that possibility of pos_len being max_len but by that time pos_len is already compared against
 * the max_len so it is ok. For this reason my first intuition was that if neg_len is zero, pos_len should not be changed but there was also possibility of next
 * streak of positive numbers, separated by the negative number is greater than the current pos_len (+++-+++++++) <- pos_len will be stuck at the first 3 positives.
 * 
 * This is the logic I tried first but failed due to lack of implementation details. This is a retrial after referencing https://www.youtube.com/watch?v=isC1Mi4kdIA
 */
int getMaxLen(vector<int>& nums) {
    int pos_len = 0;
    int neg_len = 0;
    int max_len = 0;

    for (size_t i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) { // if elem is positive
            pos_len++;
            if (neg_len != 0) neg_len++; // edge case 1
        }
        else if (nums[i] < 0) { // if elem is negative
            int temp = pos_len;
            pos_len = neg_len == 0 ? 0 : 1 + neg_len; // edge case 2
            neg_len = 1 + temp;
        }
        else {
            pos_len = 0;
            neg_len = 0;
        }

        max_len = max(max_len, pos_len);
    }

    return max_len;
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