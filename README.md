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