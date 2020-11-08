//题目地址：https://leetcode-cn.com/problems/combinations/

//题目地址：https://leetcode.com/problems/combinations/

class Solution {
    private:
	vector<vector<int> > ans;
	vector<int> path;

	void backtracking(int n, int k, int startIndex)
	{
		if (path.size() == k) {
			ans.push_back(path);
			return;
		}
		for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) {
			path.push_back(i);
			backtracking(n, k, i + 1);
			path.pop_back();
		}
	}

    public:
	vector<vector<int> > combine(int n, int k)
	{
        // 为什么这里要从1开始？
		backtracking(n, k, 1);
		return ans;
	}
};