
// 题目链接：https://leetcode-cn.com/problems/rotate-array/
void reverse(int *nums, int start, int end)
{
	int tmp;
	while (start < end) {
		tmp = nums[start];
		nums[start] = nums[end];
		nums[end] = tmp;
		++start;
		--end;
	}
}

void rotate(int *nums, int numsSize, int k)
{
	if (NULL == nums || 0 == k) {
		return;
	}
	k %= numsSize;
	reverse(nums, 0, numsSize - 1);
	reverse(nums, 0, k - 1);
	reverse(nums, k, numsSize - 1);
}
