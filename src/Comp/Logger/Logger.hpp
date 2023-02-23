/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-tekspice-ewen.briLogger
** File description:
** Logger
*/

#ifndef D041E0C5_7AAD_47A0_9A37_7A6E9F13058B23
#define D041E0C5_7AAD_47A0_9A37_7A6E9F13058B23

#include "../AComponent/AComponent.hpp"

namespace nts
{
    class Logger : virtual public nts::AComponent {
      public:
        Logger();

        void simulate() override;
    };
} // namespace nts

#endif /* AA67E95A_4FFE_4522_B822_46914B3E3FEA */
