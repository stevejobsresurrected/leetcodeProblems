#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/**
 * There are two key points: odd or even number of negative integers and how many zeros there are. Even number of negative integer is just another bigger positive numbers
 * Odd number of negative number however leads to big negative numbers. Zero forms checkpoint where its neibor integers cannot be multiplied by each other, meaning if we 
 * do encounter zero, we have to pick which side of the zeros, left or right, creates a greater product. So question is, which subarray, divided and identified by zero, has biggest
 * possible product?
 * 
 * Idea 1: Have cur_max and cur_product. Each iteration, cur_product *= nums[i], AND cur_max = max(cur_max, cur_product). It means that unless nums[i] is negative, cur_max is
 * going to change. When there appears another negative integers to be multiplied to cur_product, negating the - sign, that would also update cur_max. We are going to reset 
 * cur_product to 1 if we encounter zero
 * 
 * First debug: Failed at Test case 5. The array only had negative numbers and odd number of them. We had to pick which negative integer at both ends to discard.
 * Because the maxProduct was traversing from left to right, it only picked -9, because it was less than cur_product and cur_max.
 * For each traverse, we have to pick maximum product possible ending at i, by choosing which negative integer to eliminate, even after eliminating said negative, it may not be
 * greater than our cur_max;
 */
int maxProduct(vector<int>& nums) {
    int max_product = nums[0];
    int cur_max = nums[0];
    int cur_min = nums[0];
    
    for (size_t i = 1; i < nums.size(); i++) {
        int temp_max = max(nums[i], max(cur_max * nums[i], cur_min * nums[i]));
        cur_min = min(nums[i], min(cur_min * nums[i], cur_max * nums[i]));
        cur_max = temp_max;
        
        max_product = max(cur_max, max_product);
    }

    return max_product;
}

int main() {
    vector<int> sample = {1};
    assert(1 == maxProduct(sample));

    sample = {2,3,-2,4};
    assert(6 == maxProduct(sample));

    sample = {-2,0,-1};
    assert(0 == maxProduct(sample));

    sample = {1,2,3,4,5};
    assert(120 == maxProduct(sample));

    sample = {-3,-4,-2,-5,-7,-1,-9};
    assert(2520 == maxProduct(sample));

    sample = {-2,-5,-6};
    assert(30 == maxProduct(sample));

    sample = {-5,1,2,-4,-7};
    assert(56 == maxProduct(sample));

    sample = {1,-9,3,5,-1,-7,3,10};
    assert(3150 == maxProduct(sample));

    sample = {-1,2,3,2,-3,-1,1,2,-2,1,3,1,-2,4,-1,-2,-3,2,-1,3};
    assert(124416 == maxProduct(sample));

    sample = {3,5,0,2,3,1,2,6,3,9,1,3};
    assert(5832 == maxProduct(sample));

    sample = {0,-9,8,4,5,7,0,-3,5,6,8,-4,8,3,-2,-0,-1,6,4,0,-8,-3,2,7,-9,7};
    assert(69120 == maxProduct(sample));

    sample = {1,0,-3,5,9,-7,1,5,-8,3,2,0,2,1,-6,4,8,0,9,2,0,-2,5,1,6,-2,5,1,-5,9,2,-3,-5,8,2,3,0,4,6,9,8,1};
    assert(19440000 == maxProduct(sample));

    sample = {1,9,0,-5,7,3,2,9,5,4,7,2,-3,-8,9,4,1,2,0,6-3,5,8,1,9,3,-5,-7,2,-3};
    assert(182891520 == maxProduct(sample));

    sample = {5,-7,-8,-9,5,1,6,-5,9,1,2,5,-8,2,3,-1,0,5,-1,9,5,6,-3,2,-8,4,0,2,-3,8,4};
    assert(1632960000 == maxProduct(sample));

    cout << ":)" << endl;
}