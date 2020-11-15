学习笔记
## 暴力搜素
### 广度优先搜索（Breadth-First—Search)
1. 遍历当前节点的所有相邻节点。
2. 队列实现，对队列头部进行pop。
3. 图遍历时，可能存在环，要避免重复访问。
4. 最短问题，可以条件反射想想BFS。

```c++
void bfs(Node *root)
{
	map<int, int> visited;
	if (!root)
		return;

	queue<Node *> queueNode;
	queueNode.push(root);

	while (!queueNode.empty()) {
		Node *node = queueNode.top();
		queueNode.pop();
		if (visited.count(node->val))
			continue;
		visited[node->val] = 1;

		for (int i = 0; i < node->children.size(); ++i) {
			queueNode.push(node->children[i]);
		}
	}

	return;
}
```

### 深度搜索优先（Deepth-First—Search）
1. 递归寻找当前节点的节点
2. 实现时，可以通过递归调用（系统栈），或是循环（手动维护栈）
```c++


map<int, int> visited;

void dfs(Node *root)
{
	// terminator
	if (!root)
		return;

	if (visited.count(root->val)) {
		// already visited
		return;
	}

	visited[root->val] = 1;

	// process current node here.

	// ...
	for (int i = 0; i < root->children.size(); ++i) {
		dfs(root->children[i]);
	}
	return;
}

```

```c++
// 循环
void dfs(Node *root)
{
	map<int, int> visited;
	if (!root)
		return;

	stack<Node *> stackNode;
	stackNode.push(root);

	while (!stackNode.empty()) {
		Node *node = stackNode.top();
		stackNode.pop();
		if (visited.count(node->val))
			continue;
		visited[node->val] = 1;

		for (int i = node->children.size() - 1; i >= 0; --i) {
			stackNode.push(node->children[i]);
		}
	}

	return;
}
```


## 非暴力搜索

### [贪心算法](https://zh.wikipedia.org/wiki/贪心算法)

- 贪心在每一步选择中选出局部最好的结果，并希望获得全局最优解。
- 然而事实往往事与愿违，每次选择最优结果不一定是最优的结果。

**适用场景：**问题能够分解为子问题解决，子问题的最优解能够递推到最终问题的最优解，这种子问题最优解称为最优子结构。

**与动态规划的区别：**对每个子问题，贪心算法都必须作出选择且不能回退。而动态规划则会保存以前的运算结果，并根据以前的结果对当前进行选择，且可以回退。

### [动态规划](https://zh.wikipedia.org/wiki/动态规划)

- 动态规划之于贪心算法的不同是：对每个字问题的解决方案都做出选择，并且能够回退。
- 动态规划回保存之前的运算结果，根据以前的运算结果，与当前结果比较得出最优解，并且可以有回退功能。（其实是一种特殊的回溯算法）
- 通常许多子问题非常相似，为此动态规划法试图仅仅解决每个子问题一次，从而减少计算量：一旦某个给定子问题的解已经算出，则将其记忆化存储，以便下次需要同一个子问题解之时直接查表。这种做法在重复子问题的数目关于输入的规模呈指数增长时特别有用。

### 二分查找

1. 单调性（有序序列）。
2. 存在上下界。
3. 能够通过索引访问（随机访问）。

```c++

int binarySearch(const vector<int> &nums, int target)
{
	int left = 0, right = (int)nums.size() - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] == target)
			return mid;
		else if (nums[mid] < target)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return -1;
}

```