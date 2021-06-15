// 题目地址：https://leetcode-cn.com/problems/valid-anagram/
// 题目地址：https://leetcode.com/problems/valid-anagram/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;

class Solution
{
public:
	bool isAnagram(string s, string t)
	{
		unordered_map<char, int> map;
		if (s.size() != t.size())
		{
			return false;
		}
		for (int i = 0; i < s.size(); i++)
		{
			map[s[i]]++;
			map[t[i]]--;
		}

		for (auto item : map)
		{
			if (item.second != 0)
			{
				return false;
			}
		}

		return true;
	}
};

int main()
{
	string s = "abd";
	string t = "bda";
	Solution *solu = new Solution();
	if (solu->isAnagram(s, t))
	{
		cout << "is Anagram" << endl;
	}
	else
	{
		cout << "not is Anagram" << endl;
	}
}