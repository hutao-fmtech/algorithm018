//题目地址：https://leetcode-cn.com/problems/trapping-rain-water/

//题目地址：https://leetcode.com/problems/trapping-rain-water/

int trap(int *height, int heightSize)
{
	int l = 0;
	int r = heightSize - 1;
	int l_lvl = 0;
	int r_lvl = 0;

	int ans = 0;

	while (l < r) {
		if (height[l] < height[r]) {
			if (height[l] > l_lvl) {
				l_lvl = height[l];
			} else {
				ans += (l_lvl - height[l]);
			}
			l++;

		} else {
			if (height[r] > r_lvl) {
				r_lvl = height[r];
			} else {
				ans += (r_lvl - height[r]);
			}
			r--;
		}
	}
	return ans;
}