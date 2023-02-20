/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-tekspice-ewen.briInvert
** File description:
** Invert
*/

#include "Invert.hpp"

nts::Invert::Invert()
{
    _type = nts::Type::TNot;
    _pins[0] = new nts::PIN();
    _pins[1] = new nts::PIN();
    _pins[1]->setFunc(&nts::PIN::Invertop);
    _pins[1]->setLink1(_pins[0]);
    _deleting.push_back(0);
    _deleting.push_back(1);
}

void nts::Invert::simulate(std::size_t ticks)
{
    // std::cout << "HELLO " << _pins[0] << " ";
    _pins[1]->setLink1(_pins[0]);
    _pins[1]->setFunc(&nts::PIN::Invertop);
    for (size_t it = 0; it < _pins.size(); it++)
        if (_pins[it]->getType() == nts::Type::clock)
            _pins[it]->setState((nts::Tristate)(ticks % 2));
    _pins[1]->compute();
    // std::cout << _pins[1] << "\n";
}
