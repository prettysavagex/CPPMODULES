#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	*this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	this->deque = copy.deque;
	this->vector = copy.vector;
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::merge_vec(std::vector<int> &vec, std::vector<int> &left, std::vector<int> &right)
{
	size_t i = 0, j = 0, k = 0;
	while (i < left.size() && j < right.size())
	{
		if (left[i] <= right[j])
		{
			vec[k++] = left[i++];
		}
		else
		{
			vec[k++] = right[j++];
		}
	}
	while (i < left.size())
	{
		vec[k++] = left[i++];
	}
	while (j < right.size())
	{
		vec[k++] = right[j++];
	}
}

int PmergeMe::mergeSort_vec(std::vector<int> &vector)
{
	if (vector.size() <= 1)
		return 0;

	size_t mid = vector.size() / 2;
	std::vector<int> left(vector.begin(), vector.begin() + mid);
	std::vector<int> right(vector.begin() + mid, vector.end());

	mergeSort_vec(left);
	mergeSort_vec(right);

	merge_vec(vector, left, right);

	return 0;
}

void PmergeMe::merge_deq(std::deque<int> &deq, std::deque<int> &left, std::deque<int> &right)
{
	size_t i = 0, j = 0, k = 0;
	while (i < left.size() && j < right.size())
	{
		if (left[i] <= right[j])
		{
			deq[k++] = left[i++];
		}
		else
		{
			deq[k++] = right[j++];
		}
	}
	while (i < left.size())
	{
		deq[k++] = left[i++];
	}
	while (j < right.size())
	{
		deq[k++] = right[j++];
	}
}

int PmergeMe::mergeSort_deq(std::deque<int> &deque)
{
	if (deque.size() <= 1)
		return 0;

	size_t mid = deque.size() / 2;
	std::deque<int> left(deque.begin(), deque.begin() + mid);
	std::deque<int> right(deque.begin() + mid, deque.end());

	mergeSort_deq(left);
	mergeSort_deq(right);

	merge_deq(deque, left, right);

	return 0;
}

void PmergeMe::displaySequence(const std::string &message, const std::vector<int> &sequence)
{
	std::cout << message << ": ";
	for (size_t i = 0; i < sequence.size(); ++i)
	{
		std::cout << sequence[i] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::displaySequence(const std::string &message, const std::deque<int> &sequence)
{
	std::cout << message << ": ";
	for (size_t i = 0; i < sequence.size(); ++i)
	{
		std::cout << sequence[i] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::displayTime(const std::string &container, double time)
{
	std::cout << "Time to process a range of " << vector.size() << " elements with " << container << " : " << time << " microseconds" << std::endl;
}

int PmergeMe::Pmerge(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Error: Insufficient Argument!" << std::endl;
		return -1;
	}

	if (argc == 2)
	{
		std::istringstream iss(argv[1]);
		std::string tmp;

		while(iss >> tmp)
		{
			int num = std::atoi(tmp.c_str());
			if (!num || num < 0)
			{
				std::cout << "Error: Invalid Argument!" << std::endl;
				return -1;
			}
			vector.push_back(num);
			deque.push_back(num);
		}
	}
	if (argc != 2)
	{
		for (int i = 1; i < argc; ++i)
		{
			int num = std::atoi(argv[i]);
			if (!num || num < 0)
			{
				std::cout << "Error: Invalid Argument!" << std::endl;
				return -1;
			}
			vector.push_back(num);
			deque.push_back(num);
		}
	}

	displaySequence("Before", vector);

	clock_t vec_start = clock();
	mergeSort_vec(vector);
	clock_t vec_end = clock();

	clock_t deq_start = clock();
	mergeSort_deq(deque);
	clock_t deq_end = clock();

	displaySequence("After", deque);

	double vec_time = (vec_end - vec_start) / (double)CLOCKS_PER_SEC * 1000000;
	double deq_time = (deq_end - deq_start) / (double)CLOCKS_PER_SEC * 1000000;

	displayTime("std::vector", vec_time);
	displayTime("std::deque", deq_time);

	return 0;
}

/* void PmergeMe::printDeque(std::deque<int> deque)
{
	std::deque<int>::iterator it;
	for (it = deque.begin(); it != deque.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printVector(std::vector<int> vector)
{
	std::vector<int>::iterator it;
	for (it = vector.begin(); it != vector.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
} */

/* 	std::cout << "Vector: ";
	for (size_t i = 0; i < this->vector.size(); ++i)
	{
		std::cout << this->vector[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Deque: ";
	for (size_t i = 0; i < this->deque.size(); ++i)
	{
		std::cout << this->deque[i] << " ";
	}
	std::cout << std::endl; */