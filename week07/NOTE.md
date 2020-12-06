学习笔记

**高级搜索**
1. 剪枝：a.踢除一些不可能的解空间 b. 剔除已经计算过的分支。
2. 双向BFS：搜索方向优化，始终选择解空间小的方向。
3. 启发式搜索（A*)

**平衡树**
1. AVL：TODO
2. 红黑树：TODO

**并查集**
1. 查并集相对比较简单，只需要记住它的几个API：`union_nodes`、`get_count`、`connected`。可以强记下面模版

```c++

class UF
{
private:
	// 记录连通分量
	int count;
	// 节点 x 的节点是 parent[x]
	int *parent;
    // 记录此节点的，连通节点数量。
	int *size;

private:
	int find(int x)
	{
		// 根节点的 parent[x] == x
		while (parent[x] != x)
		{
			parent[x] = parent[parent[x]];
			x = parent[x];
		}
		return x;
	}

public:
	// 构造函数，n 为图的节点总数
	UF(int n)
	{
		// 一开始互不连通
		count = n;
		// 父节点指针初始指向自己
		parent = new int[n];
		size = new int[n];
		for (int i = 0; i < n; i++)
		{
			parent[i] = i;
			size[i] = 1;
		}
	}

	void union_nodes(int p, int q)
	{
		int rootP = find(p);
		int rootQ = find(q);
		if (rootP == rootQ)
			return;
		// 小树接到大树下面，较平衡

		if (size[rootP] > size[rootQ])
		{
			parent[rootQ] = rootP;
			size[rootP] += size[rootQ];
		}
		else
		{
			parent[rootP] = rootQ;
			size[rootQ] += size[rootP];
		}

		count--;
	}

	int get_count() { return count; }

	bool connected(int p, int q)
	{
		int rootP = find(p);
		int rootQ = find(q);
		return rootP == rootQ;
	}
};
```
