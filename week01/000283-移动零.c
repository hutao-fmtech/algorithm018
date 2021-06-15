// 题目地址：https://leetcode-cn.com/problems/move-zeroes/

// 题目地址：https://leetcode.com/problems/move-zeroes/

void moveZeroes(int *nums, int numsSize)
{
	int last_pos = 0;
	int tmp;
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] != 0)
		{
			tmp = nums[last_pos];
			nums[last_pos++] = nums[i];
			nums[i] = tmp;
		}
	}
}