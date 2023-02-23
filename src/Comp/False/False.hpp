/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-tekspice-ewen.briFalse
** File description:
** False
*/

#ifndef CC0AAFBC_DF41_42E5_A927_E5266977860165
#define CC0AAFBC_DF41_42E5_A927_E5266977860165

#include "../AComponent/AComponent.hpp"

namespace nts
{
    class AFalse : virtual public nts::AComponent {
      public:
        AFalse(std::string name);
        ~AFalse();

        void simulate() override;
        void setLink(std::size_t pin, nts::IComponent &other,
            std::size_t otherPin) override;
    };
} // namespace nts

#endif /* CC0AAFBC_DF41_42E5_A927_E52669778601 */
