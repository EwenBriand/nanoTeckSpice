/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-tekspice-ewen.briOutput
** File description:
** Output
*/

#include "Output.hpp"

nts::Output::Output(std::string name)
{
    _type = nts::Type::output;
    _set = false;
    _pins[0] = new nts::PIN();
    _pins[0]->setType(nts::Type::output);
    _pins[0]->setName(name);
}

nts::Output::~Output()
{
    for (size_t it = 0; it < _pins.size(); it++)
        if (_pins[it]->getType() == nts::Type::output) {
            delete _pins[0];
            _pins[0] = nullptr;
        }
}

void nts::Output::setLink(
    std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin > _pins.size() || otherPin > other.getList().size() || _set)
        return;

    std::string name = _pins[pin]->getName();
    delete _pins[pin];
    _pins[pin] = other.getList()[otherPin];
    _pins[0]->setName(name);
    _set = true;
}

void nts::Output::simulate()
{
    std::cout << _pins[0] << std::endl;
}
