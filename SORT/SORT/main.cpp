#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include "SORT.h"


int main()
{
	
	//***************************************//
	//					int–Õ≈≈–Ú			//
	//***************************************//
	SORT< std::vector<int> > iSort;
	int N;
	std::cout << "please input N numbers: ";
	std::cin >> N;
	std::vector<int> iarray;
	iSort.initial_sort(iarray, N);
	//iSort.show_value(iarray);

	//≤Â»Î≈≈–Ú
// 	std::vector<int> ia(iarray.begin(), iarray.end());
// 	iSort.insert_sort(iarray);
// 	iSort.show_value(iarray);

	//√∞≈›≈≈–Ú
// 	std::vector<int> ba(iarray.begin(), iarray.end());
// 	iSort.bubble_sort(ba);
// 	iSort.show_value(ba);

	//øÏÀŸ≈≈–Ú
// 	std::vector<int> qa(iarray.begin(), iarray.end());
// 	iSort.qsort2(qa, 0, qa.size() - 1);
// 	iSort.show_value(qa);

	//º∆ ˝≈≈–Ú
// 	int k;
// 	std::cout<<"please input the maximun value k:";
// 	std::cin >> k;
// 	std::vector<int> qa(iarray.begin(), iarray.end());
// 	iSort.counting_sort(qa, k);
// 	iSort.show_value(qa);
	std::vector<int> qa(iarray.begin(), iarray.end());
	iSort.radix_sort(qa);
	iSort.show_value(qa);
	//πÈ≤¢≈≈–Ú
// 	std::vector<int> ma(iarray.begin(), iarray.end());
// 	iSort.merge_sort(ma, 0, ma.size() - 1);
// 	iSort.show_value(ma);

	//—°‘Ò≈≈–Ú
// 	std::vector<int> sa(iarray.begin(), iarray.end());
// 	iSort.select_sort(sa);
// 	iSort.show_value(sa);

	//◊Ó–°∂—≈≈–Ú
// 	std::vector<int> heapa(iarray.begin(), iarray.end());
// 	iSort.minHeap_sort(heapa);
// 	iSort.show_value(heapa);

	//œ£∂˚≈≈–Ú
// 	std::vector<int> shella(iarray.begin(), iarray.end());
// 	iSort.shell_sort(shella);
// 	iSort.show_value(shella);





// 	//***************************************//
// 	//					string–Õ≈≈–Ú		//
// 	//***************************************//
// 	SORT< std::vector<std::string> > sSort;
// 	int N;
// 	std::cout << "please input N strings: ";
// 	std::cin >> N;
// 	std::vector<std::string> sarray;
// 	sSort.initial_sort(sarray, N);
// 	sSort.show_value(sarray);

	//≤Â»Î≈≈–Ú
	// 	std::vector<int> ia(iarray.begin(), iarray.end());
	// 	iSort.insert_sort(iarray);
	// 	iSort.show_value(iarray);

	//√∞≈›≈≈–Ú
	// 	std::vector<int> ba(iarray.begin(), iarray.end());
	// 	iSort.bubble_sort(ba);
	// 	iSort.show_value(ba);

	//øÏÀŸ≈≈–Ú
	// 	std::vector<int> qa(iarray.begin(), iarray.end());
	// 	iSort.qsort(qa, 0, qa.size() - 1);
	// 	iSort.show_value(qa);

	//πÈ≤¢≈≈–Ú
	// 	std::vector<int> ma(iarray.begin(), iarray.end());
	// 	iSort.merge_sort(ma, 0, ma.size() - 1);
	// 	iSort.show_value(ma);

	//—°‘Ò≈≈–Ú
	// 	std::vector<int> sa(iarray.begin(), iarray.end());
	// 	iSort.select_sort(sa);
	// 	iSort.show_value(sa);

	//◊Ó–°∂—≈≈–Ú
	// 	std::vector<int> heapa(iarray.begin(), iarray.end());
	// 	iSort.minHeap_sort(heapa);
	// 	iSort.show_value(heapa);

	//œ£∂˚≈≈–Ú
// 	std::vector<std::string> shella(sarray.begin(), sarray.end());
// 	sSort.shell_sort(shella);
// 	sSort.show_value(shella);

	system("pause");




	//return 0;

}