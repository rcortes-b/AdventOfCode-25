#ifndef FILEPARSING_HPP
# define FILEPARSING_HPP

#include "main.hpp"
#include <fstream>

#define READ_SIZE 10

class FileParsing {
	private:
			std::string		path;
			std::string		content;
			std::vector<std::string> contentVector;
	public:
			FileParsing(const char *path);
			void openFile(std::ifstream &myFile);
			void closeFile(std::ifstream &myFile);
			void readFile(std::ifstream &myFile);
			std::string getContent();
			std::vector<std::string> getContentVector();
			
};

#endif