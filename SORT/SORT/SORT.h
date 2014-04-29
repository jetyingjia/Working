#ifndef _SORT_HPP_
#define _SORT_HPP_


template <typename T>
class SORT 
{
public:
	void show_value(T &a);
	void initial_sort(T &a, int N);
	void insert_sort(T &a);
	void bubble_sort(T &a);
	void qsort(T &a, int left, int right);
	void qsort1(T &a, int left, int right);
	void qsort2(T &a, int left, int right);
	void merge_sort(T &a, int first, int last);
	void select_sort(T &a);
	void shell_sort(T &a);
	void shell_sort1(T &a);
	void minHeap_sort(T &a);
	void counting_sort(T &a, int k);
	void radix_sort(T &a);
private:
	void merge_array(T &a, int first, int mid, int last);
	void build_minHeap(T &a, int length);
	void minHeapify(T &a, int pos, int i);
};

template <typename T>
void swap(T &a, T &b)
{
	T temp;
	temp = b;
	b = a;
	a = temp;
}

//显示数据
template <typename T>
void SORT<T>::show_value(T &a)
{
	int length = a.size();
	for(int i = 0; i < length; i++)
	{
		std::cout << a[i] << " ";
	}
}

//初始化数据
template <typename T>
void SORT<T>::initial_sort(T &a, int N)
{
	for (int i = 0; i < N; i++)
	{
		T::value_type temp;
		std::cin>>temp;
		a.push_back(temp);
	}
}

//插入排序
template <typename T>
void SORT<T>::insert_sort(T &a)
{
	for (int j = 1; j < a.size(); j ++)
	{
		int i = j -1;
		T::value_type key;
		key = a[j];
		while ( i >= 0 && a[i] > key)
		{
			a[i + 1] = a[i];
			i--;
		}
		i++;
		a[i] = key;
	}
}

//冒泡排序
template <typename T>
void SORT<T>::bubble_sort(T &a)
{
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 1; j < a.size()- i; j++)
		{
			if (a[j - 1] > a[j])
			{
				swap(a[j - 1], a[j]);
			}
		}
	}
}

//不稳定排序（在只有一组相同关键值，且选择的key为此关键值时，排序是稳定的）
//快速排序,最左元素做为key
template <typename T>
void SORT<T>::qsort(T &a, int left, int right)
{
	if (right <= left)
	{
		return ;
	}
	int pos = left - 1;
	for (int j = left; j <= right; j++)
	{
		if (a[j] <= a[left])
		{
			//指向已知的小于等于key(a[left])的最后一个位置
			pos++;
			swap(a[pos], a[j]);  
		}
	}
	swap(a[left], a[pos]);
	SORT<T>::qsort(a, left, pos - 1);
	SORT<T>::qsort(a, pos + 1, right);
}

//快速排序1,最右元素作为key
template <typename T>
void SORT<T>::qsort1(T &a, int left, int right)
{
	if (right <= left)
	{
		return ;
	}
	int pos = left - 1;
	for (int j = left; j < right; j++)
	{
		if (a[j] <= a[right])
		{
			//指向已知的小于等于key(a[right])的最后一个位置
			pos++;
			swap(a[pos], a[j]);  
		}
	}
	swap(a[right], a[++pos]);
	SORT<T>::qsort1(a, left, pos - 1);
	SORT<T>::qsort1(a, pos + 1, right);
}

//快速排序2,针对相同元素值
template <typename T>
void SORT<T>::qsort2(T &a, int left, int right)
{
	if (right <= left)
	{
		return;
	}
	int t = left - 1;
	int pos = left - 1;
	T::value_type key = a[right];
	T::value_type temp;
	for (int j = left; j <= right; j++)
	{
		if (a[j] < key)
		{
			//已知的最后一个小于等于key的位置
			t++;
			//已知的最后一个小于key的位置
			pos++;
			temp = a[pos];
			a[pos] = a[j];
			if (pos < t)
			{
				a[j] = a[t];
				a[t] = temp;
			}
			else
			{
				a[j] = temp;
			}		
		}
		else if(a[j] == key)
		{
			t++;
			swap(a[j], a[t]);
		}
	}
	//swap(a[right],a[t]);
	SORT<T>::qsort2(a, left, pos);
	SORT<T>::qsort2(a, t + 1, right);
}
//合并数据
template <typename T>
void merge_array(T &a, int first, int mid, int last)
{
	//开辟一个临时数组，用来存放数据
	T::value_type *temp = new T::value_type[last - first];
	int k = 0;
	int i = first, j = mid + 1;
	while(i <= mid && j <= last)
	{
		if (a[i] < a[j])
		{
			temp[k++] = a[i++];
		}
		else
		{
			temp[k++] = a[j++];
		}
	}
	while(i <= mid)
	{
		temp[k++] = a[i++];
	}
	while(j <= last)
	{
		temp[k++] = a[j++];
	}
	for (int count = 0; count < k; count++)
	{
		a[first++] = temp[count];
	}
	delete[] temp;
}

//归并排序
template <typename T>
void SORT<T>::merge_sort(T &a, int first, int last)
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		merge_sort(a, first, mid);
		merge_sort(a, mid + 1, last);
		merge_array(a, first, mid, last);
	}
}

//选择排序
template <typename T> 
void SORT<T>::select_sort(T &a)
{
	
	int min;
	for ( int i = 0; i < a.size(); i++)
	{
		min = i;
		for (int j = i + 1; j < a.size(); j++)
		{
			if (a[j] < a[min])
			{
				min = j;
			}
		}
		swap(a[i], a[min]);
	}

}

//希尔排序
template <typename T>
void SORT<T>::shell_sort(T &a)
{
	int length = a.size();
	for (int gap = length / 2; gap > 0; gap /= 2) //步长
	{
		for (int i = 0; i <gap; i++)//步组
		{
			//插入排序
			for (int j = i + gap; j < length; j += gap)
			{
				T::value_type key = a[j];
				int k = j - gap;
				while(k >= 0 && a[k] > key)
				{
					a[k + gap] = a[k];
					k = k -gap;
				}
				a[k + gap] = key;
				
				//简化代码（依次进行交换）
// 				for (int k = j - gap; k >= 0 && a[k] > a[k + gap]; k -= gap)
// 				{
// 					swap(a[k], a[k + gap]);
// 				}
			}
		}	
	}
}

//希尔排序1
template <typename T>
void SORT<T>::shell_sort1(T &a)
{
	int length = a.size();
	for (int gap = length / 2; gap > 0; gap /= 2)
	{
		for (int j = gap; j < length; j++)
		{
			//相互依次交换
			for (int i = j - gap; i >= 0 && a[i + gap] < a[i]; i -= gap)
			{
				swap(a[i], a[i + gap]);
			}
		}
	}
}

//计数排序(输入0-k之间的数)
template <typename T>
void SORT<T>::counting_sort(T &a, int k)
{
	T c(k + 1);
	for (int i = 0; i < k + 1; i++)
	{
		c[i] = 0;
	}
	int length = a.size();
	for (int i = 0; i < length; i++)
	{
		c[a[i]] = c[a[i]] + 1;
	}
	//c[i]conttains the number of elements less than or equal to i
	for (int i = 1; i <= k; i++)
	{
		c[i] = c[i] + c[i - 1];
	}

	T b(length);
	for (int i = length - 1; i >= 0; i--)
	{
		b[c[a[i]] - 1] = a[i];
		c[a[i]] = c[a[i]] - 1;
	}
	for (int i = 0; i < length; i++)
	{
		a[i] = b[i];
	}
}

//获得某位数num的第pos位数据
int get_num_pos(int num, int pos)
{
	int temp = 1;
	for (int i = 0; i < pos; i++)
	{
		temp = temp * 10;
	}
	return (num / temp) % 10;
}

//基数排序
template <typename T>
void SORT<T>::radix_sort(T &a)
{
	std::vector< std::vector<int> > radix_array(10);
	for (int i = 0; i < 10; i++)
	{
		//radix_array[i][0]记录这组数据的个数
		radix_array[i].push_back(0);
	}
 	int length = a.size();
	for (int pos = 0; pos < 10; pos++)
	{
		//分配
		for (int i = 0; i < length; i++)
		{
			int bit = get_num_pos(a[i], pos);
			int index = ++radix_array[bit][0];
			radix_array[bit].push_back(a[i]);
		}

		//收集
		for (int i=0, j = 0; i < 10; i++)
		{
			for (int k = 1; k <= radix_array[i][0]; k++)
			{
				//按照第pos位进行排序
				a[j++] = radix_array[i][k];
			}
			for (int m = 0; m < radix_array[i][0]; m++)
			{
				//为下一次的数据录入准备
				radix_array[i].pop_back();
			}

			//这样写则为错误（注意数据录入的顺序）
// 			for (int k = radix_array[i][0]; k >= 1; k--)
// 			{
// 				a[j++] = radix_array[i][k];
// 				radix_array[i].pop_back();
// 			}
 			radix_array[i][0] = 0;
		}		
	}


	//使用数组形式实现
// 	int *radix_array[10];    //分别为0~9的序列空间  
// 	for (int i = 0; i < 10; i++)  
// 	{  
// 		radix_array[i] = (int *)malloc(sizeof(int) * (length + 1));  
// 		radix_array[i][0] = 0;    //index为0处记录这组数据的个数  
// 	}  
// 	for (int pos = 0; pos < 10; pos++)
// 	{
// 		//分配
// 		for (int i = 0; i < length; i++)
// 		{
// 			int bit = get_num_pos(a[i], pos);
// 			int index = ++radix_array[bit][0];
// 			radix_array[bit][index] = a[i];
// 		}
// 
// 		//收集
// 		for (int i=0, j = 0; i < 10; i++)
// 		{
// 			for (int k = 1; k <= radix_array[i][0]; k++)
// 			{
// 				a[j++] = radix_array[i][k];
// 			}
// 			radix_array[i][0] = 0;
// 		}		
// 	}
}

//堆的维护
template <typename T>
void SORT<T>::minHeapify(T &a, int length, int level)
{
	int left = 2 * level + 1;
	int right = 2 * level + 2;
	int min = level;
	if (left < length && a[left] < a[min])
	{
		min = left;
	}
	if (right < length && a[right] < a[min])
	{
		min = right;
	}
	if (level != min)
	{
		swap(a[level], a[min]);
		minHeapify(a, length, min);
	}

}

//建立最小堆
template <typename T>
void SORT<T>::build_minHeap(T &a, int length)
{
	for (int i = length / 2; i >= 0; i--)
	{
		SORT<T>::minHeapify(a, length, i);
	}
}

//最小堆排序
template <typename T>
void SORT<T>::minHeap_sort(T &a)
{
	int length = a.size() - 1;
	SORT<T>::build_minHeap(a, length);
	for (int i = a.size() - 1; i >= 0; i--)
	{
		swap(a[0], a[i]);
		build_minHeap(a, i);
	}
}

#endif