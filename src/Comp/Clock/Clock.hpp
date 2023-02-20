/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-tekspice-ewen.briClock
** File description:
** Clock
*/

#ifndef CC0AAFBC_DF41_42E5_A927_E5266977860212
#define CC0AAFBC_DF41_42E5_A927_E5266977860212

#include "../AComponent/AComponent.hpp"

namespace nts
{
    class Clock : virtual public nts::AComponent {
      public:
        Clock(std::string name);
        ~Clock();

        void simulate(std::size_t tick) override;
        void setLink(std::size_t pin, nts::IComponent &other,
            std::size_t otherPin) override;
        void print() override;
    };
} // namespace nts

#endif /* CC0AAFBC_DF41_42E5_A927_E52669778601 */
