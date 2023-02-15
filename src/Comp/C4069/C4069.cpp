/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-tekspice-ewen.briC4069
** File description:
** C4069
*/

#include "C4069.hpp"

// nts::Tristate nts::C4069::compute(std::size_t pin)
// {
//     // if (pin > _pins.size())
//     //     return nts::Undefined;
//     // auto it = _pins.begin();
//     // std::advance(it, (int) pin - 1);
//     // return *it->getState();
// }

nts::C4069::C4069()
{
    _returned = false;
    _type = nts::Type::o4069;
    for (int i = 0; i < 14; i++)
        _pins[i] = new nts::PIN();

    _pins[1]->setFunc(&nts::PIN::Invertop);
    _pins[1]->setLink1(_pins[0]);

    _pins[3]->setFunc(&nts::PIN::Invertop);
    _pins[3]->setLink1(_pins[2]);

    _pins[5]->setFunc(&nts::PIN::Invertop);
    _pins[5]->setLink1(_pins[4]);

    _pins[7]->setFunc(&nts::PIN::Invertop);
    _pins[7]->setLink1(_pins[8]);

    _pins[9]->setFunc(&nts::PIN::Invertop);
    _pins[9]->setLink1(_pins[10]);

    _pins[11]->setFunc(&nts::PIN::Invertop);
    _pins[11]->setLink1(_pins[12]);

    for (int i = 0; i < 15; i++)
        _deleting.push_back(i);
}

nts::C4069::~C4069()
{
    for (const auto &key : _deleting)
        if (key != -1 && _pins[key])
            delete _pins[key];
}

void nts::C4069::setLink(
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

void nts::C4069::simulate(std::size_t ticks)
{
    _pins[1]->setFunc(&nts::PIN::Invertop);
    _pins[1]->setLink1(_pins[0]);

    _pins[3]->setFunc(&nts::PIN::Invertop);
    _pins[3]->setLink1(_pins[2]);

    _pins[5]->setFunc(&nts::PIN::Invertop);
    _pins[5]->setLink1(_pins[4]);

    _pins[7]->setFunc(&nts::PIN::Invertop);
    _pins[7]->setLink1(_pins[8]);

    _pins[9]->setFunc(&nts::PIN::Invertop);
    _pins[9]->setLink1(_pins[10]);

    _pins[11]->setFunc(&nts::PIN::Invertop);
    _pins[11]->setLink1(_pins[12]);

    // std::cout << "HELLO " << _pins[0] << " " << _pins[1] << " ";
    _pins[1]->compute();
    _pins[3]->compute();
    _pins[5]->compute();
    _pins[7]->compute();
    _pins[9]->compute();
    _pins[11]->compute();
    // std::cout << _pins[2] << "\n";
}

std::unordered_map<int, nts::PIN *> nts::C4069::getList() const
{
    return _pins;
}
