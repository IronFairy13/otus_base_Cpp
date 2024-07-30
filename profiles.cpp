#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#include "profiles.h"



// download the list of profiles from file in vector
void get_prflist(std::string file_name, std::vector<profile> &vec)
{

	std::ifstream in_file{file_name};
	if (!in_file.is_open())
	{
		//std::cout << "Failed to open file for read: " << file_name << "!" << std::endl;
		return;
	}
	if(in_file.peek() == std::ifstream::traits_type::eof()){
		//std::cout << "File is empty." << std::endl;
		return;
	}
	profile read_profile;
	while (true)
	{
		in_file >> read_profile.name;
		in_file >> read_profile.attempts;
		in_file.ignore();

		if (in_file.fail())
		{
			break;
		}

		vec.push_back(read_profile);
		
	}
}

// print profile list from vector
void print_prflist(std::vector<profile> &vec)
{
	std::cout << "High scores table:" << "\n";
	int i = 1;
	for (const profile& prf : vec)
	{
		
		std::cout << i << ". " << prf.name << " " << prf.attempts << "\n";
		i++;
	}
	std::cout << std::endl;
}

// add new profile in the profile list and sort
void add_to_prflist(std::vector<profile> &vec, profile &prf)
{

	profile *ptr = find_prfname(vec, prf);

	if (ptr == nullptr)
	{
		vec.push_back(prf);
		sort(vec.begin(), vec.end(), [](const profile &a, const profile &b)
			 { return a.attempts < b.attempts; });
		return;
	}
	if(ptr->attempts >= prf.attempts)
	{
	ptr->attempts = prf.attempts;
	}
	sort(vec.begin(), vec.end(), [](const profile &a, const profile &b)
		 { return a.attempts < b.attempts; });
	return;
}

// searching the name of profiles in the vector
profile *find_prfname(std::vector<profile> &vec, const profile &prf)
{
	auto it = std::find_if(vec.begin(), vec.end(), [&prf](const profile &p)
						   { return (prf.name.empty() || p.name == prf.name); });
	return (it != vec.end()) ? &(*it) : nullptr;
}

// save the high score table in file
void out_file_prflist(const std::string file_name, std::vector<profile> &vec)
{

	std::ofstream out_file{file_name, std::ios_base::trunc};

	if (!out_file.is_open())
	{
		std::cout << "Failed to open file for write: " << file_name << "!" << std::endl;
		return ;
	}

	for (profile prf : vec)
	{
		out_file << prf.name << ' ';
		out_file << prf.attempts;
		out_file << std::endl;
	
	}
	return ;
}

