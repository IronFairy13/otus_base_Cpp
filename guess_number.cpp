
#include "profiles.h"
#include "parametrs.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

int max_value = 100;

int main(int argc, char **argv)
{

    const std::string high_scores_filename = "high_scores.txt";

    std::vector<profile> profile_list;

    get_prflist(high_scores_filename, profile_list);

    if (check_parametrs(argc, argv))
    {
        print_prflist(profile_list);
        return 0;
    }
    std::cout << "Welcome to the game" << "\n";
    std::cout << "GUESS THE NUMBER!" << "\n";
    std::cout << "Please write your nickname." << std::endl;

    profile new_prf = {};
    std::cin >> new_prf.name;

    std::cout << "Write the number" << std::endl;

    int number = -1;

    std::cin >> number;

    std::srand(std::time(nullptr));
    const int random_value = std::rand() % max_value;

    while (true)
    {
        new_prf.attempts++;
        if (number < random_value)
        {
            std::cout << "greater than " << number << std::endl;
            std::cin >> number;
        }
        else if (number > random_value)
        {
            std::cout << "less than " << number << std::endl;
            std::cin >> number;
        }
        else
            break;
    }

    std::cout << "You win!" << std::endl;

    add_to_prflist(profile_list, new_prf);
    print_prflist(profile_list);
    out_file_prflist(high_scores_filename, profile_list);

    return 0;
}
