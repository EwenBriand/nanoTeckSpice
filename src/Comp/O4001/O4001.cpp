/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-tekspice-ewen.briO4001
** File description:
** O4001
*/

#include "O4001.hpp"

nts::O4001::O4001()
{
    _type = nts::Type::o4001;
    for (int i = 0; i < 14; ++i)
        _pins[i + 0] = new nts::PIN();

    _pins[2]->setFunc(&nts::PIN::NOrop);
    _pins[2]->setLink1(_pins[0]);
    _pins[2]->setLink2(_pins[1]);

    _pins[3]->setFunc(&nts::PIN::NOrop);
    _pins[3]->setLink1(_pins[5]);
    _pins[3]->setLink2(_pins[4]);

    _pins[9]->setFunc(&nts::PIN::NOrop);
    _pins[9]->setLink1(_pins[7]);
    _pins[9]->setLink2(_pins[8]);

    _pins[10]->setFunc(&nts::PIN::NOrop);
    _pins[10]->setLink1(_pins[12]);
    _pins[10]->setLink2(_pins[11]);

    for (int i = 0; i < 15; i++)
        _deleting.push_back(i);
}

void nts::O4001::simulate()
{
    _pins[2]->setFunc(&nts::PIN::NOrop);
    _pins[2]->setLink1(_pins[0]);
    _pins[2]->setLink2(_pins[1]);

    _pins[3]->setFunc(&nts::PIN::NOrop);
    _pins[3]->setLink1(_pins[5]);
    _pins[3]->setLink2(_pins[4]);

    _pins[9]->setFunc(&nts::PIN::NOrop);
    _pins[9]->setLink1(_pins[7]);
    _pins[9]->setLink2(_pins[8]);

    _pins[10]->setFunc(&nts::PIN::NOrop);
    _pins[10]->setLink1(_pins[12]);
    _pins[10]->setLink2(_pins[11]);

    // std::cout << "HELLO " << _pins[0] << " " << _pins[1] << " ";
    _pins[2]->compute();
    _pins[3]->compute();
    _pins[9]->compute();
    _pins[10]->compute();
    // std::cout << _pins[2] << "\n";
}
