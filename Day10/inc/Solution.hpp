#ifndef SOLUTION_HPP
# define SOLUTION_HPP

#include "main.hpp"

typedef struct s_machines {
	std::string indicator_lights;
	std::vector<std::string> buttons;
	int timesPressed;
}	t_machines;

class Solution {
	private:
			std::vector<std::string> content;
			t_machines *machines;
			int timesPressed;

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
						}
					machines[i].timesPressed = machines[i].buttons.size();
				}
			}
	public:
			Solution(std::vector<std::string> &content);
			~Solution() {
				delete[] machines;
			}
			void run();
			void showResolution();
			void recursive(t_machines &machine, std::string curr_panel, size_t button_index, int iterations);
};

#endif