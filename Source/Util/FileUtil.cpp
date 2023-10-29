#include "FileUtil.h"

#include <iostream>
#include <fstream>
#include <sstream>

std::string getFilecontent(std::string filePath)
{
	std::ifstream file(filePath);
	if (!file.is_open())
		std::cout << "Could not open File: " + filePath << std::endl;

	std::ostringstream s;
	s << file.rdbuf();

	file.close();

	return s.str();
}
