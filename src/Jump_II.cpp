#include <iostream>
#include <vector>
#include <cassert>
#include <random>

using namespace std;

bool canJump(vector<int>& nums) {
    int i = 1;
    // fr = furthest reach so far
    int fr = nums[0];
    // loop through vector
    while (i < nums.size()) {
        // when furthest reach cannot current index, 
        // it means the current i index is unreachable, thus return false
        if (fr < i) return false;
        // get max reach so far. 
        fr = max(fr, nums[i] + i);
        i++;
    }

    return true;

}

int jump(vector<int>& nums) {
    // if (nums.size() == 1) return 0;
    int i = 1;
    int count = 0;
    int fr = nums[0];
    while (i < nums.size()) {
        // compare current furthest reach and reach of current index
        // if current reach is greater, increment count and update furthest reach
        int cur_fr = fr;
        while (i <= cur_fr && i < nums.size()) {
            fr = max(fr, nums[i] + i);
            i++;
        }

        count++;
    }

    return count;
}

int main()
{
    vector<int> sample = {2,3,1,1,4};
    assert(2 == jump(sample));

    sample = {2,1};
    assert(1 == jump(sample));

    sample = {1,1,5,3,2,4,1,3,1};
    assert(4 == jump(sample));

    sample = {2,3,0,1,4};
    assert(2 == jump(sample));

    sample = {0};
    assert(0 == jump(sample));

    sample = {3};
    assert(0 == jump(sample));

    sample = {1,5,3,2,1,0,4,7};
    assert(3 == jump(sample));

    sample = {1,1,1,1,1,1,1,1,1};
    assert(8 == jump(sample));

    sample = {4,1,3,7,8,5,0,1,2};
    assert(2 == jump(sample));

    sample = {2,1,5,4,3,2,1,1,1,1,3,2,0,1,4,7,2,3,2,1,2,4,2,0,1,1,2,2,1};
    assert(12 == jump(sample));

    sample = {3,2,1,5,4,3,2,1,6,5,4,3,2,1,7,7,7,7,7,7,7,1};
    assert(4 == jump(sample));

    sample = {2,3};
    assert(1 == jump(sample));

    sample = {9,4,2,3, 7,6,3,2,1,1,4,2, 1, 6,1,2, 5,4,3,2,1};
    assert(5 == jump(sample));

    srand(time(0));

    vector<int> s(rand() % 1000);
    for (size_t i = 0; i < s.size(); i++) {
        
    }

    cout << ":)" << endl;
}
