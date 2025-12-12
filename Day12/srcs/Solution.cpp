#include "../inc/Solution.hpp"
#include "../inc/main.hpp"

Solution::Solution(std::vector<std::string> &content)
{
	this->totalRegionsFit = 0;
	this->parseContent(content);
}

void Solution::run()
{
	for (auto &region : regions) {
		auto &matrix = region.first;
		int64_t bigArea = matrix[0].length() * matrix.size();
		int64_t totalAreas = 0;
		auto &indexes = region.second;
		for (size_t i = 0; i < indexes.size(); i++)
			totalAreas += (indexes[i] * totalTiles[i]);

		if (bigArea >= totalAreas)
			this->totalRegionsFit++;
	}
}

void Solution::showResolution()
{
	std::cout << "The dirty solution is " << this->totalRegionsFit << "!" << std::endl;
}