#include "../inc/Solution.hpp"
#include "../inc/main.hpp"

Solution::Solution(std::vector<std::string> &content)
{
	this->content = content;
	std::string getLast = content[content.size() - 1]; 
	getLast.erase(std::remove_if(getLast.begin(), getLast.end(), ::isspace), getLast.end());
	this->operators = getLast;
	this->content.pop_back();
	this->totalSum = 0;
	this->totalBonusSum = 0;
}

void Solution::run()
{
	size_t size = this->content.size();
	for (size_t i = 0; i < size; i++) {
		size_t length = this->content[i].length();
		auto c = 0;
		std::string &line = this->content[i];
		for (size_t j = 0; j < length;) {
			if (std::isdigit(line[j]))
			{
				if (i == 0)
					this->numbers.push_back(atoll(line.substr(j).c_str()));
				else
					do_operation(atoll(line.substr(j).c_str()), c);
				c++;
				j = line.find(' ', j);
			}
			else
				j++;
		}
	}
	for (itVec it = numbers.begin(); it != numbers.end(); it++)
		totalSum += *it;
}

void Solution::runBonus()
{
	Solution::normalizeInput();
	numbers.clear();
	size_t size = this->content.size();
	int getNum = 0;
	unsigned long totalColNumber = 0;
	auto c = 0;
	for (int len = this->content[0].length() - 1; len >= 0; len--) {
		getNum = Solution::getColNumber(len, size);
		if (getNum == 0)
		{
			numbers.push_back(totalColNumber);
			c++;
			totalColNumber = 0;
		}
		else
		{
			this->do_operation(totalColNumber, getNum, c);
			if (len == 0)
				numbers.push_back(totalColNumber);
		}
	}
	for (itVec it = numbers.begin(); it != numbers.end(); it++)
		totalBonusSum += *it;
}

void Solution::showResolution()
{
	std::cout << "The solution is " << totalSum << std::endl;
	std::cout << "The bonus solution is " << totalBonusSum << std::endl;
}