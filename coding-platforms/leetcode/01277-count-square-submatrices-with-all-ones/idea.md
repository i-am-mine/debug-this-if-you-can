# 1277. Count Square Submatrices with All Ones
*(Problem statement is cited at the end for reference)*


## 🔍 Idea
TBD


## 💬 My Thoughts
TBD


## ⏱️ Complexity
TBD

---

## Problem statement
Given a `m * n` matrix of ones and zeros, return how many square submatrices have all ones.

**Example 1:**<br>
Input:
```python
matrix =
[
    [0, 1, 1, 1],
    [1, 1, 1, 1],
    [0, 1, 1, 1]
]
```
Output: 15<br>
Explanation:<br>
There are 10 squares of side 1.<br>
There are 4 squares of side 2.<br>
There is  1 square of side 3.<br>
Total number of squares = 10 + 4 + 1 = 15.<br>

**Example 2:**<br>
Input:
```python
matrix =
[
  [1, 0, 1],
  [1, 1, 0],
  [1, 1, 0]
]
```
Output: 7<br>
Explanation:<br>
There are 6 squares of side 1.<br>
There is 1 square of side 2.<br>


**Constraints:**
- `1 <= arr.length <= 300`
- `1 <= arr[0].length <= 300`
- `0 <= arr[i][j] <= 1`
