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

static char *modifyId(char *str) {
	//printf("start str: %s\n", str);
	int size = strlen(str) - 1;
	while (size >= 0) {
		if (str[size] != '9') {
			str[size]++;
			return str;
		}
		if (str[size] != '0')
			str[size] = '0';
		size--;
	}
	//printf("str: %s\n", str);
	char *new_str = NULL;
	if (str[0] == '0') {
		int new_size = strlen(str) + 1;
		new_str = malloc(sizeof(char) * (new_size + 1));
		if (!new_size)
			return NULL;
		int i = 1;
		new_str[0] = '1';
		while (i < new_size)
			new_str[i++] = '0';
		new_str[i] = '\0';
		free(str);
	}
	//printf("newstr: %s\n", new_str);
	return new_str;
}

static char *checkInvalid(char *str, unsigned long *totalIds) {

	int size = strlen(str);
	int del = size / 2;
	int c = 0;
	if (size % 2 == 0) {
		while (del < size) {
			if (str[c] != str[del])
				break ;
			c++;
			del++;
		}
		if (del == size) {
			
			*totalIds += atoll(str);
		}
	}
	return modifyId(str);
	
}

static unsigned long theGoodAlgo(char **ranges) {
	unsigned long totalIds = 0;
	while (*ranges != NULL) {
		char **ids = ft_split(*ranges, '-');
		char *new = strdup(*ids);
		int minRange = atoi(*ids);
		int maxRange = atoi(ids[1]);
		while (minRange++ <= maxRange) {
			new = checkInvalid(new, &totalIds);
		}
		*ranges++;
	}
	return totalIds;
}

int main(int argc, char **argv) {
	if (argc != 2)
		return 1;
	char *content = NULL;
	if (!strcmp(argv[1], fileName))
		content = getMapContent(fileName);
	else
		content = getMapContent(fileNameExample);
	if(!content)
		return (1);
	char **ranges = ft_split(content, ',');

	printf("\n%ld\n", theGoodAlgo(ranges));
	return (0);
}
