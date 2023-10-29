#include "DialogSystem.h"


DialogSystem::DialogSystem()
{

}

DialogSystem::~DialogSystem()
{

}

void DialogSystem::getCurrentDialog(std::string path)
{
	std::string s = getFilecontent(path);

	unsigned index = 0;
	unsigned subindex = 0;
	
	while (true)
	{
		unsigned i = s.find('\\');
		std::istringstream iss(std::to_string(s[i + 2]));

		switch (s[i+1])
		{
		case 'C':
			break;
		default:
			break;
		}
	}
}
