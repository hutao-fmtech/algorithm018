// 题目地址：https://leetcode-cn.com/problems/container-with-most-water/

// 题目地址：https://leetcode.com/problems/container-with-most-water/

int maxArea(int *height, int heightSize)
{
	int i = 0;
	int j = heightSize - 1;
	int ans = 0;
	int area = 0;
	while (i < j)
	{
		if (height[i] <= height[j])
		{
			area = height[i] * (j - i);
			++i;
		}
		else
		{
			area = height[j] * (j - i);
			--j;
		}

		if (area > ans)
		{
			ans = area;
		}
	}
	return ans;
}