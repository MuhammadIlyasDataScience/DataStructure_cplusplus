#include <iostream>
#include <fstream>
#include <ctime>
#include<cstdlib>
#include <chrono>
                                  // Selection Sort Algorithm for Ascending Order (n-1 Swap)
                                  // ____________________________________________

void AsSelectionSort(int arr[], int size) {
	int outItera = size - 1;

	for (int i = 0; i < outItera; i++) {
		int index = i, temp;

		for (int j = i + 1; j < size; j++) {

			if (arr[i] > arr[j]) {
				index = j;
			}

		}

		if (index > i) {
			temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;

		}

	}

}


// Wrong Selection Sort in Ascending Order (n^2 Swap)
	  // ________________________________________


void wrogAsSelectionSort(int arr[], int size) {
	int iter = size - 1;

	for (int i = 0; i < iter; i++) {

		for (int j = i + 1; j < iter; j++) {

			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;

			}

		}

	}

}

// Ascending Order Bubble Sort
// ___________________________

void AsBubbleSort(int arr[], int size) {
	int iter = size - 1;

	for (int i = 0; i < iter; i++) {
		int k = 0;

		for (int j = 0; j < iter - i; j++) {
			k = j + 1;

			if (arr[j] > arr[k]) {
				int temp = arr[j];
				arr[j] = arr[k];
				arr[k] = temp;
			}

		}

	}

}

// Ascending Order Insertion Sort

void insertion_sort(int arr[], int size) {
	for (int j = 1; j < size; j++) {
		int curr = arr[j];
		int i = j - 1;

		while (i >= 0 && curr < arr[i]) {
			arr[i + 1] = arr[i];
			i--;
		}

		arr[i + 1] = curr;  
	}
}



//****************************************************************************
//                            Additional Works
//*****************************************************************************
                                  // Selection Sort Algorithm for Ascending Order (Second Method / Alternate Implementation) (n-1 Swap)
                                  // ____________________________________________

void Method2AsSelectionSort(int arr[], int size) {
	int outItera = size-1;

	for (int i =outItera; i > 0; i--) {
		int index = i, temp;

		for (int j = i -1; j >= 0; j--) {

			if (arr[i] < arr[j]) {
				index = j;

			}

		}

		if (index < i) {
			temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;

		}

	}

}

                               

                                          // Selection Sort in Descending Order (n-1 Swap)
                                          // _________________________________

void DcSelectionSort(int arr[], int size) {
	int iter = size - 1;

	for (int i = 0; i < iter; i++) {
		int index = i, temp;

		for (int j = i + 1; j < size; j++) {

			if (arr[i] < arr[j]) {
				index = j;
			}
		}

		if (index > i) {
			temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;
		}

	}

}


                                      // Selection Sort Algorithm for Descending Order (Second Method / Alternate Implementation) (n-1 Swap)
                                      // ____________________________________________

void Method2DcSelectionSort(int arr[], int size) {
	int outItera = size - 1;

	for (int i = outItera; i > 0; i--) {
		int index = i, temp;

		for (int j = i - 1; j >= 0; j--) {

			if (arr[i] > arr[j]) {
				index = j;

			}

		}

		if (index < i) {
			temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;

		}

	}

}

      

                                                       // Wrong Selection Sort in Descending Order (n^2 swap)
                                                       // ________________________________________


void wrogDcSelectionSort(int arr[], int size) {
	int iter = size - 1;

	for (int i = 0; i < iter; i++) {

		for (int j = i + 1; j < iter; j++) {

			if (arr[i] < arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;

			}

		}

	}

}



// Dscending Order Bubble Sort
// ___________________________

void DcBubbleSort(int arr[], int size) {
	int iter = size - 1;

	for (int i = 0; i < iter; i++) {
		int k = 0;

		for (int j = 0; j < iter - i; j++) {
			k = j + 1;

			if (arr[j] < arr[k]) {
				int temp = arr[j];
				arr[j] = arr[k];
				arr[k] = temp;
			}

		}

	}

}

// *********************************************************************************************************
//                                            End of Additional Work
//**********************************************************************************************************

// Display Function
// ________________

void display(int arr[], int size) {

	for (int i = 0; i < size; i++)
		std::cout << arr[i] <<"     ";
}



int main() {

	const int size = 400;
	int ar1[size];
	int asAr[size];
	int DesAr[size];
	std::ofstream outfile;
	outfile.open("TimeComplexity.csv");
	std::chrono::duration<long> tim[12];

	for (int i = 0; i < 12; i++) {
		tim[i] = std::chrono::duration<long>(0);
	}
	if (!outfile.is_open()) {
		std::cout << "The File could not be opened!";
		return 0;
	}

	for (int j = 0; j < 10; j++) {

		srand(time(0));
		for (int i = 0; i < size; i++) {
			ar1[i] = rand();
			asAr[i] = ar1[0] + i * 5;
			DesAr[i] = ar1[size - 1] - i * 3;
		}

		auto before = std::chrono::high_resolution_clock::now();
		AsSelectionSort(ar1, size);
		auto end = std::chrono::high_resolution_clock::now();
		tim[0] += std::chrono::duration<long>(std::chrono::duration_cast<std::chrono::nanoseconds>(end - before).count());

		before = std::chrono::high_resolution_clock::now();
		wrogAsSelectionSort(ar1, size);
		end = std::chrono::high_resolution_clock::now();
		tim[1] += std::chrono::duration<long>(std::chrono::duration_cast<std::chrono::nanoseconds>(end - before).count());

		before = std::chrono::high_resolution_clock::now();
		AsBubbleSort(ar1, size);
		end = std::chrono::high_resolution_clock::now();
		tim[2] += std::chrono::duration<long>(std::chrono::duration_cast<std::chrono::nanoseconds>(end - before).count());

		before = std::chrono::high_resolution_clock::now();
		insertion_sort(ar1, size);
		end = std::chrono::high_resolution_clock::now();
		tim[3] += std::chrono::duration<long>(std::chrono::duration_cast<std::chrono::nanoseconds>(end - before).count());

		before = std::chrono::high_resolution_clock::now();
		AsSelectionSort(asAr, size);
		end = std::chrono::high_resolution_clock::now();
		tim[4] += std::chrono::duration<long>(std::chrono::duration_cast<std::chrono::nanoseconds>(end - before).count());

		before = std::chrono::high_resolution_clock::now();
		wrogAsSelectionSort(asAr, size);
		end = std::chrono::high_resolution_clock::now();
		tim[5] += std::chrono::duration<long>(std::chrono::duration_cast<std::chrono::nanoseconds>(end - before).count());

		before = std::chrono::high_resolution_clock::now();
		AsBubbleSort(asAr, size);
		end = std::chrono::high_resolution_clock::now();
		tim[6] += std::chrono::duration<long>(std::chrono::duration_cast<std::chrono::nanoseconds>(end - before).count());

		before = std::chrono::high_resolution_clock::now();
		insertion_sort(asAr, size);
		end = std::chrono::high_resolution_clock::now();
		tim[7] += std::chrono::duration<long>(std::chrono::duration_cast<std::chrono::nanoseconds>(end - before).count());

		before = std::chrono::high_resolution_clock::now();
		AsSelectionSort(DesAr, size);
		end = std::chrono::high_resolution_clock::now();
		tim[8] += std::chrono::duration<long>(std::chrono::duration_cast<std::chrono::nanoseconds>(end - before).count());

		before = std::chrono::high_resolution_clock::now();
		wrogAsSelectionSort(DesAr, size);
		end = std::chrono::high_resolution_clock::now();
		tim[9] += std::chrono::duration<long>(std::chrono::duration_cast<std::chrono::nanoseconds>(end - before).count());

		before = std::chrono::high_resolution_clock::now();
		AsBubbleSort(DesAr, size);
		end = std::chrono::high_resolution_clock::now();
		tim[10] += std::chrono::duration<long>(std::chrono::duration_cast<std::chrono::nanoseconds>(end - before).count());

		before = std::chrono::high_resolution_clock::now();
		insertion_sort(DesAr, size);
		end = std::chrono::high_resolution_clock::now();
		tim[11] += std::chrono::duration<long>(std::chrono::duration_cast<std::chrono::nanoseconds>(end - before).count());
	}

	for (int i = 0; i < 12; i++) {
		tim[i] /= 10;
	}

	outfile << "Alogithm,Array Size,Array Type, Average Time\n";
	outfile << "Right Selection Sort," << size << ",Random Array," << tim[0].count() << "\n";
	outfile << "Wrong Selection Sort," << size << ",Random Array," << tim[1].count() << "\n";
	outfile << "Bubble Sort," << size << ",Random Array," << tim[2].count() << "\n";
	outfile << "Insertion Sort," << size << ",Random Array," << tim[3].count() << "\n";

	outfile << "Right Selection Sort," << size << ",Ascending Array," << tim[4].count() << "\n";
	outfile << "Wrong Selection Sort," << size << ",Ascending Array," << tim[5].count() << "\n";
	outfile << "Bubble Sort," << size << ",Ascending Array," << tim[6].count() << "\n";
	outfile << "Insertion Sort," << size << ",Ascending Array," << tim[7].count() << "\n";

	outfile << "Right Selection Sort," << size << ",Descending Array," << tim[8].count() << "\n";
	outfile << "Wrong Selection Sort," << size << ",Descending Array," << tim[9].count() << "\n";
	outfile << "Bubble Sort," << size << ",Descending Array," << tim[10].count() << "\n";
	outfile << "Insertion Sort," << size << ",Descending Array," << tim[11].count() << "\n";
	outfile.close();
}








