学习笔记

- 递归模版

```c++
void recursion(int level, int param) {
    // 1. recursion termimator
    if (level > MAXLEVEL) {
        // post result
        return;
    }

    // 2. process current logic
    process(level,param);

    // 3. drill down
    recursion(level+1,int param);

    // 4. reverse current level status if needed

}

```
- 分治和回溯都是特殊的递归。特殊之处：简单的递归就是只有一个子问题，而分治时，是将问题进行高效的分解，所以分治要在第四步合并子问题答案。回溯就是穷举所有的可能性，对每一种可能进行判断，不合适就是尝试另一条路径。
