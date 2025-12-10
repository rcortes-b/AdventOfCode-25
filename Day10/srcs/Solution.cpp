#include "../inc/Solution.hpp"
#include "../inc/main.hpp"

Solution::Solution(std::vector<std::string> &content)
{
	this->content = content;
	this->machines = NULL;
	this->timesPressed = 0;
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

void Solution::showResolution()
{
	std::cout << "The solution is " << this->timesPressed << std::endl;
}