#ifndef SOLUTION_HPP
# define SOLUTION_HPP

#include "main.hpp"

class Solution {
	private:
			std::vector<std::string> content;
			int splitTimes;
			unsigned long timelines;
			unsigned long** timelinesMemo;
	public:
			Solution(std::vector<std::string> &content);
			~Solution() {
				for (size_t y = 0; y < content.size(); y++)
					delete[] timelinesMemo[y];
				delete[] timelinesMemo;
			}
			void run();
			void runBonus();
			void showResolution();

			void move_bean(int y, int x);
};

#endif