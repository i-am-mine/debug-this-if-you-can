#pragma once
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>

bool isPowerOfTwo(int n);
bool isPowerOfThree(int n);
bool isPowerOfFour(int n);

int countSquares(std::vector<std::vector<int>>& matrix);
int maxFreqSum(string s);
int findClosest(int x, int y, int z);

long long zeroFilledSubarray(std::vector<int>& nums);

void rotate(std::vector<int>& nums, int k);

std::vector<int> twoSum(std::vector<int>& nums, int target);
