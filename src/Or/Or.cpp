/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-tekspice-ewen.briOr
** File description:
** Or
*/

#include "Or.hpp"

// nts::Tristate nts::Or::compute(std::size_t pin)
// {
//     // if (pin > _pins.size())
//     //     return nts::Undefined;
//     // auto it = _pins.begin();
//     // std::advance(it, (int) pin - 1);
//     // return *it->getState();
// }

nts::Or::Or()
{
    _pins[0] = new nts::PIN();
    _pins[1] = new nts::PIN();
    _pins[2] = new nts::PIN();
    _pins[0]->setType(nts::Type::input);
    _pins[1]->setType(nts::Type::input);
    _pins[2]->setType(nts::Type::output);
    _pins[2]->setFunc(&nts::PIN::Orop);
    _pins[2]->setLink1(_pins[0]);
    _pins[2]->setLink2(_pins[1]);
}

nts::Or::~Or()
{
    // for (size_t it = 0; it < _pins.size(); it++)
    //     if (_pins[it])
    //         delete _pins[it];
}

void nts::Or::setLink(
    std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    // pin == position de ton pin dans _pins
    // other == le componnent auquel tu veux le lier
    // otherPin == la position du pin dans other
    if (pin > _pins.size() || otherPin > other.getList().size())
        return;
    _pins[pin] = other.getList()[otherPin];
}

void nts::Or::simulate(std::size_t ticks)
{
    _pins[2]->setLink1(_pins[0]);
    _pins[2]->setLink2(_pins[1]);
    _pins[2]->setFunc(&nts::PIN::Orop);
    for (size_t it = 0; it < _pins.size(); it++)
        if (_pins[it]->getType() == nts::Type::clock)
            _pins[it]->setState((nts::Tristate)(ticks % 2));
    std::cout << "HELLO " << _pins[0] << " " << _pins[1] << " ";
    _pins[2]->compute();
    std::cout << _pins[2] << "\n";
}

std::unordered_map<int, nts::PIN *> nts::Or::getList() const
{
    return _pins;
}
