#include "../inc/Solution.hpp"
#include "../inc/main.hpp"

Solution::Solution(std::vector<unsigned long> &freshIds, std::vector<unsigned long> &availableIds)
{
	this->freshIds = freshIds;
	this->availableIds = availableIds;
	this->totalAvailableIds = 0;
	this->totalAvailableIdsBonus = 0;
}

void Solution::run()
{
	int size = this->availableIds.size();
	int rangeSize = this->freshIds.size();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < rangeSize; j += 2) {
			if (availableIds[i] >= freshIds[j] && availableIds[i] <= freshIds[j + 1]) {
				this->totalAvailableIds++;
				break ;
			}
		}
	}
}

void Solution::runBonus()
{
	int size = freshIds.size();
	for (int i = 0; i < size; i += 2) {
		for (int j = 0; j < i;) {
			if (freshIds[i] > freshIds[j + 1] || freshIds[i + 1] < freshIds[j])
					j += 2;
			else
			{
				if (freshIds[i] > freshIds[j]) // Update the min value
					freshIds[i] = freshIds[j];
				if (freshIds[i + 1] < freshIds[j + 1]) // Update the max value
					freshIds[i + 1] = freshIds[j + 1];
				freshIds.erase(freshIds.begin() + j);
				freshIds.erase(freshIds.begin() + j);
				size -= 2;
				j = 0;
				i -= 2;
			}
		}
	}
	
	int rangesSize = freshIds.size();
	for (int i = 0; i < rangesSize; i += 2)
		this->totalAvailableIdsBonus += (freshIds[i + 1] - freshIds[i] + 1);	
}

void Solution::showResolution()
{
	std::cout << "The solution is " << this->totalAvailableIds << std::endl;
	std::cout << "The bonus solution is " << this->totalAvailableIdsBonus << std::endl;
	std::cout << std::endl;
}