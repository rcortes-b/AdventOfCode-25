#include "../inc/Solution.hpp"
#include "../inc/main.hpp"

Solution::Solution(std::vector<std::string> &content)
{
	this->content = content;
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

int blabla(std::map<int, std::vector<int>> &circuits, int value)
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

void Solution::run()
{
	std::multimap<unsigned long, std::pair<int, int>> map;
	for (size_t y = 0; y < content.size(); y++)
	{
		for (size_t x = y + 1; x < content.size(); x++) {
			//if (y != x) {
				unsigned long distance = getEuclideanDistance(y, x);
				//if (!checkIfIsRepeated(map, distance, y, x))
				map.insert({distance, {y, x}});
			//}
		}
	}
	/*auto iter = map.begin();
	while (iter != map.end()) {
		auto seconditer = iter->second.begin();
		std::cout << iter->first << " " << seconditer->first << " " << seconditer->second << std::endl;
		iter++;
	}*/
	std::map<int, std::vector<int>> circuits;
	auto it = map.begin();
	auto pk = 0;
	auto p = 0;
	//while (++p < 11) {
	std::cout << "AQUI!! " << map.size() << std::endl;
	while (it != map.end()) {
		if (p == 1000)
			break;
		std::cout << "--------------------------" << std::endl;
		int firstindex = blabla(circuits, it->second.first);
		int secondindex = blabla(circuits, it->second.second);
		std::cout << "First Value: " << content[it->second.first] << " Second Value: " << content[it->second.first] << std::endl;
		std::cout << "First index: " << firstindex << " Second Index: " << secondindex << std::endl;
		if (firstindex >= 0 && firstindex == secondindex) {
			std::cout << "Same circuit..." << std::endl;
			//p--;
		}
		else if (firstindex == -1 && secondindex == -1) {
			std::cout << "Creating new circuit...\n";
			circuits[pk] = {it->second.first, it->second.second};
			pk++;
		}
		else if (firstindex == -1 && secondindex >= 0)
			circuits.find(secondindex)->second.push_back(it->second.first);
		else if (firstindex >= 0 && secondindex == -1)
			circuits.find(firstindex)->second.push_back(it->second.second);
		else {
			auto tmp = circuits.find(firstindex);
			auto tmp2 = circuits.find(secondindex);
			tmp->second.insert(tmp->second.end(), tmp2->second.begin(), tmp2->second.end());
			circuits.erase(secondindex);
		}

		it++;
		p++;
		std::cout << "--------------------------" << std::endl;
	}
	std::cout << "jiji\n\n\n";
	std::vector<int> circuitSizes;
	circuitSizes.clear();
	auto itSize = circuits.begin();
	while (itSize != circuits.end()) {
		std::cout << "Circuit key: " << itSize->first << " Value: " << itSize->second.size() << std::endl;
		for (size_t i = 0; i < itSize->second.size(); i++)
			std::cout << content[itSize->second[i]] << " ";
			//std::cout << itSize->second[i] << " ";
		std::cout << std::endl;
		circuitSizes.push_back(itSize->second.size());
		itSize++;
	}
	std::sort(circuitSizes.begin(), circuitSizes.end());  // ascending

		int n = circuitSizes.size();
		long long result = 1LL * circuitSizes[n-1] * circuitSizes[n-2] * circuitSizes[n-3];

	std:: cout << circuitSizes[n-1] << " " << circuitSizes[n-2] << " " << circuitSizes[n-3] << std::endl;
	std::cout << "Resultado is " << result << std::endl;
}

void Solution::runBonus()
{

}

void Solution::showResolution()
{
	std::cout << "The solution is " << " " << std::endl;
}