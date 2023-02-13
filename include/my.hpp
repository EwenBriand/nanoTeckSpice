/*
** EPITECH PROJECT, 2021
** libmy.h
** File description:
** creat the header of the libmy.a
*/

#ifndef _LIBALL_POOL
#define _LIBALL_POOL

#include "../src/Comp/Clock/Clock.hpp"
#include "../src/Comp/False/False.hpp"
#include "../src/Comp/Input/Input.hpp"
#include "../src/Comp/Output/Output.hpp"
#include "../src/Comp/True/True.hpp"

#include "../src/Comp/And/And.hpp"
#include "../src/Comp/Invert/Invert.hpp"
#include "../src/Comp/Logger/Logger.hpp"
#include "../src/Comp/O4001/O4001.hpp"
#include "../src/Comp/Or/Or.hpp"
#include "../src/Comp/Xor/Xor.hpp"

#include "../src/Tower/ControlTower.hpp"

#include "nts.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

static const int ERROR_VALUE = 84;
static const int END_VALUE = 0;

nts::ControlTower *parse(const char *file);
void execution(nts::ControlTower *tower);
void tokenize(
    std::string const &str, const char delim, std::vector<std::string> &out);
std::string remove_space(std::string str);

#endif
