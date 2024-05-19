#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <sstream>
#include <ctime>
//#include <iterator>

class PmergeMe
{
	private:
		std::vector<int> vector;
		std::deque<int> deque;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &copy);
		~PmergeMe();

		int Pmerge(int argc, char **argv);
		int mergeSort_vec(std::vector<int> &vector);
		int mergeSort_deq(std::deque<int> &deque);
		void merge_vec(std::vector<int> &vec, std::vector<int> &left, std::vector<int> &right);
		void merge_deq(std::deque<int> &deq, std::deque<int> &left, std::deque<int> &right);

		void displaySequence(const std::string &message, const std::vector<int> &sequence);
		void displaySequence(const std::string &message, const std::deque<int> &sequence);
		void displayTime(const std::string &container, double time);
		// void printDeque(std::deque<int> deque);
		// void printVector(std::vector<int> vector);
};

#endif