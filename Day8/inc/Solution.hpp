#ifndef SOLUTION_HPP
# define SOLUTION_HPP

#include "main.hpp"

class Solution {
	private:
			std::vector<std::string> content;
			int **coords;

	public:
			Solution(std::vector<std::string> &content);
			void run();
			void runBonus();
			void showResolution();

			unsigned long getEuclideanDistance(int idx_curr, int idx_coord);
			void parseCoords();
			bool checkIfIsRepeated(std::multimap<int, std::multimap<int, int>> &map, int key, int y, int x);
};

#endif