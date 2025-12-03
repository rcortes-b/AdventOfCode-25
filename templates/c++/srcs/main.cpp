#include "../inc/main.hpp"
#include "../inc/FileParsing.hpp"
#include "../inc/Solution.hpp"

int main(int argc, char **argv) {
	if (argc != 2)
		return (printf("Map path as argument is mandatory.\n"), 1);

	FileParsing fp = FileParsing(argv[1]);
	
	/* Parse input */
	
	std::string content = fp.getContent();
	std::cout << "Unique line: " << content << std::endl;
	std::vector<std::string> contentVector = fp.getContentVector();
	std::cout << "\nParsed Lines in Vector" << std::endl;
	for (itVec it = contentVector.begin(); it != contentVector.end(); it++)
		std::cout << *it << std::endl;

	/* Load Solution Class */
	Solution solution = Solution();
	Solution solutionExample = Solution();

	solutionExample.run(content);
	solutionExample.run(contentVector);

	solution.run(content);
	solution.run(contentVector);
	
	return (0);
}
