#include "../inc/Solution.hpp"
#include "../inc/main.hpp"

Solution::Solution(std::vector<std::string> &content)
{
	this->content = content;
	this->timelinesMemo = nullptr;
	this->splitTimes = 0;
	this->timelines = 0;
}

void Solution::move_bean(int y, int x)
{
	if (x == -1 || x == (int)content[0].length() || y == (int)content.size())
		return ;
	
	char c = content[y][x];
	if (c == '|')
		return;
	else if (c == '.') {
		content[y][x] = '|';
		move_bean(y + 1, x);
	}
	else {
		this->splitTimes++;
		move_bean(y, x - 1);
		move_bean(y, x + 1);
	}
}

void Solution::run()
{
	auto y_pos = 0;
	auto x_pos = 0;
	for (int x = 0; x < (int)content[y_pos].length(); x++) {
		if (content[y_pos][x] == 'S')
			x_pos = x;
	}
	move_bean(y_pos + 1, x_pos);
}

void Solution::runBonus()
{
	auto len = content[0].length();

	timelinesMemo = new unsigned long*[content.size() + 1];
	for (int y = 0; y < (int)content.size(); y++)
		timelinesMemo[y] = new unsigned long[len + 1];

	for (size_t y = 0; y < content.size(); y++) {
		for (size_t x = 0; x < content[y].length(); x++) {
			if (content[y][x] == 'S')
				timelinesMemo[y][x] = 1;
			else
				timelinesMemo[y][x] = 0;
		}
	}

	for (size_t y = 1; y < content.size(); y++) {
		for (size_t x = 0; x < content[y].length(); x++) {
			if (content[y][x] == '^') {
				timelinesMemo[y][x - 1] += timelinesMemo[y - 1][x];
				timelinesMemo[y][x + 1] += timelinesMemo[y - 1][x];
			}
			else if (timelinesMemo[y - 1][x] > 0)
				timelinesMemo[y][x] += timelinesMemo[y - 1][x];
		}
	}

	for (size_t y = 0; y < content.size(); y++) {
		for (size_t x = 0; x < len; x++) {
			if (y + 1 == content.size())
				this->timelines += timelinesMemo[y][x];
		}
	}
}

void Solution::showResolution()
{
	std::cout << "The solution is " << this->splitTimes << std::endl;
	std::cout << "The bonus solution is " << this->timelines << std::endl;
}