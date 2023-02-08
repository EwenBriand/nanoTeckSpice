/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-tekspice-ewen.briand
** File description:
** PIN
*/

#include "PIN.hpp"

nts::PIN::PIN() : _state(nts::Undefined), _name(""), _type(nts::New)
{
    _link1 = nullptr;
    _link2 = nullptr;
    _func = nullptr;
}

void nts::PIN::setState(nts::Tristate state)
{
    _state = state;
}

void nts::PIN::setName(std::string name)
{
    _name = name;
}

void nts::PIN::setType(nts::Type type)
{
    _type = type;
}

void nts::PIN::setFunc(
    nts::Tristate (nts::PIN::*func)(nts::Tristate, nts::Tristate))
{
    _func = func;
}

void nts::PIN::setLink1(nts::PIN *links)
{
    _link1 = links;
}

void nts::PIN::setLink2(nts::PIN *links)
{
    _link2 = links;
}

nts::Tristate nts::PIN::getState() const
{
    return _state;
}

std::string nts::PIN::getName() const
{
    return _name;
}

nts::Type nts::PIN::getType() const
{
    return _type;
}

void nts::PIN::compute()
{
    if (_link1 == nullptr)
        return;
    if (_link2 == nullptr)
        return setState((this->*_func)(_link1->_state, nts::Undefined));
    setState((this->*_func)(_link1->_state, _link2->_state));
}

std::ostream &operator<<(std::ostream &os, const nts::PIN *pin)
{
    if (pin->getState() == nts::Tristate::Undefined)
        return os << pin->getName() << ": U";
    return os << pin->getName() << ": " << pin->getState();
}

nts::Tristate nts::PIN::Andop(nts::Tristate pin1, nts::Tristate pin2)
{
    std::cout << pin1 << " " << pin2 << std::endl;
    if (pin1 == 0 || pin2 == 0)
        return nts::False;
    else if (pin1 == nts::True && pin2 == nts::True)
        return nts::True;
    else
        return nts::Undefined;
}

nts::Tristate nts::PIN::Orop(nts::Tristate pin1, nts::Tristate pin2)
{
    if (pin1 == 0)
        return pin2;
    if (pin2 == 1)
        return nts::True;
    else if (pin1 == 1)
        return nts::True;
    return nts::Undefined;
}

nts::Tristate nts::PIN::Xorop(nts::Tristate pin1, nts::Tristate pin2)
{
    if (pin1 == 0)
        return pin2;
    else if (pin1 == nts::Undefined || pin2 == nts::Undefined)
        return nts::Undefined;
    else if (pin2 == 0)
        return nts::True;
    return nts::False;
}

nts::Tristate nts::PIN::Invertop(nts::Tristate pin1, nts::Tristate pin2)
{
    if (nts::Undefined == pin1)
        return nts::Undefined;
    else if (pin1 == nts::True)
        return nts::False;
    return nts::True;
}
