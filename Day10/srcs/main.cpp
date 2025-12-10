#include "../inc/main.hpp"
#include "../inc/FileParsing.hpp"
#include "../inc/Solution.hpp"

const char *input = "map.txt";
const char *inputExample = "map_example.txt";

int main() {
	FileParsing fpExample = FileParsing(inputExample);
	FileParsing fp = FileParsing(input);

	std::vector<std::string> contentExample = fpExample.getContentVector();
	std::vector<std::string> content = fp.getContentVector();

	/* Load Solution Class */
	Solution solutionExample = Solution(contentExample);
	Solution solution = Solution(content);

	solutionExample.run();
	solutionExample.showResolution();
	auto start = std::chrono::high_resolution_clock::now();
	solution.run();
	auto end = std::chrono::high_resolution_clock::now();
	solution.showResolution();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << "The level 1 duration was " << duration.count() << "ms" << std::endl;
	
	return (0);
}
