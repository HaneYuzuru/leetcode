# leetcode
leetcode exercises,algorithms part!


TwoSum:
	1.key point: unorderd_map(16ms), map(24ms)
	2.大概是前50%的样子，并不知道如何进一步提升性能

addTwoNums:
	1.新建ListNode对象的时候没有分配存储空间导致bus error
	2.原题设计上null pointer使用了NULL而不是nullptr
	3.考虑将测试用例变成用户输入
	4.考虑将在不同对象上的相同操作提炼为子函数
	5.c++链表操作复习

Longest Substring Without Repeating Characters:
	1.map内部根据键值红黑树排序，一开始以为根据插入时间排序导致错误
	2.情况分为最长子串在字符串开头，中间，以及结尾，需要用不同的方式进行处理
	3.tag中hash table没有用到，可能是提高效率的关键点？（不过感觉不是
	4.代码还是不够优雅（嘤

String to Integer (atoi):
	1.没有考虑到很多很多情况，比如溢出，字符串不是单纯的数字串，数字和字母结合的字符串需要截取前面部分的数字进行转换而不是单纯返回0，空格etc
	2.遇到了segmentation fault，先定位再调试（。
	3.一开始性能不佳，通过把一些判断移出循环是性能到达了平均水平

Binary Tree Inorder Traversal:
	1.使用了递归算法，因为非递归并没有想出来（垢
	2.传参数方面出了一点问题

Unique Binary Search Trees:
	1.可以用递归的思想，不同根结点情况下叶结点组合情况可由之前计算所得的叶结点数计算得出
	2.使用数组方式存储途经所有结果是为了避免重复计算，在两边相同结点数的处理方法上优点不优雅（。

Same Tree:
	1.没有什么难度

Symmetric Tree:
	1.同上

Binary Tree Level Order Traversal:
	1.可以通过保留两个queue来提高效率
	2.实现的时候其实可以不在循环中声明将要push到vector中的vector，因为不是push进指针，所以下一次对同一个vector对象的改写其实不会影响到已经在别的vector中的前一次push进的vector（我的表述能力。。。。

Binary Tree Level Order Traversal II:
	1.初版用了stack存放原本的顺序level排序
	2.会再版提高性能

Balanced Binary Tree:
	1.初版使用了map，性能不佳，换成unordered_map以后有些许提升