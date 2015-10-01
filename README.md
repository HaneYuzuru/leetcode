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