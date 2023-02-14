/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-tekspice-ewen.briand
** File description:
** nts
*/

#ifndef A1F652E5_DEA3_407B_B0ED_02343818795
#define A1F652E5_DEA3_407B_B0ED_02343818795

#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

namespace nts
{
    enum Tristate { Undefined = (-true), True = true, False = false };
    enum Type {
        New,
        input,
        clock,
        T,
        F,
        output,
        TAnd,
        TOr,
        TXor,
        TNot,
        logger,
        o4001,
        o4011,
        o4030,
        o4069,
        o4071,
        o4081
    };

    class PIN;

    class IComponent {
      protected:
        nts::Type _type;

      public:
        // virtual nts::Tristate compute(std::size_t pin) = 0;
        virtual ~IComponent() = default;
        virtual void simulate(std::size_t tick) = 0;
        virtual void setLink(
            std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
        virtual std::unordered_map<int, nts::PIN *> getList() const = 0;
        virtual nts::Type getType()
        {
            return _type;
        };
    };

    class And;
    class Or;
    class Xor;
    class Invert;
    class Input;
    class Output;
    class Clock;
    class ATrue;
    class AFalse;
    class Logger;
    class O4001;
    class C4011;
    class C4030;
    class C4069;

    class ControlTower;
} // namespace nts

#endif /* A1F652E5_DEA3_407B_B0ED_02343818795A */
