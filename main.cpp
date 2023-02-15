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
    if (env[0] == NULL)
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
    // nts::Output out("output");
    // nts::Output out2("output2");
    // nts::Input input(std::string("input1"));
    // nts::Input input3(std::string("input3"));
    // nts::Input input2(std::string("input2"));
    // nts::Output out3("output3");
    // nts::And and_m;
    // nts::Xor or_m;
    // nts::Invert inv;

    // input.setLink(0, and_m, 0);
    // and_m.setLink(1, input2, 0);
    // and_m.setLink(2, out, 0);

    // input.getList()[0]->setState(nts::Tristate::False);
    // input2.getList()[0]->setState(nts::Tristate::Undefined);
    // and_m.simulate(1);
    // input.simulate(1);
    // input2.simulate(1);
    // out.simulate(1);
    // out2.simulate(1);

    // or_m.setLink(0, input, 0);
    // or_m.setLink(1, input2, 0);
    // or_m.setLink(2, out2, 0);

    // input3.setLink(0, out3, 0);

    // input.getList()[0]->setState(nts::Tristate::False);
    // input3.getList()[0]->setState(nts::Tristate::False);
    // input2.getList()[0]->setState(nts::Tristate::True);

    // or_m.simulate(1);
    // or_m.simulate(1);
    // or_m.simulate(1);
    // or_m.simulate(1);
    // or_m.simulate(1);
    // input.simulate(1);
    // input2.simulate(1);
    // out2.simulate(1);

    // or_m.setLink(2, inv, 0);
    // inv.setLink(1, out2, 0);

    // inv.simulate(1);
    // out2.simulate(1);
    // out3.simulate(1);

    return END_VALUE;
}

// créée les input en tout premier lors du scraping
