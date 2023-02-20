/*
** EPITECH PROJECT, 2022
** my project
** File description:
** main
*/

#include <iostream>
#include <stddef.h>
#include <string>
#include "my.hpp"
#include "nts.hpp"

#include <signal.h>

#include <iostream>

int handling_error(nts::ControlTower::Error e, std::string name)
{
    switch (e.type) {
        case nts::ControlTower::Error::LEX:
            std::cerr << e.what() << std::endl;
            return ERROR_VALUE;
        case nts::ControlTower::Error::TYPE:
            std::cerr << e.what() << name << "'." << std::endl;
            return ERROR_VALUE;
        case nts::ControlTower::Error::NAME:
            std::cerr << e.what() << name << "'." << std::endl;
            return ERROR_VALUE;
        case nts::ControlTower::Error::SAME:
            std::cerr << "'" << name << e.what() << std::endl;
            return ERROR_VALUE;
        case nts::ControlTower::Error::CHIPSET:
            std::cerr << e.what() << std::endl;
            return ERROR_VALUE;
        default: return 0;
    }

    return 0;
}

int main(int argc, char **argv, char **env)
{
    if (env[0] == NULL || argc != 2)
        return ERROR_VALUE;

    nts::ControlTower *tower = parse(argv[1]);

    if (tower == nullptr)
        return ERROR_VALUE;

    if (handling_error(tower->_error, tower->_nameError) == ERROR_VALUE) {
        delete tower;
        return ERROR_VALUE;
    }

    execution(tower);

    delete tower;
    return END_VALUE;
}
