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

nts::Or::~Or()
{
    for (const auto &key : _deleting)
        if (key != -1 && _pins[key])
            delete _pins[key];
}

void nts::Or::setLink(
    std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    // pin == position de ton pin dans _pins
    // other == le componnent auquel tu veux le lier
    // otherPin == la position du pin dans other
    if (pin > _pins.size() || otherPin > other.getList().size())
        return;
    if (_pins[pin]->getType() == nts::New) {
        delete _pins[pin];
        _deleting[pin] = -1;
        _pins[pin] = other.getList()[otherPin];
    } else
        other.setLink(otherPin, *this, pin);
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
