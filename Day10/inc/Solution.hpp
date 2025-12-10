#ifndef SOLUTION_HPP
# define SOLUTION_HPP

#include "main.hpp"

typedef struct s_machines {
	std::string indicator_lights;
	std::vector<std::string> buttons;
	std::vector<int> joltage_counters;
	int timesPressed;
	int timesPressedBonus;
}	t_machines;

struct CompareByValue {
    bool operator()(const int* a, const int* b) const {
        return *a < *b;
    }
};

class Solution {
	private:
			std::vector<std::string> content;
			t_machines *machines;
			int timesPressed;
			int timesPressedBonus;

			void parse_content() {
				machines = new t_machines[content.size()];
				for (size_t i = 0; i < content.size(); i++) {
					std::stringstream ss(content[i]);
					std::string str = "";
					while (ss >> str) {
						if (str[0] == '[')
							machines[i].indicator_lights = str.substr(1, str.length() - 2);
						else if (str[0] == '(')
							machines[i].buttons.push_back(str);
						else {
							for (size_t j = 0; j < str.length(); j++) {
								if (std::isdigit(str[j])) {
									machines[i].joltage_counters.push_back(atoi(str.substr(j).c_str()));
									while (std::isdigit(str[j]))
										j++;
								}
							}
						}
					}
					machines[i].timesPressed = machines[i].buttons.size();
					machines[i].timesPressedBonus = 0;
				}
			}
	public:
			Solution(std::vector<std::string> &content);
			~Solution() {
				delete[] machines;
			}
			void run();
			void runBonus();
			void showResolution();
			void recursive(t_machines &machine, std::string curr_panel, size_t button_index, int iterations);
};

#endif