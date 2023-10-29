#pragma once

#include <string>
#include <sstream>
#include <vector>
#include <iostream>

#include "../../Util/FileUtil.h"

class DialogSystem
{
public:
	DialogSystem();
	~DialogSystem();

	void getCurrentDialog(std::string path);
private:

	std::vector<std::vector<std::string>> currentDialog;
};

