/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-tekspice-ewen.briInput
** File description:
** input
*/

#ifndef CC0AAFBC_DF41_42E5_A927_E52669778601
#define CC0AAFBC_DF41_42E5_A927_E52669778601

#include <array>
#include "../PIN/PIN.hpp"
#include "nts.hpp"

namespace nts
{
    class Input : virtual public nts::IComponent {
      protected:
        std::unordered_map<int, nts::PIN *> _pins;

      public:
        Input(std::string name);
        ~Input();

        void simulate(std::size_t tick) override;
        void setLink(std::size_t pin, nts::IComponent &other,
            std::size_t otherPin) override;

        std::unordered_map<int, nts::PIN *> getList() const override;
    };
} // namespace nts

#endif /* CC0AAFBC_DF41_42E5_A927_E52669778601 */