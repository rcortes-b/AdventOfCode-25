#ifndef SOLUTION_HPP
# define SOLUTION_HPP

#include "main.hpp"

class Solution {
	private:
			std::vector<std::string> content;
			int **coords;
			int totalPairsToConnect;
			unsigned long largestCircuits;
			unsigned long lastConnection;
			std::chrono::_V2::system_clock::time_point firstLevelEndTime;

	public:
			Solution(std::vector<std::string> &content, int totalPairsToConnect);
			~Solution() {
				for (size_t y = 0; y < content.size(); y++)
					delete[] coords[y];
				delete[] coords;
			}
			
			void run();
			void showResolution();

			void parseCoords();
			unsigned long getEuclideanDistance(int idx_curr, int idx_coord);
			int indexOfCircuit(std::map<int, std::vector<int>> &circuits, int value);
			void calculateLargestCircuits(std::map<int, std::vector<int>> &circuits);

			void setFirstLevelEndTime() {
				firstLevelEndTime = std::chrono::high_resolution_clock::now();
			}

			std::chrono::_V2::system_clock::time_point getFirstLevelEndTime() {
				return firstLevelEndTime;
			}
};

#endif