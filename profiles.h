#include <string>
#include <vector>

#pragma once 

struct profile
{
    std::string name;
    int attempts;
};

void out_file_prflist(const std::string file_name, std::vector<profile> &vec);

profile* find_prfname(std::vector<profile> &vec, const profile &prf);

void add_to_prflist(std::vector<profile> &vec, profile &prf);

void print_prflist(std::vector<profile> &vec);

void get_prflist(std::string file_name, std::vector<profile> &vec);


