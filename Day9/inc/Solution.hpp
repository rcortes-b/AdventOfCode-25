#ifndef SOLUTION_HPP
# define SOLUTION_HPP

#include "main.hpp"

class Solution {

	private:
			std::vector<std::string> content;
			std::vector<std::string> map;
			std::vector<std::pair<int, int>> coords;
			unsigned long maxArea;
			unsigned long maxInsideArea;
			void fillCoords() {
				for (size_t y = 0; y < content.size(); y++) {
					int pos = content[y].find(',');
					coords.push_back({atoi(content[y].substr(0, pos).c_str()), atoi(content[y].substr(pos + 1).c_str())});
				}
			}
	public:
			Solution(std::vector<std::string> &content);
			void run();
			void runBonus();
			void showResolution();
};

#endif