// 题目地址：https://leetcode-cn.com/problems/plus-one/

// 题目地址：https://leetcode.com/problems/plus-one/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *plusOne(int *digits, int digitsSize, int *returnSize)
{
	for (int i = digitsSize - 1; i >= 0; i--) {
		if (9 == digits[i]) {
			digits[i] = 0;
		} else {
			digits[i]++;
			int *ans = malloc(sizeof(int) * digitsSize);
			memcpy(ans, digits, digitsSize);
			*returnSize = digitsSize;
			return ans;
		}
	}
	*returnSize = digitsSize + 1;
	int *ans = calloc(*returnSize, sizeof(int));
	ans[0] = 1;
	return ans;
}