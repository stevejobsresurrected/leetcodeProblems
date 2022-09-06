#include <iostream>
#include <vector>
#include <cassert>
#include <random>

using namespace std;
/**
 * Idea 1: Simplest that come to mind. Apply the same MaxSubArray algorithm, but instead of traversing through the end of the array,
 * we are going to keep track of max_start_index, which is a starting index of current maximum subarray, and we are going to end
 * traversing only when we reach this max_start index. Once we reach this index without switching maximum, it indicates that there
 * was no greater subarray than the current maximum while we traverse the vector for another round. 
 * 
 * But then, there's a catch. Consider cur_maximum starts at zero and cur_sum at the end of the vector is still positive, but less than 
 * cur_max. Since this is a circular array, we should add cur_sum to cur_max, which are connected, to get a new cur_max but above logic doesn't
 * account for that. we might be tempted to simply add edge case where we are adding cur_sum to cur_max when max_start_index is zero and cur_sum
 * is positive at the end, but there's another catch. That only works if max_start_index is zero. If cur_max subarray happens to start at somewhere 
 * in the middle of the array, When in reality the real maxSubarray is supposed to consist of subarray attached to end of the array and subarray at 
 * the start, it doesn't work. Never mind. When cur_max is in the middle, the as our traverse comes around from back to front, because max_start_index
 * is going to traverse until the middel, naturally, picking up elements along the way to exceed the cur_max
 * 
 * This turns out to cause a problem when the maxSubarray of the array is the array itself. In that case, exploiting the property of circular,
 * we can even maximize the max value by eliminating negative section in the middle, but logic to account for that scenario is rather complicated.
 * 
 * If cur_sum has never been reset, it means the sum of the array never goes below 0. If the maximum subarray is one interval inside the array, it wouldn't be
 * a problem. If the maximum subarray is two-interval however, it becomes a problem. If there is extra condition of the maximum subarray being the entire array itself
 * we can simply plus the maxSubArray of reversed sign nums, but if not,  
 * 
 * Time complexity: N ~ 2N
 * 
 * Final: 
 * 
 */

int maxSubarraySumCircular(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int cur_max = nums[0];
    int cur_sum = 0;
    int sum = 0;
    int cur_min = nums[0];
    int cur_min_sum = 0;

    for (size_t i = 0; i < nums.size(); i++) {
        sum += nums[i];

        cur_sum += nums[i % nums.size()];
        cur_max = max(cur_sum, cur_max);
        cur_sum = cur_sum < 0 ? 0 : cur_sum;

        cur_min_sum += nums[i];
        cur_min = min(cur_min, cur_min_sum);
        cur_min_sum = cur_min_sum > 0 ? 0 : cur_min_sum;
    }
    
    return sum == cur_min ? cur_max : max(cur_max, sum - cur_min);
}

int main() {
    vector<int> sample = {1,-2,3,-2};
    assert(3 == maxSubarraySumCircular(sample));

    sample = {5,-3,5};
    assert(10 == maxSubarraySumCircular(sample));

    sample = {5,1,-2,-1,4,-2,-1,1,3,4};
    assert(15 == maxSubarraySumCircular(sample));

    sample = {-3,-2,-3};
    assert(-2 == maxSubarraySumCircular(sample));

    sample = {4,5,-1,-3,-2,7};
    assert(16 == maxSubarraySumCircular(sample));

    sample = {5,7,4,-3,-2,3,4,-2,-1,5,1};
    assert(26 == maxSubarraySumCircular(sample));

    sample = {3,5,6,-7,-2,-5,4,5};
    assert(23 == maxSubarraySumCircular(sample));

    sample = {13,6,4,-8,6,-7,2,4,5,-9,5,-7,-3,4,-6};
    assert(25 == maxSubarraySumCircular(sample));

    sample = {-3,1,-2,7,-13,5,4,-1,-2,7};
    assert(16 == maxSubarraySumCircular(sample));

    sample = {-1,-2,-3,-2,-5,-7,-10};
    assert(-1 == maxSubarraySumCircular(sample));

    sample = {1,2,3,4,5,6,5,4,3,2,1};
    assert(36 == maxSubarraySumCircular(sample));

    sample = {14,3,-5,9, -7,2,1,-3,5,2,-6,3,-14, 16,-3,-9,7,-6,8,-7};
    assert(27 == maxSubarraySumCircular(sample));

    sample.clear();
    vector<int> slns = {19,76,122,29,0,-5,19,7,70,59,3,13,71,37,12,21,41,10,122,115,31,25,0,67,35};
    for (size_t i = 0; i < 25; i++) {
        int size = rand() % 30;
        for (size_t j = 0; j < size; j++) {
            int elem = rand() % 20;
            int sign = rand() % 2;
            if (sign) elem *= -1;
            sample.emplace_back(elem);
        }

        assert(slns[i] == maxSubarraySumCircular(sample));
        sample.clear();
    }

    cout << ":) " << endl;
}