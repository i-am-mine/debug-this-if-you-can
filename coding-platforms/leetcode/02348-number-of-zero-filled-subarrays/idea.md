# 2348. Number of Zero-Filled Subarrays
*(Problem statement is cited at the end for reference)*


## 🔍 Idea

Let’s analyze by hand with a simple case:

- For a sequence of **3 zeros** `[0, 0, 0]`, all subarrays consisting only of zeros are:
[0] → 3 occurrences
[0, 0] → 2 occurrences
[0, 0, 0] → 1 occurrence

👉 Total = **1 + 2 + 3 = 6**

This matches the formula: `sum`$= \frac{n(n+1)}{2}$

where `n` = length of the consecutive zero sequence.


- Testing with a longer block, e.g. **6 zeros**, the formula still holds.

**Therefore:**
For any block of consecutive zeros of length `n`, the number of valid subarrays is:
`1 + 2 + ... + n = n(n+1)/2`

Here are two approaches, each using a different side of this formula:
- Approach 1: uses the closed-form formula `n(n+1)/2` (right hand side).
- Approach 2: directly sums `1 + 2 + ... + n` (left hand side).


Pretty neat, right? 😄

| Approach 1 | Approach 2 |
|---|---|
| - Traverse the array once.<br>- Count the length of each consecutive-zero block.<br>- Add `n(n+1)/2` for each block. | - Traverse the array once.<br>- Increment `zeroSequenceLength` for each zero.<br>- Add it to `result` immediately. |

```cpp
// Aproach 1
long long result = 0, zeroSequenceLength = 0;

for(int i = nums.size()-1; i >= 0; i--){
    if (nums[i] == 0) zeroSequenceLength++;
    if(i == 0 || nums[i] != 0){
        result += zeroSequenceLength * (zeroSequenceLength + 1);
        zeroSequenceLength = 0;
    }
}
return result/2;
```
```cpp
// Approach 2
long long result = 0, zeroSequenceLength = 0;

for (int num : nums) {
    if (num == 0) {
        zeroSequenceLength++;
        result += zeroSequenceLength;    // result += 1 + 2 + 3 + ...
    } else {
        zeroSequenceLength = 0;
    }
}
return result;
```


## 💬 My Thoughts

| Aproach 1 | Aproach 2 |
|----------|----------|
| - Implement from `right to left` to avoid multiple `nums.size()` calls. <br> - Postpone `/2` until the very end → fewer divisions → higher performance. | - Cleaner and more idiomatic. <br> - Each zero extends the block and contributes to `result` immediately. |


## ⏱️ Complexity
For both approaches
- **Time: O(n)**
  We traverse the array once, and for each element we do only constant-time work (increment, reset, or add).

- **Space: O(1)**
  We only use a few integer variables (`result`, `zeroSequenceLength`).

---

## Problem statement
Given an integer array `nums`, return the number of subarrays filled with `0`.

A **subarray** is a contiguous non-empty sequence of elements within an array.



**Example 1:**
Input: `nums = [1,3,0,0,2,0,0,4]`
Output: 6
Explanation:
There are 4 occurrences of `[0]` as a subarray.
There are 2 occurrences of `[0,0]` as a subarray.
There is no occurrence of a subarray with a size more than 2 filled with `0`. Therefore, we return 6.

**Example 2:**
Input: `nums = [0,0,0,2,0,0]`
Output: 9
Explanation:
There are 5 occurrences of `[0]` as a subarray.
There are 3 occurrences of `[0,0]` as a subarray.
There is 1 occurrence of `[0,0,0]` as a subarray.
There is no occurrence of a subarray with a size more than 3 filled with `0`. Therefore, we return 9.

**Example 3:**
Input: `nums = [2,10,2019]`
Output: 0
Explanation: There is no subarray filled with 0. Therefore, we return 0.


**Constraints:**
- `1 <= nums.length <= 105`
- `-10^9 <= nums[i] <= 10^9`
