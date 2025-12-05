#include "../inc/main.hpp"
#include "../inc/FileParsing.hpp"
#include "../inc/Solution.hpp"

const char *input = "map.txt";
const char *inputExample = "map_example.txt";

// too low 1813656443

int main() {
	FileParsing fpExample = FileParsing(inputExample);
	FileParsing fp = FileParsing(input);
	
	/*
	Get input --- Instead of a vector i can have a unique string if the input is a single line
	std::string contentExample = fpExample.getContent();
	std::string content = fp.getContent();
	*/
	std::vector<unsigned long> freshIdsExample = fpExample.getFreshIds();
	std::vector<unsigned long> availableIdsExample = fpExample.getAvailableIds();

	std::vector<unsigned long> freshIds = fp.getFreshIds();
	std::vector<unsigned long> availableIds = fp.getAvailableIds();

	/* Load Solution Class */
	Solution solutionExample = Solution(freshIdsExample, availableIdsExample);
	Solution solution = Solution(freshIds, availableIds);

	solutionExample.run();
	solutionExample.runBonus();
	solutionExample.showResolution();

	auto start = std::chrono::high_resolution_clock::now();
	solution.run();
	auto end = std::chrono::high_resolution_clock::now();
	solution.runBonus();
	auto endBonus = std::chrono::high_resolution_clock::now();
	solution.showResolution();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	auto durationBonus = std::chrono::duration_cast<std::chrono::milliseconds>(endBonus - end);
	std::cout << "The level 1 duration was " << duration.count() << "ms" << std::endl;
	std::cout << "The level 2 duration was " << durationBonus.count() << "ms" << std::endl;
	
	return (0);
}
