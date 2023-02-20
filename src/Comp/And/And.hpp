/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-tekspice-ewen.briand
** File description:
** And
*/

#ifndef D041E0C5_7AAD_47A0_9A37_7A6E9F13058B
#define D041E0C5_7AAD_47A0_9A37_7A6E9F13058B

#include "../AComponent/AComponent.hpp"

namespace nts
{
    class And : virtual public nts::AComponent {
      public:
        And();

        void simulate(std::size_t tick) override;
    };
} // namespace nts

#endif /* D041E0C5_7AAD_47A0_9A37_7A6E9F13058B */
