#include <iostream>

using namespace std;

int* Apply_all(const int* const arr1, size_t, const int* const arr2, size_t);
void Print(int* arr, size_t size);

int main() {
	int array1[]{ 1,2,3,4,5 };
	int array2[]{ 10,20,30 };

	const size_t array1_size{ 5 };
	const size_t array2_size{ 3 };

	int* results = Apply_all(array1, array1_size, array2, array2_size);
	constexpr size_t finalSize{ array1_size * array2_size };

	Print(results, finalSize);

	return 0;
}

int* Apply_all(const int* const arr1, size_t size1, const int* const arr2, size_t size2) {
	int* applied{};
	applied = new int[size1 * size2];

	int position{ 0 };

	for (size_t i{ 0 }; i < size2; i++) {

		for (size_t j{ 0 }; j < size1; j++) {
			applied[position] = arr1[j] * arr2[i];
			position++;
		}
	}

	return applied;
}

void Print(int* arr, size_t size) {
	for (int i{ 0 }; i < size; ++i) {
		cout << arr[i] << endl;
	}
}