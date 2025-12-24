#include <iostream>
using namespace std;
const int max1 = 50;//小球的最大个数，可以在此进行修改
int QuickPass(int num[], int low, int high)//进行一次挖坑的分类排序，将标准元素放入应在的位置
				//QuickSort(num, 0, n);
{
	int down = low;//初始位置
	int up = high;//最后方的位置
	num[0] = num[down];//将标准元素放入到数组的零号单元,此时标准元素的位置留下一个坑
	//在符合down小于up的规则下，down位置留下的坑让up去找，up位置留下的坑让down去找,找到后将元素填入坑中，然后这个元素的位置变为坑
	while (down < up)
	{
		//从最后方开始向前寻找第一个比标准元素小的元素
		while (down<up && num[up]>num[0])
			up--;
		//将找到的元素放入坑中，然后在这个找到的元素位置留下一个坑
		if (down < up)
			num[down++] = num[up];
		//从初始位置开始向后寻找第一个比标准元素大的元素
		while (down < up && num[down] < num[0])
			down++;
		//将找到的元素放入坑中，然后在这个找到的元素位置留下一个坑
		if (down < up)
			num[up--] = num[down];
	}
	//将标准元素放入坑中，即完成一轮分类,左侧为小于标准元素的元素，右侧为等于或者大于的元素
	num[down] = num[0];
	//函数返回的是标准元素所放入的位置，作为下次分类的边界之一
	return down;
}
void QuickSort(int num[], int low, int high)
				//QuickSort(num, 0, n);
{
	int middle;//标准元素最终放入的位置，作为下次分类的边界之一
	if (low < high)
	{
		middle = QuickPass(num, low, high);//先进行一次分类
		QuickSort(num, low, middle - 1);//对分类后的边界左边的小数组进行递归分类
		QuickSort(num, middle + 1, high);//对分类后的边界右边的小数组进行递归分类
	}
}
void print(int x)
{
	if (x == 1)
		cout << "红";
	if (x == 2)
		cout << "白";
	if (x == 3)
		cout << "蓝";
}
int main()
{
	while (true)
	{
		int n = 0, m = 0;
		cout << "请输入小球的序列（1为红，2为白，3为蓝,以0结束输入,以-1结束程序）：";
		int* num = new int[max1];
		for (int i = 1; i < max1; i++)
		{
			cin >> m;
			if (m == -1)
			{
				delete[]num;
				return 0;
			}
			if (m == 0)break;
			num[i] = m;
			n++;
		}
		cout << "排序前：";
		for (int i = 1; i <= n; i++)
		{
			print(num[i]);
			cout << " ";
		}
		cout << endl;
		QuickSort(num, 0, n);
		cout << "有序排列后为：";
		for (int i = 1; i <= n; i++)
		{
			if (num[i - 1] != num[i])
				cout << endl;
			print(num[i]);
		}
		cout << endl;
		delete[]num;
	}
	return 0;
}