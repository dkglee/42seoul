#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <cstring>

template <typename Container>
void Insertion(Container& arr, int low, int high) {
	for (int i = low + 1; i <= high; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= low && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

template <typename Container>
void merge(Container& arr, int low, int high) {
	int mid = (low + high) / 2;
	int n1 = mid - low + 1;
	int n2 = high - mid;
	Container leftArr(n1);
	Container rightArr(n2);
	for (int i = 0; i < n1; i++)
		leftArr[i] = arr[low + i];
	for (int i = 0; i < n2; i++)
		rightArr[i] = arr[mid + 1 + i];
	int i = 0;
	int j = 0;
	int k = low;
	while (i < n1 && j < n2) {
		if (leftArr[i] <= rightArr[j])
			arr[k++] = leftArr[i++];
		else
			arr[k++] = rightArr[j++];
	}
	while (i < n1)
		arr[k++] = leftArr[i++];
	while (j < n2)
		arr[k++] = rightArr[j++];
}

template <typename Container>
void mergeInsertion(Container& arr, int low, int high, int depth) {
	if (high - low < depth)
		Insertion(arr, low, high);
	else {
		int mid = (low + high) / 2;
		mergeInsertion(arr, low, mid, depth);
		mergeInsertion(arr, mid + 1, high, depth);
		merge(arr, low, high);
	}
}

#endif
