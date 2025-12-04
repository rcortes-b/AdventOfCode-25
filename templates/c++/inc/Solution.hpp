#ifndef SOLUTION_HPP
# define SOLUTION_HPP

#include "main.hpp"

class Solution {
	private:
			std::vector<std::string> content;
	public:
			Solution(std::vector<std::string> &content);
			void run();
			void runBonus();
			void showResolution();
};

#endif