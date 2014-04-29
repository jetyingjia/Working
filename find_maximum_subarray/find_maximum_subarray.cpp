#include <iostream>
#include <vector>


struct Interval
{
	int low;
	int high;
	int sum;
};

Interval find_max_crossing_subarray(std::vector<int> array, int low, int mid, int high)
{
	int left_sum = INT_MIN, right_sum = INT_MIN;
	int left_pos = 0, right_pos = 0;
	int sum_temp = 0;
	for (int i = mid; i >= low; i--)
	{
		sum_temp = sum_temp + array[i];
		if (sum_temp > left_sum)
		{
			left_sum = sum_temp;
			left_pos = i;
		}
	}

	sum_temp = 0;
	for (int i = mid + 1; i <= high; i++)
	{
		sum_temp = sum_temp + array[i];
		if (sum_temp > right_sum)
		{
			right_sum = sum_temp;
			right_pos = i;
		}
	}

	Interval crossing;
	crossing.low = left_pos;
	crossing.high = right_pos;
	crossing.sum = left_sum + right_sum;
	return crossing;
}





Interval find_maximum_subarray(std::vector<int>array, int low, int high)
{
	if (low == high)
	{
		Interval over;
		over.low = low;
		over.high = high;
		over.sum = array[low];
		return over;
	}

	int mid = (low + high) / 2;
	Interval left_array, right_array, crossing_array;
	left_array = find_maximum_subarray(array, low, mid);
	right_array = find_maximum_subarray(array, mid + 1, high);
	crossing_array = find_max_crossing_subarray(array, low, mid, high);

	if (left_array.sum > right_array.sum && left_array.sum > crossing_array.sum)
	{
		return left_array;
	}
	else if(right_array.sum > left_array.sum && right_array.sum > crossing_array.sum)
	{
		return right_array;
	}
	else 
	{
		return crossing_array;
	}
}



int main()
{
	std::vector<int> array;
	std::cout<<"Please input N and N numbers: "<<std::endl;
	int N;
	std::cin>>N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		std::cin >> temp;
		array.push_back(temp);
	}
	Interval jet;
	jet = find_maximum_subarray(array, 0, N - 1);
	std::cout<<jet.low<<"  "<<jet.high<<"  "<<jet.sum;
	system("pause");

	return 0;



}