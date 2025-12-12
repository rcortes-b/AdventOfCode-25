#ifndef SOLUTION_HPP
# define SOLUTION_HPP

#include "main.hpp"

class Solution {
	private:
			std::vector<std::pair<std::vector<std::string>, std::vector<int>>> regions;
			std::map<int, int> totalTiles;
			std::map<int, std::vector<std::string>> presents;
			int64_t totalRegionsFit = 0;

			void parseContent(std::vector<std::string> &content) {
				for (size_t i = 0; i < content.size(); i++) {
					std::string str = content[i];
					if (str[str.length() - 1] == ':') {
						int tiles = 0;
						int index = atoi(str.c_str());
						i++;
						while (!content[i].empty()) {
							for (char c : content[i]) {
								if (c == '#')
									tiles++;
							}
							presents[index].push_back(content[i]);
							i++;
						}
						totalTiles[index] = tiles;
					}
					else if (content[i][0] != '\n') {
						std::vector<std::string> region_map;
						std::vector<int> region_idx;
						int width = atoi(str.c_str());
						size_t pos = str.find('x') + 1;
						int longitude = atoi(str.substr(pos).c_str());
						while (--longitude >= 0)
							region_map.push_back(std::string(width, '.'));
						pos = str.find(':', pos) + 1;
						while (pos < str.length()) {
							if (std::isdigit(str[pos])) {
								region_idx.push_back(atoi(str.substr(pos).c_str()));
								while (std::isdigit(str[pos]))
									pos++;
							}
							else
								pos++;
						}
						regions.push_back({{region_map}, {region_idx}});
					}
				}
			}

			void debug_input() {
				std::cout << "---Listing indexes + presents---" << std::endl;
				for (auto it = presents.begin(); it != presents.end(); it++) {
					std::cout << "Index: " << it->first << std::endl;
					for (auto &str : it->second)
						std::cout << str << std::endl;
					std::cout << std::endl;
				}
				std::cout << "---Listing regions---" << std::endl;
				for (auto it = regions.begin(); it != regions.end(); it++) {
					auto &str = *it->first.begin();
					std::cout << it->first.size() << "x" << str.length() << ": ";
					auto &int_vec = it->second;
					for (auto &n : int_vec)
						std::cout << n << " ";
					std::cout << std::endl;
				}
			}
	public:
			Solution(std::vector<std::string> &content);
			void run();
			void runBonus();
			void showResolution();
};

#endif