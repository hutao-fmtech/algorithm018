// 题目地址：https://leetcode-cn.com/problems/two-sum/

// 题目地址：https://leetcode.com/problems/two-sum/

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
	int *ans = (int *)malloc(sizeof(int) * 2);
	for (int i = 0; i < numsSize - 1; i++)
	{
		int left = target - nums[i];
		for (int j = i + 1; j < numsSize; j++)
		{
			if (nums[j] == left)
			{
				ans[0] = i;
				ans[1] = j;
				*returnSize = 2;
				return ans;
			}
		}
	}
	*returnSize = 0;
	return NULL;
}

class Solution
{
public:
	vector<int> twoSum(vector<int> &nums, int target)
	{
		map<int, int> helper_map;
		vector<int> ans;
		int len = nums.size();
		for (int i = 0; i < len; i++)
		{
			if (helper_map.count(target - nums[i]))
			{
				ans.push_back(helper_map[target - nums[i]]);
				ans.push_back(i);
				return ans;
			}
			helper_map[nums[i]] = i;
		}
		return ans;
	}
};