//题目地址：https://leetcode-cn.com/problems/permutations-ii/submissions/

//题目地址：https://leetcode.com/problems/permutations-ii/submissions/

class Solution {
    private:
	void backtracking(vector<int> &nums, vector<int> &cur, vector<bool> &used)
	{
		if (cur.size() == nums.size()) {
			ans.push_back(cur);
			return;
		}

		for (int i = 0; i < nums.size(); i++) {
			if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
				continue;
			}

			if (used[i] == false) {
				used[i] = true;
				cur.push_back(nums[i]);
				backtracking(nums, cur, used);
				cur.pop_back();
				used[i] = false;
			}
		}
	}

    public:
	vector<vector<int> > ans;
	vector<vector<int> > permuteUnique(vector<int> &nums)
	{
		sort(nums.begin(), nums.end());
		vector<bool> used(nums.size(), false);
		vector<int> cur;
		backtracking(nums, cur, used);
		return ans;
	}
};