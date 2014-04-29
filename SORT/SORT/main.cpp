#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include "SORT.h"


int main()
{
	
	//***************************************//
	//					int������			//
	//***************************************//
	SORT< std::vector<int> > iSort;
	int N;
	std::cout << "please input N numbers: ";
	std::cin >> N;
	std::vector<int> iarray;
	iSort.initial_sort(iarray, N);
	//iSort.show_value(iarray);

	//��������
// 	std::vector<int> ia(iarray.begin(), iarray.end());
// 	iSort.insert_sort(iarray);
// 	iSort.show_value(iarray);

	//ð������
// 	std::vector<int> ba(iarray.begin(), iarray.end());
// 	iSort.bubble_sort(ba);
// 	iSort.show_value(ba);

	//��������
// 	std::vector<int> qa(iarray.begin(), iarray.end());
// 	iSort.qsort2(qa, 0, qa.size() - 1);
// 	iSort.show_value(qa);

	//��������
// 	int k;
// 	std::cout<<"please input the maximun value k:";
// 	std::cin >> k;
// 	std::vector<int> qa(iarray.begin(), iarray.end());
// 	iSort.counting_sort(qa, k);
// 	iSort.show_value(qa);
	std::vector<int> qa(iarray.begin(), iarray.end());
	iSort.radix_sort(qa);
	iSort.show_value(qa);
	//�鲢����
// 	std::vector<int> ma(iarray.begin(), iarray.end());
// 	iSort.merge_sort(ma, 0, ma.size() - 1);
// 	iSort.show_value(ma);

	//ѡ������
// 	std::vector<int> sa(iarray.begin(), iarray.end());
// 	iSort.select_sort(sa);
// 	iSort.show_value(sa);

	//��С������
// 	std::vector<int> heapa(iarray.begin(), iarray.end());
// 	iSort.minHeap_sort(heapa);
// 	iSort.show_value(heapa);

	//ϣ������
// 	std::vector<int> shella(iarray.begin(), iarray.end());
// 	iSort.shell_sort(shella);
// 	iSort.show_value(shella);





// 	//***************************************//
// 	//					string������		//
// 	//***************************************//
// 	SORT< std::vector<std::string> > sSort;
// 	int N;
// 	std::cout << "please input N strings: ";
// 	std::cin >> N;
// 	std::vector<std::string> sarray;
// 	sSort.initial_sort(sarray, N);
// 	sSort.show_value(sarray);

	//��������
	// 	std::vector<int> ia(iarray.begin(), iarray.end());
	// 	iSort.insert_sort(iarray);
	// 	iSort.show_value(iarray);

	//ð������
	// 	std::vector<int> ba(iarray.begin(), iarray.end());
	// 	iSort.bubble_sort(ba);
	// 	iSort.show_value(ba);

	//��������
	// 	std::vector<int> qa(iarray.begin(), iarray.end());
	// 	iSort.qsort(qa, 0, qa.size() - 1);
	// 	iSort.show_value(qa);

	//�鲢����
	// 	std::vector<int> ma(iarray.begin(), iarray.end());
	// 	iSort.merge_sort(ma, 0, ma.size() - 1);
	// 	iSort.show_value(ma);

	//ѡ������
	// 	std::vector<int> sa(iarray.begin(), iarray.end());
	// 	iSort.select_sort(sa);
	// 	iSort.show_value(sa);

	//��С������
	// 	std::vector<int> heapa(iarray.begin(), iarray.end());
	// 	iSort.minHeap_sort(heapa);
	// 	iSort.show_value(heapa);

	//ϣ������
// 	std::vector<std::string> shella(sarray.begin(), sarray.end());
// 	sSort.shell_sort(shella);
// 	sSort.show_value(shella);

	system("pause");




	//return 0;

}