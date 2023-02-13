/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-tekspice-ewen.briFalse
** File description:
** False
*/

#include "False.hpp"

// nts::Tristate nts::AFalse::compute(std::size_t pin)
// {
//     // if (pin > _pins.size())
//     //     return nts::Undefined;
//     // auto it = _pins.begin();
//     // std::advance(it, (int) pin - 1);
//     // return *it->getState();
// }

nts::AFalse::AFalse(std::string name)
{
    _type = nts::Type::F;
    _pins[0] = new nts::PIN();
    _pins[0]->setType(nts::Type::F);
    _pins[0]->setName(name);
    _pins[0]->setState(nts::Tristate::False);
}

nts::AFalse::~AFalse()
{
    for (size_t it = 0; it < _pins.size(); it++)
        if (_pins[it]) {
            delete _pins[it];
            _pins[it] = nullptr;
        }
}

void nts::AFalse::setLink(
    std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin > _pins.size() || otherPin > other.getList().size())
        return;
    other.setLink(otherPin, *this, pin);
    return;
}

void nts::AFalse::simulate(std::size_t ticks)
{
    std::cout << _pins[0] << std::endl;
}

std::unordered_map<int, nts::PIN *> nts::AFalse::getList() const
{
    return _pins;
}
