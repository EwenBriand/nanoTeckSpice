/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-tekspice-ewen.briXor
** File description:
** Xor
*/

#include "Xor.hpp"

nts::Xor::Xor()
{
    _type = nts::Type::TXor;
    _pins[0] = new nts::PIN();
    _pins[1] = new nts::PIN();
    _pins[2] = new nts::PIN();
    _pins[2]->setFunc(&nts::PIN::Xorop);
    _pins[2]->setLink1(_pins[0]);
    _pins[2]->setLink2(_pins[1]);
    _deleting.push_back(0);
    _deleting.push_back(1);
    _deleting.push_back(2);
}

void nts::Xor::simulate(std::size_t ticks)
{
    _pins[2]->setLink1(_pins[0]);
    _pins[2]->setLink2(_pins[1]);
    _pins[2]->setFunc(&nts::PIN::Xorop);
    // std::cout << "HELLO " << _pins[0] << " " << _pins[1] << " ";
    _pins[2]->compute();
    // std::cout << _pins[2] << "\n";
}
