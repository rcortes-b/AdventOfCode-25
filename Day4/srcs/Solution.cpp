#include "../inc/Solution.hpp"
#include "../inc/main.hpp"

Solution::Solution() {}

Solution::Solution(std::vector<std::string> &content)
{
	this->height = content.size();
	this->width = content[0].length();
	this->rollsAccessed = 0;
	this->rollsRemoved = 0;
	this->content = content;
}

void Solution::run()
{
	int nOfAdjacent = 0;
	for (int y = 0; y < this->height; y++) {
		for (int x = 0; x < this->width; x++) {
			nOfAdjacent = 0;
			if (content[y][x] == '@')
			{
				nOfAdjacent += (int)this->checkAdjacent(x - 1, y - 1);
				nOfAdjacent += (int)this->checkAdjacent(x, y - 1);
				nOfAdjacent += (int)this->checkAdjacent(x + 1, y - 1);
				nOfAdjacent += (int)this->checkAdjacent(x - 1, y);
				nOfAdjacent += (int)this->checkAdjacent(x + 1, y);
				nOfAdjacent += (int)this->checkAdjacent(x - 1, y + 1);
				nOfAdjacent += (int)this->checkAdjacent(x, y + 1);
				nOfAdjacent += (int)this->checkAdjacent(x + 1, y + 1);
				if (nOfAdjacent < 4)
					this->rollsAccessed++;
			}
		}
	}
}

void Solution::runBonus()
{
	int nOfAdjacent = 0;
	int totalRemoved = -1;
	while (totalRemoved != 0)
	{
		totalRemoved = 0;
		for (int y = 0; y < this->height; y++) {
			for (int x = 0; x < this->width; x++) {
				nOfAdjacent = 0;
				if (content[y][x] == '@')
				{
					nOfAdjacent += (int)this->checkAdjacent(x - 1, y - 1);
					nOfAdjacent += (int)this->checkAdjacent(x, y - 1);
					nOfAdjacent += (int)this->checkAdjacent(x + 1, y - 1);
					nOfAdjacent += (int)this->checkAdjacent(x - 1, y);
					nOfAdjacent += (int)this->checkAdjacent(x + 1, y);
					nOfAdjacent += (int)this->checkAdjacent(x - 1, y + 1);
					nOfAdjacent += (int)this->checkAdjacent(x, y + 1);
					nOfAdjacent += (int)this->checkAdjacent(x + 1, y + 1);
					if (nOfAdjacent < 4) {
						totalRemoved++;
						content[y][x] = '.';
					}
				}
			}
		}
		this->rollsRemoved += totalRemoved;
	}
}

void Solution::showResolution()
{
	std::cout << "The number of forklifts with access is " << this->rollsAccessed << std::endl;
	std::cout << "The number of rolls removed is " << this->rollsRemoved << std::endl;
}