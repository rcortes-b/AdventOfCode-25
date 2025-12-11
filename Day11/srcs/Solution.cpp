#include "../inc/Solution.hpp"
#include "../inc/main.hpp"

Solution::Solution(std::unordered_map<std::string, std::vector<std::string>> &content)
{
	this->content = content;
	this->leadingPaths = 0;
	this->numOfValidPaths = 0;
}

void Solution::run()
{
	std::queue<std::string> queue;
	
	queue.push("you");

	while (!queue.empty()) {
		for (std::string &node : content[queue.front()]) {
			if (node == "out") {
				this->leadingPaths++;
				continue ;
			}
			queue.push(node);
		}
		queue.pop();
	}
}

/* Learning memoization fundamentals */

int64_t Solution::do_recursive(const std::string &node, bool isDac, bool isFft, memo_data_t &memo)
{
	if (node == "dac")
		isDac = true;
	else if (node == "fft")
		isFft = true;
	if (node == "out")
		return (isDac && isFft);
	auto tup = std::make_tuple(node, isDac, isFft);
	if (memo.count(tup))
		return memo[tup];
	int64_t total = 0;
	for (std::string &n : content[node])
		total += do_recursive(n, isDac, isFft, memo);
	
	memo[tup] = total;
	return total;
}

void Solution::runBonus()
{
	memo_data_t memo;
	this->numOfValidPaths = do_recursive("svr", false, false, memo);
}

void Solution::showResolution(bool printSolution, bool printBonus)
{
	if (printSolution)
		std::cout << "The solution is " << this->leadingPaths << std::endl;
	if (printBonus)
		std::cout << "The bonus solution is " << this->numOfValidPaths << std::endl;
}

/*void Solution::runBonus()
{
	std::queue<std::pair<std::set<std::string>, std::string>> queue;
	queue.push({{"svr"}, "svr"});
	//std::map<std::string, int> timesVisited;
	while(!queue.empty()) {
		//Consigo el vector de la primera posicion de la cola
		auto node = queue.front().second;
		//Consigo el set de la primera posicion de la cola
		auto curr_set = queue.front().first;
		//Consigo el valor de la ultima posicion del vector de la cola
		queue.pop();
		if (node == "out") {
			bool isDac = curr_set.insert("dac").second; 
			bool isFft = curr_set.insert("fft").second;
			if (!isDac && !isFft)
				this->numOfValidPaths++;
			continue;
		}
		//Consigo gracias al valor de la ultima posicion, el vector del mapa que corresponde a la key
		auto contentVec = content[node];
		for (size_t i = 0; i < contentVec.size(); i++) {
			auto new_set = curr_set;
			auto result = new_set.insert(contentVec[i]);
			if (!result.second)
				continue ;
			queue.push({{new_set}, {contentVec[i]}});
		}
	}

}*/