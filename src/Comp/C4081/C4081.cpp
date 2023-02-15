/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-tekspice-ewen.briC4081
** File description:
** C4081
*/

#include "C4081.hpp"

// nts::Tristate nts::C4081::compute(std::size_t pin)
// {
//     // if (pin > _pins.size())
//     //     return nts::Undefined;
//     // auto it = _pins.begin();
//     // std::advance(it, (int) pin - 1);
//     // return *it->getState();
// }

nts::C4081::C4081()
{
    _returned = false;
    _type = nts::Type::o4081;
    for (int i = 0; i < 14; ++i)
        _pins[i + 0] = new nts::PIN();

    _pins[2]->setFunc(&nts::PIN::Andop);
    _pins[2]->setLink1(_pins[0]);
    _pins[2]->setLink2(_pins[1]);

    _pins[3]->setFunc(&nts::PIN::Andop);
    _pins[3]->setLink1(_pins[5]);
    _pins[3]->setLink2(_pins[4]);

    _pins[9]->setFunc(&nts::PIN::Andop);
    _pins[9]->setLink1(_pins[7]);
    _pins[9]->setLink2(_pins[8]);

    _pins[10]->setFunc(&nts::PIN::Andop);
    _pins[10]->setLink1(_pins[12]);
    _pins[10]->setLink2(_pins[11]);

    for (int i = 0; i < 15; i++)
        _deleting.push_back(i);
}

nts::C4081::~C4081()
{
    for (const auto &key : _deleting)
        if (key != -1 && _pins[key])
            delete _pins[key];
}

void nts::C4081::setLink(
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

void nts::C4081::simulate(std::size_t ticks)
{
    _pins[2]->setFunc(&nts::PIN::Andop);
    _pins[2]->setLink1(_pins[0]);
    _pins[2]->setLink2(_pins[1]);

    _pins[3]->setFunc(&nts::PIN::Andop);
    _pins[3]->setLink1(_pins[5]);
    _pins[3]->setLink2(_pins[4]);

    _pins[9]->setFunc(&nts::PIN::Andop);
    _pins[9]->setLink1(_pins[7]);
    _pins[9]->setLink2(_pins[8]);

    _pins[10]->setFunc(&nts::PIN::Andop);
    _pins[10]->setLink1(_pins[12]);
    _pins[10]->setLink2(_pins[11]);

    // std::cout << "HELLO " << _pins[0] << " " << _pins[1] << " ";
    _pins[2]->compute();
    _pins[3]->compute();
    _pins[9]->compute();
    _pins[10]->compute();
    // std::cout << _pins[2] << "\n";
}

std::unordered_map<int, nts::PIN *> nts::C4081::getList() const
{
    return _pins;
}
