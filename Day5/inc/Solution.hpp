#ifndef SOLUTION_HPP
# define SOLUTION_HPP

#include "main.hpp"

class Solution {
	private:
			std::vector<unsigned long> freshIds;
			std::vector<unsigned long> availableIds;
			int totalAvailableIds;
			unsigned long totalAvailableIdsBonus;

	public:
			Solution(std::vector<unsigned long> &freshIds, std::vector<unsigned long> &availableIds);
			void run();
			void runBonus();
			void showResolution();
};

#endif