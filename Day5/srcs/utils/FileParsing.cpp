#include "../../inc/FileParsing.hpp"

FileParsing::FileParsing(const char *path)
{
	this->path = std::string(path);
	std::ifstream myFile;
	this->openFile(myFile);
	this->readFile(myFile);
	this->closeFile(myFile);
}

std::vector<unsigned long> FileParsing::getFreshIds()
{
	return (this->freshIds);
}

std::vector<unsigned long> FileParsing::getAvailableIds()
{
	return (this->availableIds);
}

void FileParsing::openFile(std::ifstream &myFile)
{
	myFile.open(this->path, std::ios::in);
	if (!myFile.is_open()) {
		std::cerr << "Error: File could not be opened" << std::endl;
		exit(1);
	}
}

void FileParsing::readFile(std::ifstream &myFile)
{
	std::string line = "";
	while(std::getline(myFile, line))
	{
		if (line.empty())
			break ;
		int pos = line.find('-', 0);
		std::string first = line.substr(0, pos);
		pos++;
		std::string second = line.substr(pos, line.length() - pos);
		this->freshIds.push_back(atoll(first.c_str()));
		this->freshIds.push_back(atoll(second.c_str()));
	}
	while(std::getline(myFile, line))
	{
		this->availableIds.push_back(atoll(line.c_str()));
	}
	if (myFile.bad())
	{
		std::cerr << "Error: Something happened while reading the file" << std::endl;
		exit(1);
	}
}

void FileParsing::closeFile(std::ifstream &myFile)
{
	myFile.close();
}