/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-tekspice-ewen.briOr
** File description:
** Or
*/

#include "Or.hpp"

nts::Or::Or()
{
    _type = nts::Type::TOr;
    _pins[0] = new nts::PIN();
    _pins[1] = new nts::PIN();
    _pins[2] = new nts::PIN();
    _pins[2]->setFunc(&nts::PIN::Orop);
    _pins[2]->setLink1(_pins[0]);
    _pins[2]->setLink2(_pins[1]);
    _deleting.push_back(0);
    _deleting.push_back(1);
    _deleting.push_back(2);
}

void nts::Or::simulate(std::size_t ticks)
{
    _pins[2]->setLink1(_pins[0]);
    _pins[2]->setLink2(_pins[1]);
    _pins[2]->setFunc(&nts::PIN::Orop);
    // std::cout << "HELLO " << _pins[0] << " " << _pins[1] << " ";
    _pins[2]->compute();
    // std::cout << _pins[2] << "\n";
}
