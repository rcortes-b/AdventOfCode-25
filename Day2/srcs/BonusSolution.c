#include "../inc/Solution.h"

static char *modifyId(char *str) {
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
	return new_str;
}

static bool do_checker(char *str, int size) {
	int c = 1;
	int del = 0;
	int i = 0;
	while (c <= size / 2) {
		if (size % c == 0) {
			del = c;
			i = 0;
			while (del < size) {
				if (str[i] != str[del])
					break ;
				i++;
				del++;
			}
			if (del == size) {
				return true;
			}
		}
		c++;
	}
	return false;

}

static char *checkInvalid(char *str, unsigned long *totalIds) {

	int size = strlen(str);
	int del = size / 2;
	int c = 0;
	if (do_checker(str, size))
		*totalIds += atoll(str);
	return modifyId(str);
	
}

static unsigned long theGoodAlgo(char **ranges) {
	unsigned long totalIds = 0;
	while (*ranges != NULL) {
		char **ids = ft_split(*ranges, '-');
		char *new = ft_strdup(*ids);
		int minRange = atoi(*ids);
		int maxRange = atoi(ids[1]);
		while (minRange++ <= maxRange) {
			new = checkInvalid(new, &totalIds);
		}
		*ranges++;
		free_mem(ids, new);
	}
	return totalIds;
}

int main(int argc, char **argv) {
	if (argc != 2)
		return (printf("Map path as argument is mandatory.\n"), 1);
	char *content = getMapContent(argv[1]);
	if(!content)
		return (printf("File error.\n"), 1);
	char **ranges = ft_split(content, ',');
	if (!ranges)
		return (free(content), printf("Split error.\n"), 1);
	printf("\n%ld\n", theGoodAlgo(ranges));
	free_mem(ranges, content);
	return (0);
}
