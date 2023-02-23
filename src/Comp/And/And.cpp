/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-tekspice-ewen.briand
** File description:
** And
*/

#include "And.hpp"

nts::And::And()
{
    _type = nts::Type::TAnd;
    _pins[0] = new nts::PIN();
    _pins[1] = new nts::PIN();
    _pins[2] = new nts::PIN();
    _pins[2]->setFunc(&nts::PIN::Andop);
    _pins[2]->setLink1(_pins[0]);
    _pins[2]->setLink2(_pins[1]);
    _deleting.push_back(0);
    _deleting.push_back(1);
    _deleting.push_back(2);
}

void nts::And::simulate()
{
    _pins[2]->setLink1(_pins[0]);
    _pins[2]->setLink2(_pins[1]);
    _pins[2]->setFunc(&nts::PIN::Andop);
    _pins[2]->compute();
}
