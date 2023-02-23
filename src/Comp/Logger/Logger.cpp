/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-tekspice-ewen.briLogger
** File description:
** Logger
*/

#include "Logger.hpp"
#include <fstream>
#include <iostream>

nts::Logger::Logger()
{
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
    _pins[9] = new nts::PIN();
    for (int i = 0; i < 10; i++)
        _deleting.push_back(i);
}

void nts::Logger::simulate()
{
    // std::cout << _pins[9] << "  " << _pins[8] << std::endl;
    if (_pins[9]->getState() != nts::False
        || _pins[8]->getState() != nts::True)
        return;
    std::string my_char;
    for (int i = 7; i >= 0; --i)
        if (_pins[i]->getState() != nts::Undefined)
            my_char += (_pins[i]->getState() == nts::True) ? "1" : "0";
        else
            return;

    // std::cout << my_char << std::endl;
    int ch = std::stoi(my_char, 0, 2);
    std::cout << ch << std::endl;
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
