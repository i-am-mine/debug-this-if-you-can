# 3516. Find Closest Person
*(Problem statement is cited at the end for reference)*


## 🔍 Idea
TBD


## 💬 My Thoughts
TBD


## ⏱️ Complexity
TBD

---

## Problem statement
You are given three integers `x`, `y`, and `z`, representing the positions of three people on a number line:

`x` is the position of Person 1.
`y` is the position of Person 2.
`z` is the position of Person 3, who does not move.
Both Person 1 and Person 2 move toward Person 3 at the same speed.

Determine which person reaches Person 3 first:

Return `1` if Person 1 arrives first.
Return `2` if Person 2 arrives first.
Return `0` if both arrive at the same time.
Return the result accordingly.



**Example 1:**<br>
Input: `x = 2, y = 7, z = 4`<br>
Output: 1<br>
Explanation:<br>
Person 1 is at position 2 and can reach Person 3 (at position 4) in 2 steps.<br>
Person 2 is at position 7 and can reach Person 3 in 3 steps.<br>
Since Person 1 reaches Person 3 first, the output is 1.<br>


**Example 2:**<br>
Input: `x = 2, y = 5, z = 6`<br>
Output: 2<br>
Explanation:<br>
Person 1 is at position 2 and can reach Person 3 (at position 6) in 4 steps.<br>
Person 2 is at position 5 and can reach Person 3 in 1 step.<br>
Since Person 2 reaches Person 3 first, the output is 2.<br>


**Example 3:**<br>
Input: `x = 1, y = 5, z = 3`<br>
Output: 0<br>
Explanation:<br>
Person 1 is at position 1 and can reach Person 3 (at position 3) in 2 steps.<br>
Person 2 is at position 5 and can reach Person 3 in 2 steps.<br>
Since both Person 1 and Person 2 reach Person 3 at the same time, the output is 0.<br>


**Constraints:**
- `1 <= x, y, z <= 100`
