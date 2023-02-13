/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-tekspice-ewen.briO4001
** File description:
** O4001
*/

#include "O4001.hpp"

// nts::Tristate nts::O4001::compute(std::size_t pin)
// {
//     // if (pin > _pins.size())
//     //     return nts::Undefined;
//     // auto it = _pins.begin();
//     // std::advance(it, (int) pin - 1);
//     // return *it->getState();
// }

nts::O4001::O4001()
{
    _type = nts::Type::o4001;
    for (int i = 0; i < 14;) {
        if (i == 7)
            i++;
        else {
            _pins[i + 0] = new nts::PIN();
            _pins[i + 1] = new nts::PIN();
            _pins[i + 2] = new nts::PIN();
            i += 3;
        }
    }

    _pins[2]->setFunc(&nts::PIN::Orop);
    _pins[2]->setLink1(_pins[0]);
    _pins[2]->setLink2(_pins[1]);

    _pins[4]->setFunc(&nts::PIN::Orop);
    _pins[4]->setLink1(_pins[5]);
    _pins[4]->setLink2(_pins[6]);

    _pins[10]->setFunc(&nts::PIN::Orop);
    _pins[10]->setLink1(_pins[9]);
    _pins[10]->setLink2(_pins[8]);

    _pins[11]->setFunc(&nts::PIN::Orop);
    _pins[11]->setLink1(_pins[12]);
    _pins[11]->setLink2(_pins[13]);

    for (int i = 0; i < 15; i++)
        _deleting.push_back(i);
}

nts::O4001::~O4001()
{
    for (const auto &key : _deleting)
        if (key != -1 && _pins[key])
            delete _pins[key];
}

void nts::O4001::setLink(
    std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    // pin == position de ton pin dans _pins
    // other == le componnent auquel tu veux le lier
    // otherPin == la position du pin dans other
    if (pin > _pins.size() || otherPin > other.getList().size())
        return;
    if (_pins[pin]->getType() == nts::New) {
        delete _pins[pin];
        _deleting[pin] = -1;
        _pins[pin] = other.getList()[otherPin];
    } else
        other.setLink(otherPin, *this, pin);
}

void nts::O4001::simulate(std::size_t ticks)
{
    _pins[2]->setFunc(&nts::PIN::Orop);
    _pins[2]->setLink1(_pins[0]);
    _pins[2]->setLink2(_pins[1]);

    _pins[4]->setFunc(&nts::PIN::Orop);
    _pins[4]->setLink1(_pins[5]);
    _pins[4]->setLink2(_pins[6]);

    _pins[10]->setFunc(&nts::PIN::Orop);
    _pins[10]->setLink1(_pins[9]);
    _pins[10]->setLink2(_pins[8]);

    _pins[11]->setFunc(&nts::PIN::Orop);
    _pins[11]->setLink1(_pins[12]);
    _pins[11]->setLink2(_pins[13]);

    for (size_t it = 0; it < _pins.size(); it++)
        if (_pins[it]->getType() == nts::Type::clock)
            _pins[it]->setState((nts::Tristate)(ticks % 2));
    // std::cout << "HELLO " << _pins[0] << " " << _pins[1] << " ";
    _pins[2]->compute();
    // std::cout << _pins[2] << "\n";
}

std::unordered_map<int, nts::PIN *> nts::O4001::getList() const
{
    return _pins;
}
