#pragma once

#include <string>

using std::string;

class Resource
{
public:
	Resource(const int& i, const string& l_Data);
	~Resource() noexcept;
	Resource(const Resource& l_Resource);
	Resource& operator=(const Resource& l_Resource);
	Resource(Resource&& l_Resource) noexcept;
	Resource& operator=(Resource&& l_Resource);

	string PrintInfo();

	static int m_Count;

private:
	int m_Val = 0;
	string m_Data = "";

	// Ideally a resource class like this will wrap an actual resource, which could be critical and expensive to create
	// and timely realease of such resources is usually important.
};

