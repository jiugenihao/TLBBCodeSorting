/////////////////////////////////////////
//文件名称：SortUtility.h
//功能描述：排序算法
//        
/////////////////////////////////////////
#pragma once
#include "BaseDefine.h"
namespace SortUtility
{
	// 交换元素
	template <class T>
	void Swap(T* a, T* b)
	{
		T temp = *b;
		*b = *a;
		*a = temp;
	}

	// 打印元素
	template <class T>
	void Print(T list[], int len)
	{
		if (len <= 0) return;
		for (int i = 0; i < len; i++)
		{
			cout << list[i] << " ";
		}
		cout << endl;
	}

	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	// 插入排序---直接插入排序---升序
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

				list[k + 1] = sentry;	// 因为循环的最后一步--k了,所以最后一个需要加回来
			}
		}
	}

	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	// 插入排序---希尔排序---升序
	// array[0...len-1]乱序序列
	// 1.将一个数据序列分成若干组，每组由相隔若干距离delta的元素组成，delta称为增量，
	//   在一个组内采用直接插入排序算法进行排序
	// 2.delta的初值通常为数据序列长度的一半，以后每趟增量逐渐缩小，最后值为1，随着
	//   增量delta的减小，组数也减少，组内元素个数增加，整个序列则接近有序。
	// 3.当增量为1时，只有1组，元素是整个序列，再进行一次直接插入排序即可
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	template <class T>
	void ShellSort(T list[], int len)
	{
		if (len <= 0)
		{
			return;
		}

		// 将序列分成delta组，增量减半
		for (int delta = len / 2; delta > 0; delta /= 2)
		{
			// 一趟分若干组，一组元素距离delta
			for (int i = delta; i < len; ++i)
			{
				// 组内进行直接插入排序
				T sentry = list[i];
				int k = 0;
				for (k = i - delta; k >= 0 && sentry < list[k]; k -= delta)
				{
					list[k + delta] = list[k];
				}
				list[k + delta] = sentry;	// 因为循环的最后一步k = k - delta了, 所以这里需要加回来
			}
		}
	}

	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	// 交换排序---冒泡排序---升序
	// 比较相邻两个关键字的值，如果反序则交换。
	// 若按升序排序，每一趟将被扫描的数据序列中最大关键字交换到最后位置，就像气泡从水里冒出一样
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	template <class T>
	void BubbleSort(T list[], int len)
	{
		if (len <= 0)
		{
			return;
		}

		bool exchange = true;
		for (int i = 1; i < len && exchange; ++i)
		{
			exchange = false;
			for (int j = 0; j < len - i; ++j)
			{
				if (list[j] > list[j + 1])
				{
					Swap(&list[j], &list[j + 1]);
					exchange = true;
				}
			}
		}
	}

	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	// 交换排序---快速排序---升序
	// 1.在数据序列中选取一个值作为比较基准值
	// 2.每趟从数据序列的两端开始交替执行，将小于基准值的元素交换到序列前端，大于基准
	//   值的元素交换到序列后端，介于两者之间的位置就成为基准值的最终位置(i==j)
	// 3.同时，序列被划分为两个子序列，再用同样的方法对两个子序列进行排序，直到子序列
	//   的长度为1，则完成排序
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	template <class T>
	void QuickSort(T list[], int len, int low, int high)
	{
		if (0 <= low && low < len && 0 <= high && high < len && low < high)
		{
			int i = low;
			int j = high;
			T vote = list[i];
			while (i != j)
			{
				while (i < j && vote < list[j])
				{
					j--;
				}
				if (i < j) list[i++] = list[j];
				while (i < j && list[i] <= vote)
				{
					i++;
				}
				if (i < j) list[j--] = list[i];
			}
			list[i] = vote;
			QuickSort(list, len, low, j - 1);
			QuickSort(list, len, i + 1, high);
		}
	}
	template <class T>
	void QuickSort(T list[], int len)
	{
		if (len <= 0)
			return;
		QuickSort(list, len, 0, len - 1);
	}

	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	// 选择排序---直接选择排序---升序
	// 1.第一趟从n个元素的数据序列中选出关键字值最小的元素，并放在序列的最前的位置。
	// 2.下一趟再从n-1个元素中选出关键字值最小的元素，放在次前的位置。
	// 3.以此类推，经过n-1趟完成排序
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	template <class T>
	void SelectSort(T list[], int len)
	{
		if (len <= 0)
			return;
		for (int i = 0; i < len - 1; ++i)
		{
			int min = i;
			for (int j = i + 1; j < len; ++j)
			{
				if (list[j] < list[min])
				{
					min = j;
				}
			}
			if (min != i)
			{
				Swap(&list[i], &list[min]);
			}
			
		}
	}

	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	// 交换排序---堆排序---大顶堆---升序
	// 1.将数据序列建立成堆序列
	// 2.采用选择排序思路，每趟将根节点交换到最后，再将剩余的数据序列调整成堆序列
	// 3.如此重复，直到排序完成
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	template <class T>
	void MaxHeapify(T list[], int i, int len)
	{
		int left  = i * 2 + 1;
		int right = i * 2 + 2;
		int large = i;

		if (left < len && list[left] > list[large])
		{
			large = left;
		}
		if (right < len && list[right] > list[large])
		{
			large = right;
		}
		if (large != i)
		{
			Swap(&list[large], &list[i]);
			MaxHeapify(list, large, len);
		}
	}
	template <class T>
	void CreateMaxHeap(T list[], int len)
	{
		int i = len / 2 - 1;
		for ( ; i >= 0; --i)
		{
			MaxHeapify(list, i, len);
		}
	}
	template <class T>
	void MaxHeapSort(T list[], int len)
	{
		if (len <= 0)
			return;
		CreateMaxHeap(list, len);

		for (int i = len - 1; i > 0; --i)
		{
			Swap(&list[0], &list[i]);
			MaxHeapify(list, 0, i);
		}
	}

	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	// 交换排序---堆排序---小顶堆---降序
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	template <class T>
	void MinHeapify(T list[], int start, int end)
	{
		// 建立父节点指标和子节点指标
		int dad = start;
		int son = dad * 2 + 1;
		while (son <= end)  //若子节点指标在范围内才做比较
		{
			// 先比较两个子节点大小，选择最小的
			if (son + 1 <= end && list[son] > list[son + 1])
				son++;

			// 如果父节点大於子节点代表调整完毕，直接跳出函数
			if (list[dad] <= list[son]) 
				return;
			else
			{
				//否则交换父子内容再继续子节点和孙节点比较
				Swap(&list[dad], &list[son]);
				dad = son;
				son = dad * 2 + 1;
			}
		}
	}
	
	template <class T>
	void MinHeapSort(T list[], int len)
	{
		if (len <= 0)
			return;

		int i = 0;
		for (i = len / 2 - 1; i >= 0; i--)
			MinHeapify(list, i, len - 1);

		//先将第一个元素和已排好元素前一位做交换，再重新调整，直到排序完毕
		for (i = len - 1; i > 0; i--)
		{
			Swap(&list[0], &list[i]);
			MinHeapify(list, 0, i - 1);
		}
	}


	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	// 归并排序---二路归并排序
	// N个元素的数据序列可看成是由N个长度为1的排序子序列组成，反复将相邻的两个子序列
	// 合并成一个排序的子序列，直到合并成一个序列，排序完成
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	// 单次归并操作，将两个有序子序列归并成一个有序序列
	// low low+1 ... mid mid+1 mid+2 ... high
	// |_ _ _ _ _ _ _ |  |_ _ _ _ _ _ _ _ _|
	// i                 j
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	template <class T>
	void Merge(T list[], T aux[], int low, int mid, int high)
	{
		int i = low, j = mid + 1;
		// 先将list[low...high]拷贝到aux[low...high]
		for (int k = low; k <= high; k++)
		{
			aux[k] = list[k];
		}
		
		for (int k = low; k <= high; k++)
		{
			if		(i > mid)			list[k] = aux[j++];		// 左半边用尽，取右边元素
			else if (j > high)			list[k] = aux[i++];		// 右半边用尽，取左边元素
			else if (aux[i] < aux[j])	list[k] = aux[i++];		// 左半边的当前元素小于右半边的当前元素，取左半边的当前元素
			else						list[k] = aux[j++];		// 左半边的当前元素大于等于右半边的当前元素，取右半边的当前元素
		}
	}

	template <class T>
	void MergeSort(T list[], int len)
	{
		if (len <= 0) return;

		T* aux = new T[len];
		if (!aux) return;

		//Merge(list, aux, 0, len / 2 - 1, len - 1);

		// 0,6,3,2,7,5,4,9,1,8  每2个元素归并
		Merge(list, aux, 0, 0, 1);
		Merge(list, aux, 2, 2, 3);
		Merge(list, aux, 4, 4, 5);
		Merge(list, aux, 6, 6, 7);
		Merge(list, aux, 8, 8, 9);

		// step = 1
		//Merge(list, aux, i * 2, i * 2, i * 2 + 1);			//
																//
		// 每4个元素归并											//
		Merge(list, aux, 0, 1, 3);								//
		Merge(list, aux, 4, 5, 7);								//
		Merge(list, aux, 8, 8, 9);								//
		//Merge(list, aux, i * 4, i * 4 + 1, i * 4 + 3);		//
																//
		// 每8个元素归并											//
		Merge(list, aux, 0, 3, 7);								//
		Merge(list, aux, 8, 8, 9);								//
		//Merge(list, aux, i * 8, i * 8 + 3, i * 8 + 7);		//
																//
		// 每16个元素归并											//
		Merge(list, aux, 0, 7, 9);								//
		//Merge(list, aux, i * 16, i * 16 + 7, i * 16 + 15);	//

		delete[] aux;
		aux = nullptr;
	}

} // namespace SortUtility
