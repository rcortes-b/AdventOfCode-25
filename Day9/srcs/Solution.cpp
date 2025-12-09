#include "../inc/Solution.hpp"
#include "../inc/main.hpp"

Solution::Solution(std::vector<std::string> &content)
{
	this->content = content;
	this->maxArea = 0;
	this->maxInsideArea = 0;
	this->fillCoords();
}

void Solution::run()
{
	unsigned long area, max = 0;
	long long x, y;
	size_t size = content.size();
	for (size_t i = 0; i < size - 1; i++) {
		for (size_t j = i + 1; j < size; j++) {
			x = coords[i].first - coords[j].first + 1;
			if (x < 0)
				x *= -1;
			y = coords[i].second - coords[j].second + 1;
			if (y < 0)
				y *= -1;
			area = y * x;
			if (area > max)
				max = area;
		}
	}
	this->maxArea = max;
}

void Solution::runBonus()
{
	unsigned long area, max = 0;
	long long x, y, x2, y2, x1a, y1a, x2a, y2a;
	size_t size = content.size();
	for (size_t i = 0; i < size - 1; i++) {
		for (size_t j = i + 1; j < size; j++) {
			x = coords[i].first < coords[j].first ? coords[i].first : coords[j].first;
			y = coords[i].second < coords[j].second ? coords[i].second : coords[j].second;
			x2 = coords[i].first > coords[j].first ? coords[i].first : coords[j].first;
			y2 = coords[i].second > coords[j].second ? coords[i].second : coords[j].second;
			area = (y2 - y + 1) * (x2 - x + 1);
			if (area > max) {
				size_t k = 0;
				while (k < size) {
					size_t l = (k + 1 == size) ? 0 : k + 1;
					x1a = coords[k].first < coords[l].first ? coords[k].first : coords[l].first;
					y1a = coords[k].second < coords[l].second ? coords[k].second : coords[l].second;
					x2a = coords[k].first > coords[l].first ? coords[k].first : coords[l].first;
					y2a = coords[k].second > coords[l].second ? coords[k].second : coords[l].second;
					if (x1a < x2 && y1a < y2 && x2a > x && y2a > y)
						break;
					k++;
				}
				if (k == size)
					max = area;
			}
		}
	}
	this->maxInsideArea = max;
}

void Solution::showResolution()
{
	std::cout << "The solution is " << this->maxArea << std::endl;
	std::cout << "The bonus solution is " << this->maxInsideArea << std::endl;
}