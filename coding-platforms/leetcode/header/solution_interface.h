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
bool isValidSudoku(std::vector<std::vector<char>>& board);
bool hasSameDigits(string s);

int canBeTypedWords(string text, string brokenLetters);
int countSquares(std::vector<std::vector<int>>& matrix);
int findClosest(int x, int y, int z);
int maxFreqSum(string s);
int countStudents(vector<int>& students, std::vector<int>& sandwiches);
int lengthOfLongestSubstring(string s);
int romanToInt(string s);
int removeElement(std::vector<int>& nums, int val);
int removeDuplicates(std::vector<int>& nums);
int strStr(string haystack, string needle);
int searchInsert(std::vector<int>& nums, int target);
int lengthOfLastWord(string s);
int finalValueAfterOperations(std::vector<string>& operations);
int mySqrt(int x);
int climbStairs(int n);

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
ListNode* rotateRight(ListNode* head, int k);

long long zeroFilledSubarray(std::vector<int>& nums);

void rotate(std::vector<int>& nums, int k);

std::vector<int> twoSum(std::vector<int>& nums, int target);
std::vector<int> getNoZeroIntegers(int n);
std::vector<int> plusOne(std::vector<int>& digits);

string longestCommonPrefix(std::vector<string>& strs);
string addBinary(string a, string b);



