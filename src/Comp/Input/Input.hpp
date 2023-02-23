/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-tekspice-ewen.briInput
** File description:
** input
*/

#ifndef CC0AAFBC_DF41_42E5_A927_E52669778601
#define CC0AAFBC_DF41_42E5_A927_E52669778601

#include "../AComponent/AComponent.hpp"

namespace nts
{
    class Input : virtual public nts::AComponent {
      public:
        Input(std::string name);
        ~Input();

        void simulate() override;
        void setLink(std::size_t pin, nts::IComponent &other,
            std::size_t otherPin) override;
        void print() override;
    };
} // namespace nts

#endif /* CC0AAFBC_DF41_42E5_A927_E52669778601 */
