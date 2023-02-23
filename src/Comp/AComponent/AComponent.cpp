/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-tekspice-ewen.briAComponent
** File description:
** AComponent
*/

#include "AComponent.hpp"

nts::AComponent::AComponent()
{
    _returned = false;
}

nts::AComponent::~AComponent()
{
    for (const auto &key : _deleting)
        if (key != -1 && _pins[key])
            delete _pins[key];
}

void nts::AComponent::setLink(
    std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    // pin == position de ton pin dans _pins
    // other == le componnent auquel tu veux le lier
    // otherPin == la position du pin dans other
    if (pin > _pins.size() || otherPin > other.getList().size())
        return;

    if (_pins[pin]->getType() == nts::New) {
        _returned = false;
        delete _pins[pin];
        _deleting[pin] = -1;
        _pins[pin] = other.getList()[otherPin];
    } else if (_returned == true) {
        _pins[pin] = other.getList()[otherPin];
        _returned = false;
    } else {
        _returned = true;
        other.setLink(otherPin, *this, pin);
    }
}

std::unordered_map<int, nts::PIN *> nts::AComponent::getList() const
{
    return _pins;
}

int nts::AComponent::getNbPins() const
{
    return _pins.size();
}

nts::Type nts::AComponent::getType()
{
    return _type;
}

void nts::AComponent::print()
{
    return;
}

void nts::AComponent::simulate(std::size_t tick)
{
    tick += 0;
    return;
}

void nts::AComponent::simulate()
{
    return;
}
