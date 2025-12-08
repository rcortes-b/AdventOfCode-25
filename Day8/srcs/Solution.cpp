#include "../inc/Solution.hpp"
#include "../inc/main.hpp"

Solution::Solution(std::vector<std::string> &content, int totalPairsToConnect)
{
	this->content = content;
	this->totalPairsToConnect = totalPairsToConnect;
	parseCoords();
}

void Solution::parseCoords()
{
	auto pos = 0;
	coords = new int*[content.size() + 1];
	coords[content.size()] = 0;
	for (size_t y = 0; y < content.size(); y++) {
		coords[y] = new int[3];
		pos = content[y].find(',');
		coords[y][0] = atoi(content[y].substr(0, pos).c_str());
		pos += 1;
		coords[y][1] = atoi(content[y].substr(pos, content[y].find(',', pos) - pos).c_str());
		pos = content[y].find(',', pos) + 1;
		coords[y][2] = atoi(content[y].substr(pos).c_str());
	}
}

unsigned long Solution::getEuclideanDistance(int idx_curr, int idx_coord)
{
	unsigned long x_value = pow((coords[idx_coord][0] - coords[idx_curr][0]), 2);
	unsigned long y_value = pow((coords[idx_coord][1] - coords[idx_curr][1]), 2);
	unsigned long z_value = pow((coords[idx_coord][2] - coords[idx_curr][2]), 2);
	return ((x_value + y_value + z_value));
}

int Solution::indexOfCircuit(std::map<int, std::vector<int>> &circuits, int value)
{
	auto it = circuits.begin();
	while (it != circuits.end()) 
	{
		for (size_t i = 0; i < it->second.size(); i++) {
			if (it->second[i] == value)
				return it->first;
		}
		it++;
	}
	return -1;
}

void Solution::calculateLargestCircuits(std::map<int, std::vector<int>> &circuits) {
	std::vector<int> circuitSizes;
	auto it = circuits.begin();
	while (it != circuits.end()) {
		circuitSizes.push_back(it->second.size());
		it++;
	}
	std::sort(circuitSizes.begin(), circuitSizes.end());  // ascending

	size_t size = circuitSizes.size();
	this->largestCircuits = 1UL * circuitSizes[size - 1] * circuitSizes[size - 2] * circuitSizes[size - 3];
	this->setFirstLevelEndTime();
}

void Solution::run()
{
	std::multimap<unsigned long, std::pair<int, int>> map;
	for (size_t y = 0; y < content.size(); y++)
	{
		for (size_t x = y + 1; x < content.size(); x++)
			map.insert({getEuclideanDistance(y, x), {y, x}});
	}

	std::map<int, std::vector<int>> circuits;
	auto it = map.begin();
	auto pk = 0;
	auto pairsToConnect = 0;
	bool isConnection = true;

	while (it != map.end()) {
		isConnection = true;
		if (pairsToConnect == this->totalPairsToConnect)
			calculateLargestCircuits(circuits);
		int firstindex = indexOfCircuit(circuits, it->second.first);
		int secondindex = indexOfCircuit(circuits, it->second.second);
		if (firstindex == secondindex) {
			isConnection = false;
			if (firstindex == -1)
				circuits[pk++] = {it->second.first, it->second.second};
		}
		else if (firstindex == -1 && secondindex >= 0)
			circuits.find(secondindex)->second.push_back(it->second.first);
		else if (firstindex >= 0 && secondindex == -1)
			circuits.find(firstindex)->second.push_back(it->second.second);
		else {
			auto firstCircuit = circuits.find(firstindex);
			auto secondCircuit = circuits.find(secondindex);
			firstCircuit->second.insert(firstCircuit->second.end(), secondCircuit->second.begin(), secondCircuit->second.end());
			circuits.erase(secondindex);
		}
		if (isConnection) {
			lastConnection = atoll(content[it->second.first].substr(0, content[it->second.first].find(',')).c_str()) *
							 atoll(content[it->second.second].substr(0, content[it->second.second].find(',')).c_str());
		}
		it++;
		pairsToConnect++;
	}
}

void Solution::showResolution()
{
	std::cout << "The solution is " << this->largestCircuits << std::endl;
	std::cout << "The bonus solution is " << this->lastConnection << std::endl;
}