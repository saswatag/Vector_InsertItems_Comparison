#include "stdafx.h"
#include "Resource.h"
#include <iostream>

using std::cout;
using std::endl;
using std::to_string;

int Resource::m_Count = 0;

Resource::Resource(const int & i, const string & l_Data) : m_Val(i), m_Data(l_Data)
{
	//cout << "Constructing " << to_string(m_Val)  + m_Data << endl;
	m_Count++;
}

Resource::~Resource() noexcept
{
	//cout << "Destructing " << to_string(m_Val) + m_Data << endl;
}

Resource::Resource(const Resource& l_Resource) : m_Val(l_Resource.m_Val), m_Data(l_Resource.m_Data)
{
	cout << "Copy Constructing " << to_string(m_Val) + m_Data << endl;
	m_Count++;
}

Resource& Resource::operator=(const Resource& l_Resource)
{
	// if Resource actually held a resource, clean/release the resource held by 'this' before assigning new resource 
	// from l_Resource
	
	m_Val = l_Resource.m_Val;
	m_Data = l_Resource.m_Data;

	return *this;
}

Resource::Resource(Resource&& l_Resource) noexcept : m_Val(l_Resource.m_Val), m_Data(std::move(l_Resource.m_Data) )
{
	//cout << "Move Constructing " << to_string(m_Val) + m_Data << endl;
	m_Count++;
}

Resource& Resource::operator=(Resource && l_Resource)
{
	// if Resource actually held a resource, clean/release the resource held by 'this' before assigning new resource 
	// from l_Resource
	if (this != &l_Resource)
	{
		m_Val = l_Resource.m_Val;
		m_Data = std::move(l_Resource.m_Data);
		l_Resource.m_Data.clear();
	}

	return *this;
}

string Resource::PrintInfo()
{
	return to_string(m_Val) + m_Data;
}
