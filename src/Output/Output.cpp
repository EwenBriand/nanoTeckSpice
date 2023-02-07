/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-tekspice-ewen.briOutput
** File description:
** Output
*/

#include "Output.hpp"

// nts::Tristate nts::Output::compute(std::size_t pin)
// {
//     // if (pin > _pins.size())
//     //     return nts::Undefined;
//     // auto it = _pins.begin();
//     // std::advance(it, (int) pin - 1);
//     // return *it->getState();
// }

nts::Output::Output(std::string name)
{
    _pins[0] = new nts::PIN();
    _pins[0]->setType(nts::Type::output);
    _pins[0]->setName(name);
}

nts::Output::~Output()
{
    for (size_t it = 0; it < _pins.size(); it++)
        if (_pins[it])
            delete _pins[0];
}

void nts::Output::setLink(
    std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin > _pins.size() || otherPin > other.getList().size())
        return;

    std::string name = _pins[pin]->getName();
    _pins[pin] = other.getList()[otherPin];
    _pins[0]->setName(name);
}

void nts::Output::simulate(std::size_t ticks)
{
    std::cout << _pins[0] << std::endl;
    // std::cout << (*_pins[0]) << std::endl;
}

std::unordered_map<int, nts::PIN *> nts::Output::getList() const
{
    return _pins;
}
