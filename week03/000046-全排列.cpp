// 题目地址：https://leetcode-cn.com/problems/permutations/

// 题目地址：https://leetcode.com/problems/permutations/

class Solution {
    private:
	void backtrack(vector<int> &nums, vector<int> &cur, unordered_set<int> &used, vector<vector<int> > &ans)
	{
		if (cur.size() == nums.size()) {
			ans.push_back(cur);
			return;
		}
		for (int i = 0; i < nums.size(); i++) {
			if (used.count(nums[i])) {
				continue;
			}
			used.insert(nums[i]);
			cur.push_back(nums[i]);
			backtrack(nums, cur, used, ans);
			used.erase(nums[i]);
			cur.pop_back();
		}
	}

    public:
	vector<vector<int> > permute(vector<int> &nums)
	{
		vector<int> cur;
		unordered_set<int> used;
		vector<vector<int> > ans;
		backtrack(nums, cur, used, ans);
		return ans;
	}
};