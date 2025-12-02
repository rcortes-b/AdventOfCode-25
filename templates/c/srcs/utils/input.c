#include "../../inc/Solution.h"

#define READ_SIZE 10

char* getMapContent(const char *path) {
	char *content = NULL;
	char buff[READ_SIZE];
	FILE *f = fopen(path, "r");
	if (!f)
		return NULL;
	memset(buff, '\0', READ_SIZE);
	while (fgets(buff, READ_SIZE, f) != NULL) {
		int size = strlen(buff);
		if (!content)
			content = ft_strdup(buff);
		else
			content = ft_strjoin(content, buff);
		if (!content) {
			fclose(f);
			return NULL;
		}
	}
	fclose(f);
	return content;
}