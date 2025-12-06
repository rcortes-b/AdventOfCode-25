#ifndef SOLUTION_HPP
# define SOLUTION_HPP

#include "main.hpp"

class Solution {
	private:
			std::vector<std::string> content;
			std::string operators;
			std::vector<unsigned long> numbers;
			unsigned long totalSum;
			unsigned long totalBonusSum;

			void do_operation(unsigned long num, int index) {
				if (this->operators[index] == '+')
					numbers[index] += num;
				else
					numbers[index] *= num;
			}

			void do_operation(unsigned long &total, int num, int index) {
				if (this->operators[this->operators.length() - index - 1] == '+')
					total += num;
				else {
					if (!total)
						total = 1;
					total *= num;
				}
			}

			int getColNumber(size_t len, size_t size)
			{
				int num = 0;
				for (size_t y = 0; y < size; y++) {
					if (std::isdigit(content[y][len]))
						num = num * 10 + (content[y][len] - '0');
				}
				return num;
			}

			void normalizeInput()
			{
				size_t size = content.size();
				size_t maxLen = 0;
				for (size_t y = 0; y < size; y++) {
					size_t len = content[y].length();
					if (len > maxLen)
						maxLen = len;
				}
				for (size_t i = 0; i < size; i++) {
					size_t fill = maxLen - content[i].length();
					while (fill != 0) {
						content[i].append(" ");
						fill--;
					}
				}
			}
			
	public:
			Solution(std::vector<std::string> &content);
			void run();
			void runBonus();
			void showResolution();
};

#endif