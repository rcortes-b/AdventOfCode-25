#include "../inc/main.hpp"
#include "../inc/FileParsing.hpp"
#include "../inc/Solution.hpp"

int main(int argc, char **argv) {
	if (argc != 2)
		return (printf("Map path as argument is mandatory.\n"), 1);

	FileParsing fp = FileParsing(argv[1]);
	
 	std::vector<std::string> contentVector = fp.getContentVector();

	/* Load Solution Class */
	Solution solution = Solution(contentVector);

	auto start = std::chrono::high_resolution_clock::now();
	solution.run();
	solution.runBonus();
	auto end = std::chrono::high_resolution_clock::now();
	solution.showResolution();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << "The program duration was " << duration.count() << "ms" << std::endl;
	
	return (0);
}
