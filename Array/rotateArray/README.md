🔁 Rotate Array — LeetCode 189
🧩 Problem Overview

Problem:
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

What does “rotate right” mean?

Take elements from the end

Move them to the front

Keep their order the same

🧠 Real-Life Example (Very Easy)

Imagine people standing in a line:

[ A, B, C, D, E, F, G ]


If k = 3, the last 3 people move to the front:

[ E, F, G, A, B, C, D ]


That’s exactly what this problem is asking us to do.

1️⃣ LOGIC & THINKING PROCESS
a) Problem Explained in Simple Words

You are given an array and a number k

Rotate the array to the right k times

Each rotation moves the last element to the front

b) Important Tricks & Patterns
🔑 Trick 1: Reduce k
k = k % n;


Why?

Rotating n times gives the same array

Extra rotations are useless

📌 Example:

Array size = 7
k = 10 → 10 % 7 = 3

🔁 Pattern Identified

This problem follows the Array Reversal Pattern.

Very useful in:

Rotate Array

Reverse Array

Left / Right Shifts

c) Example Explained in Two Ways
Example
nums = [1,2,3,4,5,6,7]
k = 3

❌ Brute Force Approach

Idea:
Rotate the array one step at a time, k times.

Rotate 1 → [7,1,2,3,4,5,6]
Rotate 2 → [6,7,1,2,3,4,5]
Rotate 3 → [5,6,7,1,2,3,4]


⏱️ Time: O(n × k) ❌
💾 Space: O(1)

Problem:
Too slow when n and k are large.

✅ Optimal Approach (Reverse Method)

Instead of rotating repeatedly, we reverse the array in parts.

d) Why Optimal Solution Is Better
🔁 Steps

Reverse the whole array

Reverse first k elements

Reverse remaining elements

⏱️ Complexity Comparison
Approach	Time	Space
Brute Force	O(n × k)	O(1)
Extra Array	O(n)	O(n)
Reverse Method	O(n)	O(1) ✅

✔ Fast
✔ In-place
✔ Interview-preferred

2️⃣ CODE WRITING — STEP BY STEP
🔹 STL Method (Used in My LeetCode Solution)
Step 1: Function Signature
void rotate(vector<int>& nums, int k)


Provided by LeetCode.

Step 2: Find array size
int n = nums.size();


Used to:

Control bounds

Reduce k

Step 3: Reduce rotations
k = k % n;


Avoids unnecessary work.

Step 4: Reverse whole array
reverse(nums.begin(), nums.end());


Moves last elements to the front.

Step 5: Reverse first k elements
reverse(nums.begin(), nums.begin() + k);


Fixes order of rotated part.

Step 6: Reverse remaining elements
reverse(nums.begin() + k, nums.end());


Fixes remaining order.

✅ Final STL Code
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

🔹 Custom Reverse Function (No STL)
Why?

Shows real understanding

Whiteboard-friendly

Interviewers love this

Custom Reverse Logic
void reverseArray(vector<int>& nums, int start, int end) {
    while (start < end) {
        swap(nums[start], nums[end]);
        start++;
        end--;
    }
}

Complete Code (Without STL)
class Solution {
public:
    void reverseArray(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        reverseArray(nums, 0, n - 1);
        reverseArray(nums, 0, k - 1);
        reverseArray(nums, k, n - 1);
    }
};

🎯 Interview Points (VERY IMPORTANT)

✔ Always explain brute force first
✔ Then explain why it’s slow
✔ Mention reverse pattern
✔ Clearly say:

“Time complexity is O(n) and space complexity is O(1).”

🧠 One-Line Memory Trick

Rotate Right = Reverse All → Reverse First k → Reverse Rest
