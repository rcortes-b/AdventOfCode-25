#include "../inc/Solution.h"

int main(int argc, char **argv) {
	if (argc != 2)
		return (printf("Map path as argument is mandatory.\n"), 1);
	char *content = getMapContent(argv[1]);
	if(!content)
		return (printf("File error.\n"), 1);
	
	free(content);
	return (0);
}
