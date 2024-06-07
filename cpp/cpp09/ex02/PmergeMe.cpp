#include "PmergeMe.hpp"

void PmergeMe::MergeInsertVector(std::vector<std::pair<int, int> >& container, std::vector<std::pair<int, int> >& left, std::vector<std::pair<int, int> >& right) {
	container.clear();
	size_t left_index = 0;
	size_t right_index = 0;
	while (left_index < left.size() && right_index < right.size()) {
		if (left[left_index] < right[right_index]) {
			container.push_back(left[left_index]);
			left_index++;
		} else {
			container.push_back(right[right_index]);
			right_index++;
		}
	}
	while (left_index < left.size()) {
		container.push_back(left[left_index]);
		left_index++;
	}
	while (right_index < right.size()) {
		container.push_back(right[right_index]);
		right_index++;
	}
}

void PmergeMe::MergeSortVector(std::vector<std::pair<int, int> >& container) {
	if (container.size() <= 1) {
		if (container[0].first < container[0].second)
			std::swap(container[0].first, container[0].second);
		return;
	}
	std::vector<std::pair<int, int> > left(container.begin(), container.begin() + container.size() / 2);
	std::vector<std::pair<int, int> > right(container.begin() + container.size() / 2, container.end());
	MergeSortVector(left);
	MergeSortVector(right);
	MergeInsertVector(container, left, right);
}

std::vector<int> PmergeMe::GenerateJacobsthalSequenceVector(size_t size) {
	std::vector<int> return_vector(size);
	std::vector<int> jacobsthal_sequence;
	jacobsthal_sequence.push_back(0);
	jacobsthal_sequence.push_back(1);
	return_vector[0] = 0;
	
	size_t last_jacobsthal = 1;
	size_t ret_index = 1;
	size_t jac_index = 2;
	size_t temp = 0;

	while (ret_index < size) {
		jacobsthal_sequence.push_back(jacobsthal_sequence[jac_index - 1] + 2 * jacobsthal_sequence[jac_index - 2]);
		temp = jacobsthal_sequence[jac_index];
		while (temp > last_jacobsthal) {
			if (ret_index >= size) {
				break;
			}
			if (temp > size) {
				temp--;
				continue;
			}
			return_vector[ret_index++] = (temp - 1);
			temp--;
		}
		last_jacobsthal = jacobsthal_sequence[jac_index];
		jac_index++;
	}
	return return_vector;
}

void PmergeMe::InsertUsingBinarySearchVector(std::vector<int>& container, std::vector<int>::iterator end, int value) {
	size_t left = 0;
	size_t right = end - container.begin();
	while (left < right) {
		size_t mid = (left + right) / 2;
		if (container[mid] < value) {
			left = mid + 1;
		} else {
			right = mid;
		}
	}
	container.insert(container.begin() + left, value);
}

void PmergeMe::MergeInsertSortVector(std::vector<int>& container) {
	if (container.size() <= 1) {
		return;
	}
	
	std::vector<std::pair<int, int> > pairs;
	std::vector<int> main_chain;
	std::vector<int> pending_chain;

	for (size_t i = 0; i + 1 < container.size(); i += 2) {
		if (container[i] < 0 || container[i + 1] < 0) {
			throw std::invalid_argument("Error");
		}
		pairs.push_back(std::make_pair(container[i], container[i + 1]));
	}
	MergeSortVector(pairs);

	std::vector<std::pair<int, int> >::iterator it = pairs.begin();
	for (; it != pairs.end(); it++) {
		main_chain.push_back(it->first);
	}

	it = pairs.begin();
	for (; it != pairs.end(); it++) {
		pending_chain.push_back(it->second);
	}
	if (container.size() % 2 == 1) {
		pending_chain.push_back(container[container.size() - 1]);
	}


	std::vector<int> jacobsthal_sequence = GenerateJacobsthalSequenceVector(pending_chain.size());
	std::vector<int>::iterator jacobsthal_it = jacobsthal_sequence.begin();
	std::vector<int>::iterator search_range;
	for (; jacobsthal_it != jacobsthal_sequence.end(); jacobsthal_it++) {
		if (*jacobsthal_it == static_cast<int>(pending_chain.size() - 1)) {
			search_range = main_chain.end();
		} 
		else {
			search_range = std::find(main_chain.begin(), main_chain.end(), pairs[*jacobsthal_it].first);
		}
		InsertUsingBinarySearchVector(main_chain, search_range, pending_chain[*jacobsthal_it]);
	}
	std::copy(main_chain.begin(), main_chain.end(), container.begin());
}


void PmergeMe::MergeInsertList(std::list<std::pair<int, int> >& container, std::list<std::pair<int, int> >& left, std::list<std::pair<int, int> >& right) {
	container.clear();
    std::list<std::pair<int, int> >::iterator left_it = left.begin();
    std::list<std::pair<int, int> >::iterator right_it = right.begin();

    while (left_it != left.end() && right_it != right.end()) {
        if (*left_it < *right_it) {
            container.push_back(*left_it);
            ++left_it;
        } else {
            container.push_back(*right_it);
            ++right_it;
        }
    }

    while (left_it != left.end()) {
        container.push_back(*left_it);
        ++left_it;
    }

    while (right_it != right.end()) {
        container.push_back(*right_it);
        ++right_it;
    }
}

void PmergeMe::MergeSortList(std::list<std::pair<int, int> >& container) {
	if (container.size() <= 1) {
		if (container.front().first < container.front().second)
			std::swap(container.front().first, container.front().second);
		return;
	}
	std::list<std::pair<int, int> >::iterator middle = container.begin();
    std::advance(middle, container.size() / 2);
	std::list<std::pair<int, int> > left(container.begin(), middle);
	std::list<std::pair<int, int> > right(middle, container.end());
	MergeSortList(left);
	MergeSortList(right);
	MergeInsertList(container, left, right);
}

std::list<int> PmergeMe::GenerateJacobsthalSequenceList(size_t size) {
	std::list<int> return_list(size);
	std::list<int> jacobsthal_sequence;
	jacobsthal_sequence.push_back(0);
	jacobsthal_sequence.push_back(1);

	std::list<int>::iterator ret_it = return_list.begin();
	*ret_it = 0;
	
	size_t last_jacobsthal = 1;
	size_t ret_index = 1;
	size_t jac_index = 2;
	size_t temp = 0;

	while (ret_index < size) {
		// jacobsthal_sequence.push_back(jacobsthal_sequence[jac_index - 1] + 2 * jacobsthal_sequence[jac_index - 2]);
		std::list<int>::iterator jacobsthal_it1 = jacobsthal_sequence.begin();
        std::advance(jacobsthal_it1, jac_index - 1);

        std::list<int>::iterator jacobsthal_it2 = jacobsthal_sequence.begin();
        std::advance(jacobsthal_it2, jac_index - 2);

		int new_jacobsthal = *jacobsthal_it1 + 2 * (*jacobsthal_it2);
        jacobsthal_sequence.push_back(new_jacobsthal);
		temp = new_jacobsthal;
		while (temp > last_jacobsthal) {
			if (ret_index >= size) {
				break;
			}
			if (temp > size) {
				temp--;
				continue;
			}
			ret_it = return_list.begin();
			std::advance(ret_it, ret_index);
            *ret_it = (temp - 1);
			ret_index++;
			temp--;
		}
		last_jacobsthal = new_jacobsthal;
		jac_index++;
	}
	return return_list;
}

void PmergeMe::InsertUsingBinarySearchList(std::list<int>& container, std::list<int>::iterator end, int value) {
	std::list<int>::iterator left = container.begin();
    std::list<int>::iterator right = end;
    while (left != right) {
        std::list<int>::iterator mid = left;
        std::advance(mid, std::distance(left, right) / 2);
        if (*mid < value) {
			++mid;
            left = mid;
        } else {
            right = mid;
        }
    }
    container.insert(left, value);
}

void PmergeMe::MergeInsertSortList(std::list<int>& container) {
	if (container.size() <= 1) {
		return;
	}
	
	std::list<std::pair<int, int> > pairs;
	std::list<int> main_chain;
	std::list<int> pending_chain;

	
    std::list<int>::iterator it = container.begin();
    while (it != container.end()) {
        std::list<int>::iterator next_it = it;
		++next_it;
		if (*it < 0 || *next_it < 0) {
			throw std::invalid_argument("Error");
		}
        if (next_it != container.end()) {
            pairs.push_back(std::make_pair(*it, *next_it));
            it = ++next_it;
        } else {
			++it;
		}
    }
	MergeSortList(pairs);

	std::list<std::pair<int, int> >::iterator pair_it;
    for (pair_it = pairs.begin(); pair_it != pairs.end(); ++pair_it) {
        main_chain.push_back(pair_it->first);
        pending_chain.push_back(pair_it->second);
    }

	if (container.size() % 2 == 1) {
		pending_chain.push_back(container.back());
	}


	std::list<int> jacobsthal_sequence = GenerateJacobsthalSequenceList(pending_chain.size());

	std::list<int>::iterator jacobsthal_it = jacobsthal_sequence.begin();
	std::list<int>::iterator search_range;
	for (; jacobsthal_it != jacobsthal_sequence.end(); jacobsthal_it++) {
		if (*jacobsthal_it == static_cast<int>(pending_chain.size() - 1)) {
			search_range = main_chain.end();
		} 
		else {
			std::list<std::pair<int, int> >::iterator pair_it = pairs.begin();
            std::advance(pair_it, *jacobsthal_it);
			search_range = std::find(main_chain.begin(), main_chain.end(), pair_it->first);
		}
		std::list<int>::iterator pending_it = pending_chain.begin();
        std::advance(pending_it, *jacobsthal_it);
		InsertUsingBinarySearchList(main_chain, search_range, *pending_it);
	}

	std::copy(main_chain.begin(), main_chain.end(), container.begin());
}
