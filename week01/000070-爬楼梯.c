// 题目链接：https://leetcode-cn.com/problems/climbing-stairs/

// 题目链接：https://leetcode.com/problems/climbing-stairs/

/* 感受
1. 提高效率就是要让计算机少做事情。如果少做事情，就是避免做重复的事情。
2. 对于动态规划问题，就是要找到重叠子，通过存储已经计算过的状态，避免重复计算。
3. 没有思路时，先想暴力法。
4. 有用链接：https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie-qing-an-shun-xu-yue-du/dong-tai-gui-hua-xiang-jie-jin-jie
*/
int climbStairs(int n)
{
	if (n < 3)
	{
		return n;
	}

	int f1 = 1;
	int f2 = 2;

	for (int i = 3; i <= n; i++)
	{
		int f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
	}
	return f2;
}