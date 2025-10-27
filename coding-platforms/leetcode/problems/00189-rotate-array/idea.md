# 189. Rotate Array
*(Problem statement is cited at the end for reference)*


## 🔍 Idea

Let’s analyze by hand with a simple case:

- For a sequence of **3 zeros** `[0, 0, 0]`, all subarrays consisting only of zeros are:<br>
`[0]` → 3 occurrences<br>
`[0, 0]` → 2 occurrences<br>
`[0, 0, 0]` → 1 occurrence

👉 Total = **1 + 2 + 3 = 6**

This matches the formula: `sum`$= \frac{n(n+1)}{2}$, where `n` = length of the consecutive zero sequence.


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
- **Time: O(n)**<br>
  We traverse the array once, and for each element we do only constant-time work (increment, reset, or add).

- **Space: O(1)**<br>
  We only use a few integer variables (`result`, `zeroSequenceLength`).

---

## Problem statement
Given an integer array `nums`, rotate the array to the right by `k` steps, where `k` is non-negative.


**Example 1:**<br>
Input: `nums = [1,2,3,4,5,6,7], k = 3`<br>
Output: `[5,6,7,1,2,3,4]`<br>
Explanation:<br>
rotate 1 steps to the right: `[7,1,2,3,4,5,6]`
rotate 2 steps to the right: `[6,7,1,2,3,4,5]`
rotate 3 steps to the right: `[5,6,7,1,2,3,4]`

**Example 2:**<br>
Input: `nums = [-1,-100,3,99], k = 2`<br>
Output: `[3,99,-1,-100]`<br>
Explanation:<br>
rotate 1 steps to the right: `[99,-1,-100,3]`
rotate 2 steps to the right: `[3,99,-1,-100]`


**Constraints:**
- `1 <= nums.length <= 10^5`
- `-2^31 <= nums[i] <= 2^31-1`
- `0 <= k <= 10^5`


**Follow up:**
- Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
- Could you do it in-place with `O(1)` extra space?

