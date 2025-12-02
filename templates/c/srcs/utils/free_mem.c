#include "../../inc/Solution.h"

void free_mem(char **arr, char *str) {
	if (arr) {
		int i = 0;
		while (arr[i]) {
			free(arr[i]);
			i++;
		}
		free(arr);
	}
	if (str)
		free(str);
}