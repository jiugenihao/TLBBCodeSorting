/////////////////////////////////////////
//文件名称：SortUtility.h
//功能描述：排序算法
//        
/////////////////////////////////////////
#pragma once

namespace SortUtility
{
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	// 直接插入排序---升序
	// array[len]乱序序列
	// array[0...i-1]为有序序列
	// array[i]为待加入有序序列的元素
	// array[i+1...len-1]为待排序的无序序列
	// 1.使用一个局部变量保存array[i],充当哨兵
	// 2.在当前有序区array[0..i-1]中查找array[i]的正确插入位置k(0≤k≤i-1)；
	// 3.将array[k．．i-1]中的记录均后移一个位置，腾出k位置上的空间插入array[i]
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	template <class T>
	void InsertSort(T list[], int len)
	{
		if (len <= 0)
		{
			return;
		}

		// 外层循环从第二个元素开始 list[0]为有序序列
		for (int i = 1; i < len; ++i)
		{
			if (list[i] < list[i - 1])
			{
				T sentry = list[i];	// 哨兵
				int k = i - 1;
				for ( ; k >= 0 && sentry < list[k]; --k)
				{
					list[k + 1] = list[k];
				}

				list[k + 1] = sentry;	// 以为循环的最后一步--k了,所以最后一个需要加回来
			}
		}
	}
}
