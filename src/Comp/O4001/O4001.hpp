/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-tekspice-ewen.briO4001
** File description:
** O4001
*/

#ifndef D041E0C5_7AAD_47A0_9A37_7A6E9F1305213
#define D041E0C5_7AAD_47A0_9A37_7A6E9F1305213

#include "../AComponent/AComponent.hpp"

namespace nts
{
    class O4001 : virtual public nts::AComponent {
      public:
        O4001();

        void simulate(std::size_t tick) override;
    };
} // namespace nts

#endif /* A65A9156_8F10_44C2_A7A0_484D77F59676 */
