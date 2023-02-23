/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-tekspice-ewen.briInvert
** File description:
** Invert
*/

#ifndef D041E0C5_7AAD_47A0_9A37_7A6E9F1305X
#define D041E0C5_7AAD_47A0_9A37_7A6E9F1305X

#include "../AComponent/AComponent.hpp"
namespace nts
{
    class Invert : virtual public nts::AComponent {
      public:
        Invert();

        void simulate() override;
    };
} // namespace nts

#endif /* D041E0C5_7AAD_47A0_9A37_7A6E9F13058B */
