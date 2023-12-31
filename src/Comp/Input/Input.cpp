/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-tekspice-ewen.briInput
** File description:
** Input
*/

#include "Input.hpp"

nts::Input::Input(std::string name)
{
    _type = nts::Type::input;
    _pins[0] = new nts::PIN();
    _pins[0]->setType(nts::Type::input);
    _pins[0]->setName(name);
}

nts::Input::~Input()
{
    for (size_t it = 0; it < _pins.size(); it++)
        if (_pins[it]) {
            delete _pins[it];
            _pins[it] = nullptr;
        }
}

void nts::Input::setLink(
    std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin > _pins.size() || otherPin > other.getList().size())
        return;
    other.setLink(otherPin, *this, pin);
    return;
}

void nts::Input::simulate()
{
    if (_newVal) {
        _pins[0]->setState(_new);
        _newVal = false;
    }
}

void nts::Input::print()
{
    std::cout << _pins[0] << std::endl;
}
