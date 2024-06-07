#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <utility>
#include <cmath>
#include <exception>

class PmergeMe {
public:
	static void MergeInsertSortVector(std::vector<int>& container);
	static void MergeInsertSortList(std::list<int>& container);
private:
	PmergeMe();
	PmergeMe(const PmergeMe&);
	PmergeMe& operator=(const PmergeMe&);
	~PmergeMe();
	static void MergeInsertVector(std::vector<std::pair<int, int> >& container, std::vector<std::pair<int, int> >& left, std::vector<std::pair<int, int> >& right);
	static void MergeInsertList(std::list<std::pair<int, int> >& container, std::list<std::pair<int, int> >& left, std::list<std::pair<int, int> >& right);
	static void MergeSortVector(std::vector<std::pair<int, int> >& container);
	static void MergeSortList(std::list<std::pair<int, int> >& container);
	static std::vector<int> GenerateJacobsthalSequenceVector(size_t size);
	static std::list<int> GenerateJacobsthalSequenceList(size_t size);
	static void InsertUsingBinarySearchVector(std::vector<int>& container, std::vector<int>::iterator end, int value);
	static void InsertUsingBinarySearchList(std::list<int>& container, std::list<int>::iterator end, int value);
};

// 포드 존슨 알고리즘
// 쌍으로 묶음
// 쌍이 하나의 원소임
// 쌍을 기준으로 분할함
// 더이상 쌍을 나눌 수 없을 때, 각 쌍을 큰 순서대로 정렬함. 예) {1, 5} -> {5, 1};
// 첫 번째 인덱스를 기준으로 정렬함. 예) {5, 1}, {3, 2} -> {3, 2}, {5, 1};
// 각 쌍의 큰 것들로 main chain을 만듬 (이미 정렬되어 있는 상태) : main chain = {3, 5};
// 작은 것(홀수 였을 때의 남은 것 포함)들로 pending chain을 만듬 : pending chain = {2, 1};
// pending chain에서 jacobsthal sequence를 만들 뒤 해당 sequence 순서대로 pending chain에서 하나씩 빼서 main chain에 삽입함.
// 이때, 삽입할 때, binary search를 이용해서 삽입함.
