/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-tekspice-ewen.briand
** File description:
** execution
*/

#include "my.hpp"
#include "nts.hpp"

#include <csignal>
#include <iostream>
#include <signal.h>
#include <sstream>
#include <string>

// creat simulate for clock, it change the value of the input

void simulation(int clock, nts::ControlTower *tower)
{
    auto elem = tower->getCircuit();
    for (auto it : elem) {
        if (it.second->getType() != nts::Type::input
            && it.second->getType() != nts::Type::output
            && it.second->getType() != nts::Type::T
            && it.second->getType() != nts::Type::F)
            it.second->simulate(clock);
    }
}

void display(nts::ControlTower *tower, int clock)
{
    std::cout << "tick: " << clock << std::endl;
    std::cout << "input(s):" << std::endl;
    auto circuit = tower->getCircuit();
    auto n = tower->getName();
    for (auto name = 0; name < n.size(); ++name) {
        auto elem = circuit[n[name]];
        if (elem->getType() == nts::Type::input) {
            std::cout << "  " << n[name] << ": ";
            elem->simulate(clock);
        } else if (elem->getType() == nts::Type::clock) {
            std::cout << "  " << n[name] << ": ";
            elem->print();
        }
    }
    std::cout << "output(s):" << std::endl;
    for (auto name = 0; name < n.size(); ++name) {
        auto elem = circuit[n[name]];
        if (elem->getType() == nts::Type::output) {
            std::cout << "  " << n[name] << ": ";
            elem->simulate(1);
        }
    }
}

void check_value(std::string &line, nts::ControlTower *tower)
{
    nts::IComponent *elem = nullptr;
    std::string name;
    std::string value;
    std::vector<std::string> out;

    split_string(line, '=', out);
    if (out.size() == 2) {
        name = remove_space(out[0]);
        value = remove_space(out[1]);
    }

    elem = tower->getElement(name);

    if (value == "1" && elem != nullptr && elem->getType() == nts::Type::input)
        elem->getList()[0]->setState(nts::Tristate::True);
    else if (value == "U" && elem != nullptr
        && elem->getType() == nts::Type::input)
        elem->getList()[0]->setState(nts::Tristate::Undefined);
    else if (value == "0" && elem != nullptr
        && elem->getType() == nts::Type::input)
        elem->getList()[0]->setState(nts::Tristate::False);
}

static bool loopHandle;

void ctrl_c_handler(int signal_number)
{
    loopHandle = false;
}

int loop(int clock, nts::ControlTower *tower, sighandler_t buffer)
{
    loopHandle = true;
    buffer = std::signal(SIGINT, ctrl_c_handler);
    while (loopHandle) {
        ++clock;
        simulation(clock, tower);
        display(tower, clock);
    }
    signal(SIGINT, buffer);
    return clock;
}

void execution(nts::ControlTower *tower)
{
    std::string line;
    int clock = 0;
    sighandler_t buffer = std::signal(SIGINT, ctrl_c_handler);

    std::cout << "> ";
    while (std::getline(std::cin, line)) {
        if (line == "exit")
            break;
        if (line == "simulate") {
            ++clock;
            simulation(clock, tower);
        } else if (line == "display")
            display(tower, clock);
        else if (line == "loop")
            loop(clock, tower, buffer);
        else
            check_value(line, tower);
        std::cout << "> ";
    }
}
