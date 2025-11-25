#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isPowerOfTwo(int n);
bool isPowerOfThree(int n);
bool isPowerOfFour(int n);
bool isPalindrome(int x);
bool isValid(string s);
bool isValidSudoku(std::vector<std::vector<char>>& board);
bool hasSameDigits(string s);
bool hasPathSum(TreeNode* root, int targetSum);
bool isAnagram(string s, string t);
bool kLengthApart(std::vector<int>& nums, int k);
bool isOneBitCharacter(std::vector<int>& bits);

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
int totalMoney(int n);
int countOperations(int num1, int num2);
int titleToNumber(string columnTitle);
int majorityElement(std::vector<int>& nums);
int numSub(string s);
int findFinalValue(std::vector<int>& nums, int original);
int intersectionSizeTwo(std::vector<std::vector<int>>& intervals);
int countPalindromicSubsequence(string s);
int minimumOperations(std::vector<int>& nums);
int maxSumDivThree(std::vector<int>& nums);
int smallestRepunitDivByK(int k);

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
ListNode* rotateRight(ListNode* head, int k);
ListNode* modifiedList(std::vector<int>& nums, ListNode* head);

long long zeroFilledSubarray(std::vector<int>& nums);

void rotate(std::vector<int>& nums, int k);

std::vector<int> twoSum(std::vector<int>& nums, int target);
std::vector<int> getNoZeroIntegers(int n);
std::vector<int> plusOne(std::vector<int>& digits);
std::vector<int> getSneakyNumbers(std::vector<int>& nums);
std::vector<std::vector<int>> generate(int numRows);
std::vector<int> countBits(int n);
std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2);
std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2);
std::vector<bool> prefixesDivBy5(std::vector<int>& nums);

string longestCommonPrefix(std::vector<string>& strs);
string addBinary(string a, string b);



