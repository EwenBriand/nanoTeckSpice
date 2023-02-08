/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-tekspice-ewen.briand
** File description:
** NotComponent
*/

#ifndef D06D30C1_67B1_4E81_8976_8DE733B14693
#define D06D30C1_67B1_4E81_8976_8DE733B14693

#include "nts.hpp"

namespace nts
{
    class PIN {
      private:
        nts::Tristate _state;
        std::string _name;
        nts::Type _type;

        nts::Tristate (nts::PIN::*_func)(nts::Tristate, nts::Tristate);
        nts::PIN *_link1;
        nts::PIN *_link2;

      public:
        PIN();
        ~PIN() = default;

        void setState(nts::Tristate state);
        void setName(std::string name);
        void setType(nts::Type type);
        void setFunc(
            nts::Tristate (nts::PIN::*func)(nts::Tristate, nts::Tristate));
        void setLink1(nts::PIN *links);
        void setLink2(nts::PIN *links);

        void compute();

        nts::Tristate getState() const;
        std::string getName() const;
        nts::Type getType() const;

        nts::Tristate Andop(nts::Tristate pin1, nts::Tristate pin2);
        nts::Tristate Orop(nts::Tristate pin1, nts::Tristate pin2);
        nts::Tristate Xorop(nts::Tristate pin1, nts::Tristate pin2);
        nts::Tristate Invertop(nts::Tristate pin1, nts::Tristate pin2);
    };
} // namespace nts

std::ostream &operator<<(std::ostream &os, const nts::PIN *pin);

#endif /* D06D30C1_67B1_4E81_8976_8DE733B14693 */
