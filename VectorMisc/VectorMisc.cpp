// VectorMisc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <memory>
#include "Resource.h"
#include <iostream>
#include <chrono>

using std::vector;
using std::unique_ptr;
using std::make_unique;
using std::cout;
using std::endl;
using std::to_string;
using std::chrono::system_clock;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::nanoseconds;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;

void InsertItems_WithReserve(const int& l_NumElements);
void InsertItems(const int& l_NumElements);
void InsertUniquePtr(const int& l_NumElements);
void EmplaceItems(const int& l_NumElements);
void EmplaceItems_WithReserve(const int& l_NumElements);

int main()
{
	InsertItems_WithReserve(10000);
	InsertItems(10000);
	InsertUniquePtr(10000);
	EmplaceItems_WithReserve(10000);
	EmplaceItems(10000);

	//cout << "Total instances created: " << to_string(Resource::m_Count) << endl;
	
	return 0;
}

void InsertItems_WithReserve(const int& l_NumElements)
{
	vector<Resource> l_vecResources;
	l_vecResources.reserve(l_NumElements);

	auto l_startTime = high_resolution_clock::now();
	std::generate_n(std::back_inserter(l_vecResources), l_NumElements, [l_Start = 0]() mutable
	{
		//cout << "====================================" << endl;
		string l_Info = "Item" + to_string(l_Start);
		return Resource(l_Start++, l_Info);
	});
	auto l_endTime = high_resolution_clock::now();
	cout << "Time taken - inserting with reserve (millisec): " << duration_cast<milliseconds>(l_endTime - l_startTime).count() << endl;
	cout << "Total instances created: " << to_string(Resource::m_Count) << endl;
	cout << "=====================================================================================================" << endl;
	Resource::m_Count = 0;

	/*auto l_startTime = high_resolution_clock::now();
	for (int i = 0; i < l_NumElements; ++i)
	{
	string l_Info = "Item" + to_string(i+1);
	l_vecResources.push_back(Resource(i + 1, l_Info));
	}
	auto l_endTime = high_resolution_clock::now();
	cout << "Time taken: " << duration_cast<milliseconds>(l_endTime - l_startTime).count() << endl;*/
}

void InsertItems(const int& l_NumElements)
{
	vector<Resource> l_vecResources;

	auto l_startTime = high_resolution_clock::now();
	std::generate_n(std::back_inserter(l_vecResources), l_NumElements, [l_Start = 0]() mutable
		{
			//cout << "====================================" << endl;
			string l_Info = "Item" + to_string(l_Start);
			return Resource(l_Start++, l_Info);
		});
	auto l_endTime = high_resolution_clock::now();
	cout << "Time taken - inserting (millisec): " << duration_cast<milliseconds>(l_endTime - l_startTime).count() << endl;
	cout << "Total instances created: " << to_string(Resource::m_Count) << endl;
	cout << "=====================================================================================================" << endl;
	Resource::m_Count = 0;

	/*auto l_startTime = high_resolution_clock::now();
	for (int i = 0; i < l_NumElements; ++i)
	{
		string l_Info = "Item" + to_string(i+1);
		l_vecResources.push_back(Resource(i + 1, l_Info));
	}
	auto l_endTime = high_resolution_clock::now();
	cout << "Time taken: " << duration_cast<milliseconds>(l_endTime - l_startTime).count() << endl;*/
}

void InsertUniquePtr(const int & l_NumElements)
{
	vector<unique_ptr<Resource>> l_vecResources;
	//l_vecResources.reserve(l_NumElements);

	auto l_startTime = high_resolution_clock::now();
	std::generate_n(std::back_inserter(l_vecResources), l_NumElements, [l_Start = 0]() mutable
	{
		//cout << "====================================" << endl;
		string l_Info = "Item" + to_string(l_Start);
		return make_unique<Resource>(l_Start + 1, l_Info);
	});
	auto l_endTime = high_resolution_clock::now();
	cout << "Time taken - unique ptr (millisec): " << duration_cast<milliseconds>(l_endTime - l_startTime).count() << endl;
	cout << "Total instances created: " << to_string(Resource::m_Count) << endl;
	cout << "=====================================================================================================" << endl;
	Resource::m_Count = 0;
}

void EmplaceItems_WithReserve(const int& l_NumElements)
{
	vector<Resource> l_vecResources;
	l_vecResources.reserve(l_NumElements);

	auto l_startTime = high_resolution_clock::now();
	for (int i = 0; i < l_NumElements; ++i)
	{
		string l_Info = "Item" + to_string(i + 1);
		l_vecResources.emplace_back(i + 1, l_Info);
	}
	auto l_endTime = high_resolution_clock::now();
	cout << "Time taken - emplacing with reserve (millisec): " << duration_cast<milliseconds>(l_endTime - l_startTime).count() << endl;
	cout << "Total instances created: " << to_string(Resource::m_Count) << endl;
	cout << "=====================================================================================================" << endl;
	Resource::m_Count = 0;
}

void EmplaceItems(const int& l_NumElements)
{
	vector<Resource> l_vecResources;

	auto l_startTime = high_resolution_clock::now();
	for (int i = 0; i < l_NumElements; ++i)
	{
		string l_Info = "Item" + to_string(i + 1);
		l_vecResources.emplace_back(i + 1, l_Info);
	}
	auto l_endTime = high_resolution_clock::now();
	cout << "Time taken - emplacing  (millisec): " << duration_cast<milliseconds>(l_endTime - l_startTime).count() << endl;
	cout << "Total instances created: " << to_string(Resource::m_Count) << endl;
	cout << "=====================================================================================================" << endl;
	Resource::m_Count = 0;
}

