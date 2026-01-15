#include <iostream>
using namespace std;


class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
       // here we need to find the size of an array [1,2,3,4,5,6,7]
       int n = nums.size();
       // prevents useless rotations to reduce time and space complexity
       k = k % n ; // value is 3 means k =3 
       // steps to reverse the array to find ouput
       //1.reverse whole array
       reverse(nums.begin(), nums.end()); //[7,6,5,4,3,2,1]
       //2.reverse first 3 elements
       reverse(nums.begin(),nums.begin() + k); //[5,6,7,4,3,2,1]
       // 3. reverse remaining array
       reverse(nums.begin() + k, nums.end()); //[5,6,7,1,2,3,4]
    }
};