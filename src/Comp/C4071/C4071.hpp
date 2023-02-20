/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-tekspice-ewen.briC4071
** File description:
** C4071
*/

#ifndef D041E0C5_7AAD_47A0_9A37_7A6E9F1305213865
#define D041E0C5_7AAD_47A0_9A37_7A6E9F1305213865

#include "../AComponent/AComponent.hpp"

namespace nts
{
    class C4071 : virtual public nts::AComponent {
      public:
        C4071();

        void simulate(std::size_t tick) override;
    };
} // namespace nts

#endif /* A65A9156_8F10_44C2_A7A0_484D77F59676 */
