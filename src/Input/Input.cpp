/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-tekspice-ewen.briInput
** File description:
** Input
*/

#include "Input.hpp"

// nts::Tristate nts::Input::compute(std::size_t pin)
// {
//     // if (pin > _pins.size())
//     //     return nts::Undefined;
//     // auto it = _pins.begin();
//     // std::advance(it, (int) pin - 1);
//     // return *it->getState();
// }

nts::Input::Input(std::string name)
{
    _pins[0] = new nts::PIN();
    _pins[0]->setType(nts::Type::input);
    _pins[0]->setName(name);
}

nts::Input::~Input()
{
    for (size_t it = 0; it < _pins.size(); it++)
        if (_pins[it]) {
            delete _pins[it];
        }
}

void nts::Input::setLink(
    std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin > _pins.size() || otherPin > other.getList().size())
        return;
    return;
}

void nts::Input::simulate(std::size_t ticks)
{
    std::cout << _pins[0] << std::endl;
}

std::unordered_map<int, nts::PIN *> nts::Input::getList() const
{
    return _pins;
}
