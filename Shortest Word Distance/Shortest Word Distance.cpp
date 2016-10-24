// Shortest Word Distance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int shortestDistance(vector<string>& words, string word1, string word2) {
		int pos1 = 0;
		vector<int> pos;
		int ans = INT_MAX;
		for (int i = 0; i<words.size(); i++)
		{
			if (words[i] == word1)
			{
				pos.push_back(i);
			}
		}

		for(int pos1 : pos)
		{
			int start = pos1 - 1;
			if (start < 0) start = 0;
			int end = pos1 + 1;
			if (end >= words.size()) end = words.size() - 1;
			int count = 1;
			while (1)
			{
				if (words[start] == word2 || words[end] == word2)
					break;
				start--;
				end++;
				count++;
				if (start < 0) start = 0;
				if (end >= words.size()) end = words.size() - 1;
			}
			if (ans > count)
				ans = count;
		}
		return ans;
	}
};

int main()
{
	Solution solution;
	vector<string> v = { "a", "b", "c", "d", "d"};
	cout << solution.shortestDistance(v, "a", "d");
    return 0;
}

