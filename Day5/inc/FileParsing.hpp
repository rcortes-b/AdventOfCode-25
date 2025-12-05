#ifndef FILEPARSING_HPP
# define FILEPARSING_HPP

#include "main.hpp"
#include <fstream>

#define READ_SIZE 10

class FileParsing {
	private:
			std::string		path;
			std::vector<unsigned long> freshIds;
			std::vector<unsigned long> availableIds;
	public:
			FileParsing(const char *path);
			void openFile(std::ifstream &myFile);
			void closeFile(std::ifstream &myFile);
			void readFile(std::ifstream &myFile);
			std::vector<unsigned long> getFreshIds();
			std::vector<unsigned long> getAvailableIds();
			
};

#endif