#ifndef SOLUTION_HPP
# define SOLUTION_HPP

#include "main.hpp"

class Solution {
	private:
		int width;
		int height;
		int rollsAccessed;
		int rollsRemoved;
		std::vector<std::string> content;

		bool isValidX(int x) {
			if (x == -1 || x == width)
				return false;
			return true;
		}

		bool isValidY(int y) {
			if (y == -1 || y == height)
				return false;
			return true;
		}

		bool checkAdjacent(int x, int y)
		{
			if (!this->isValidX(x) || !this->isValidY(y))
				return false;
			return (content[y][x] == '@');
		}

	public:
			Solution();
			Solution(std::vector<std::string> &content);
			void run();
			void runBonus();
			void showResolution();
};

#endif