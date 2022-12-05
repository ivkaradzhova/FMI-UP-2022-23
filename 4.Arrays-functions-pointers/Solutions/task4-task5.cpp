#include <iostream>
#include <cassert>

void swap(int& first_number, int& second_number) {
	int temp = first_number;
	first_number = second_number;
	second_number = temp;
}

void special_bubble_sort_task4(int arr[], const int size) {
	assert(size >= 0);

	for (int i = size - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < 0 && arr[j + 1] > 0) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void special_bubble_sort_task5(int arr[], const int size) {
	assert(size >= 0);

	for (int i = size - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] % 2 != 0 && arr[j + 1] % 2 == 0) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

int main() {
	const int SIZE = 1024;
	int n;
	std::cin >> n;
	assert(n > 0 && n <= SIZE);
	int arr[SIZE];

	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}

	//special_bubble_sort_task4(arr, n);
	special_bubble_sort_task5(arr, n);

	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}

	return 0;
}
