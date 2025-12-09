#ifndef MAIN_HPP
# define MAIN_HPP

#include <iostream>
#include <unistd.h>
#include <vector>
#include <map>
#include <iterator>
#include <stdexcept>
#include <chrono>
#include <algorithm>
#include <climits>

char	*getMapContent(const char *path);
void free_mem(char **arr, char *str);

typedef std::vector<std::string>::iterator itVec;

#endif