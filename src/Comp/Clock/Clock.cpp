/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-tekspice-ewen.briClock
** File description:
** Clock
*/

#include "Clock.hpp"

// nts::Tristate nts::Clock::compute(std::size_t pin)
// {
//     // if (pin > _pins.size())
//     //     return nts::Undefined;
//     // auto it = _pins.begin();
//     // std::advance(it, (int) pin - 1);
//     // return *it->getState();
// }

nts::Clock::Clock(std::string name)
{
    _type = nts::Type::clock;
    _pins[0] = new nts::PIN();
    _pins[0]->setType(nts::Type::clock);
    _pins[0]->setName(name);
}

nts::Clock::~Clock()
{
    for (size_t it = 0; it < _pins.size(); it++)
        if (_pins[it]) {
            delete _pins[it];
            _pins[it] = nullptr;
        }
}

void nts::Clock::setLink(
    std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin > _pins.size() || otherPin > other.getList().size())
        return;
    other.setLink(otherPin, *this, pin);
    return;
}

void nts::Clock::simulate(std::size_t ticks)
{
    if (ticks == 0)
        return;
    else if (ticks % 2 == 0)
        _pins[0]->setState(nts::Tristate::True);
    else
        _pins[0]->setState(nts::Tristate::False);
}

void nts::Clock::print()
{
    std::cout << _pins[0] << std::endl;
}

std::unordered_map<int, nts::PIN *> nts::Clock::getList() const
{
    return _pins;
}
