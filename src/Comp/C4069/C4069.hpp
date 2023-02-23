/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-tekspice-ewen.briC4069
** File description:
** C4069
*/

#ifndef D041E0C5_7AAD_47A0_9A37_7A6E9F1305213121321231
#define D041E0C5_7AAD_47A0_9A37_7A6E9F1305213121321231

#include "../AComponent/AComponent.hpp"

namespace nts
{
    class C4069 : virtual public nts::AComponent {
      public:
        C4069();

        void simulate() override;
        void setLink(std::size_t pin, nts::IComponent &other,
            std::size_t otherPin) override;
    };
} // namespace nts

#endif /* A65A9156_8F10_44C2_A7A0_484D77F59676 */
