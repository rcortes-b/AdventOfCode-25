#include "../inc/Solution.h"

#define READ_SIZE 10

static char *fileName = "map.txt";
static char *fileNameExample = "map_example.txt";

static char* getMapContent(const char *path) {
	char *content = NULL;
	char buff[READ_SIZE];
	FILE *f = fopen(path, "r");
	if (!f)
		return NULL;
	memset(buff, '\0', READ_SIZE);
	while (fgets(buff, READ_SIZE, f) != NULL) {
		int size = strlen(buff);
		if (!content)
			content = strdup(buff);
		else
			content = ft_strjoin(content, buff);
		if (!content)
			return NULL;
	}
	return content;
}

int main(int argc, char **argv) {
	if (argc != 2)
		return 1;
	char *content = NULL;
	if (!strcmp(argv[1], fileName))
		content = getMapContent(fileName);
	else
		content = getMapContent(fileNameExample);

	return (0);
}
