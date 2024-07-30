#include "parametrs.h"

#include <iostream>

bool check_parametrs(int argc, char **argv)
{
    if (argc >= 2)
    {
        std::string arg1_value{argv[1]};
        if (arg1_value == "-table")
        {
            return 1;
        }

        if (arg1_value == "-max")
        {
            int parameter_value = 0;
            parameter_value = std::stoi(argv[2]);
            max_value = parameter_value;
            return 1;
        }
        if (arg1_value == "-level")
        {
            int parameter_value = 0;
            parameter_value = std::stoi(argv[2]);
            switch (parameter_value)
            {
            case 1:
                max_value = 10;
                break;

            case 2:
                max_value = 50;
                break;

            case 3:
                max_value = 100;
                break;
            }
        }
    }
    return 0;
}
