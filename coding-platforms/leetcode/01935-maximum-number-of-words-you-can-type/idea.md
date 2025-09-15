# 1935. Maximum Number of Words You Can Type
*(Problem statement is cited at the end for reference)*


## 🔍 Idea
TBD


## 💬 My Thoughts
TBD


## ⏱️ Complexity
TBD

---

## Problem statement
There is a malfunctioning keyboard where some letter keys do not work. All other keys on the keyboard work properly.

Given a string `text` of words separated by a single space (no leading or trailing spaces) and a string `brokenLetters` of all distinct letter keys that are broken, return the number of words in `text` you can fully type using this keyboard.

**Example 1:**<br>
Input: `text = "hello world", brokenLetters = "ad"`
Output: 1<br>
Explanation: We cannot type "world" because the 'd' key is broken.<br>


**Example 2:**<br>
Input: `text = "leet code", brokenLetters = "lt`
Output: 1<br>
Explanation: We cannot type "leet" because the 'l' and 't' keys are broken.<br>


**Example 3:**<br>
Input: `text = "leet code", brokenLetters = "e"`
Output: 0<br>
Explanation: We cannot type either word because the 'e' key is broken.<br>


**Constraints:**
- `1 <= text.length <= 104`
- `0 <= brokenLetters.length <= 26`
- `text` consists of words separated by a single space without any leading or trailing spaces.
- Each word only consists of lowercase English letters.
- `brokenLetters` consists of distinct lowercase English letters.


