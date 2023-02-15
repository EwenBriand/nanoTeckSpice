/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-tekspice-ewen.briLogger
** File description:
** Logger
*/

#include "Logger.hpp"
#include <fstream>
#include <iostream>

// nts::Tristate nts::Logger::compute(std::size_t pin)
// {
//     // if (pin > _pins.size())
//     //     return nts::Undefined;
//     // auto it = _pins.begin();
//     // std::advance(it, (int) pin - 1);
//     // return *it->getState();
// }

nts::Logger::Logger()
{
    _returned = false;
    _type = nts::Type::logger;
    _pins[0] = new nts::PIN();
    _pins[1] = new nts::PIN();
    _pins[2] = new nts::PIN();
    _pins[3] = new nts::PIN();
    _pins[4] = new nts::PIN();
    _pins[5] = new nts::PIN();
    _pins[6] = new nts::PIN();
    _pins[7] = new nts::PIN();
    _pins[8] = new nts::PIN();
    _pins[8] = new nts::PIN();
    _pins[9] = new nts::PIN();
    for (int i = 0; i < 10; i++)
        _deleting.push_back(i);
}

nts::Logger::~Logger()
{
    for (const auto &key : _deleting)
        if (key != -1 && _pins[key])
            delete _pins[key];
}

void nts::Logger::setLink(
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

void nts::Logger::simulate(std::size_t ticks)
{
    std::cout << _pins[9] << "  " << _pins[8] << std::endl;
    if (_pins[9]->getState() != nts::False
        || _pins[8]->getState() != nts::True)
        return;
    std::string my_char;
    for (int i = 0; i < 8; i++)
        if (_pins[i]->getState() != nts::Undefined)
            my_char += (_pins[i]->getState() == nts::True) ? "1" : "0";
        else
            return;

    int ch = std::stoi(my_char, 0, 2);
    // std::cout << ch << std::endl;
    std::ofstream MyFile;
    MyFile.open("log.bin", std::ios::app);
    if (MyFile.is_open()) {
        MyFile << (char) ch;
        MyFile.close();
    } else {
        // std::cout << "Unable to open file";
        return;
    }
}

std::unordered_map<int, nts::PIN *> nts::Logger::getList() const
{
    return _pins;
}
