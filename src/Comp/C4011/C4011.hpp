/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-tekspice-ewen.briC4011
** File description:
** C4011
*/

#ifndef D041E0C5_7AAD_47A0_9A37_7A6E9F130521312
#define D041E0C5_7AAD_47A0_9A37_7A6E9F130521312

#include "../AComponent/AComponent.hpp"

namespace nts
{
    class C4011 : virtual public nts::AComponent {
      public:
        C4011();

        void simulate() override;
    };
} // namespace nts

#endif /* A65A9156_8F10_44C2_A7A0_484D77F59676 */
