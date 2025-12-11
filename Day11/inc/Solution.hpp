#ifndef SOLUTION_HPP
# define SOLUTION_HPP

#include "main.hpp"


typedef std::map<std::tuple<std::string, bool, bool>, int64_t> memo_data_t;

class Solution {
	private:
			std::unordered_map<std::string, std::vector<std::string>> content;
			int leadingPaths;
			int64_t numOfValidPaths;
	public:
			Solution(std::unordered_map<std::string, std::vector<std::string>> &content);
			void run();
			void runBonus();
			void showResolution(bool printSolution, bool printBonus);

			int64_t do_recursive(const std::string &node, bool isDac, bool isFft, memo_data_t &memo);
};

#endif