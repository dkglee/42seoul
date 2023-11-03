#include "PmergeMe.hpp"

int main(int argc, char* argv[])
{
	std::vector<int> varr;
	for (int i = 0; i < argc - 1; i++)
		varr.push_back(atoi(argv[i + 1]));
	for (auto it : varr)
		std::cout << it << ' ';
	std::cout << std::endl;
	mergeInsertion(varr, 0, varr.size() - 1, 5);
	for (auto it : varr)
		std::cout << it << ' ';
	std::cout << std::endl;
	return 0;아나
	님
	열공
	노미네이트
	탈락입니다
	ㅋ
	
}
