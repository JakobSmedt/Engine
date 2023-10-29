#pragma once

#include <string>
#include <unordered_map>

template<typename Type>
class Resource
{
public:
	 Resource(std::string folder, std::string extention)
		 : Folder		(folder)
		 , Extention	(extention)
	 { }

	 Type* get(std::string name)
	 {
		 if (resource.find(name) == resource.end())
			 add(name);
		 return &(resource.at(name));
	 }

	 void add(std::string name)
	 {
		 Type NewElement;

		 if (!NewElement.loadFromFile(getFullname(name)))
			 NewElement.loadFromFile(getFullname("_fail_"));

		 resource.insert({ name, NewElement });
	 }

private:
	std::string getFullname(std::string name) { return Folder + name + Extention; };

	std::string Folder, Extention;

	std::unordered_map<std::string, Type> resource;
};

