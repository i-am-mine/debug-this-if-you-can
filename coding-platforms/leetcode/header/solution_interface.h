#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isPowerOfTwo(int n);
bool isPowerOfThree(int n);
bool isPowerOfFour(int n);
bool isPalindrome(int x);
bool isValid(string s);

int canBeTypedWords(string text, string brokenLetters);
int countSquares(std::vector<std::vector<int>>& matrix);
int findClosest(int x, int y, int z);
int maxFreqSum(string s);
int countStudents(vector<int>& students, std::vector<int>& sandwiches);
int lengthOfLongestSubstring(string s);
int romanToInt(string s);
int removeElement(std::vector<int>& nums, int val);
int removeDuplicates(std::vector<int>& nums);

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);

long long zeroFilledSubarray(std::vector<int>& nums);

void rotate(std::vector<int>& nums, int k);

std::vector<int> twoSum(std::vector<int>& nums, int target);
std::vector<int> getNoZeroIntegers(int n);

string longestCommonPrefix(vector<string>& strs);
