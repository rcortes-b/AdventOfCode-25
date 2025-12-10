#include "../inc/Solution.hpp"
#include "../inc/main.hpp"

Solution::Solution(std::vector<std::string> &content)
{
	this->content = content;
	this->machines = NULL;
	this->timesPressed = 0;
	this->timesPressedBonus = 0;
	parse_content();
}

void Solution::recursive(t_machines &machine, std::string curr_panel, size_t button_index, int iterations)
{
    if (iterations >= machine.timesPressed)
        return;

    if (curr_panel.compare(machine.indicator_lights) == 0) {
        machine.timesPressed = iterations;
        return;
    }
    
    for (size_t i = button_index; i < machine.buttons.size(); i++) {
    	std::string next_panel = curr_panel; 
        std::string button = machine.buttons[i];

        for (char c : button) {
            if (std::isdigit(c))
                next_panel[c - '0'] = (next_panel[c - '0'] == '.') ? '#' : '.';
        }
        recursive(machine, next_panel, i + 1, iterations + 1);
    }
}

void Solution::run()
{
    for (size_t i = 0; i < content.size(); i++) {
        size_t lightsLen = machines[i].indicator_lights.length();
        std::string panel(lightsLen, '.');
        recursive(machines[i], panel, 0,0);
    }
    for (size_t k = 0; k < content.size(); k++) {
		timesPressed += machines[k].timesPressed;
	}
}

//std::queue --> queue the first values with 1 push -> for each value queue a map of numOfPushes 
//-> for each value queued check if that value + numOfPushes has been already visited using a map/set of visited values

void Solution::runBonus()
{
	for (size_t i = 0; i < content.size(); i++) {
		std::queue<std::pair<int, std::vector<int>>> queue;
		t_machines &machine = machines[i];
		queue.push({0, std::vector<int>(machine.joltage_counters.size(), 0)});
		std::set<std::vector<int>> set;
		while (machine.timesPressedBonus == 0) {
			for (size_t j = 0; j < machine.buttons.size(); j++) {
				std::vector<int> new_counters(queue.front().second);

				for (size_t c = 0; c < machine.buttons[j].length(); c++) {
					if (std::isdigit(machine.buttons[j][c]))
						new_counters[machine.buttons[j][c] - '0']++;
				}
				auto result = set.insert(new_counters);
				if (!result.second)
					continue;
				bool terminateIteration = false;
				size_t k = 0;
				while (k < new_counters.size()) {
					if (new_counters[k] > machine.joltage_counters[k])
						terminateIteration = true;
					else if (new_counters[k] != machine.joltage_counters[k])
						break ;
					k++;
				}
				if (terminateIteration)
					continue ;
				if (k == new_counters.size()) {
					machine.timesPressedBonus = queue.front().first + 1;
					break ;
				}
				else
					queue.push({queue.front().first + 1, new_counters});
			}
			queue.pop();
		}
		this->timesPressedBonus += machine.timesPressedBonus;
	}
}

void Solution::showResolution()
{
	std::cout << "The solution is " << this->timesPressed << std::endl;
	std::cout << "The bonus solution is " << this->timesPressedBonus << std::endl;
}