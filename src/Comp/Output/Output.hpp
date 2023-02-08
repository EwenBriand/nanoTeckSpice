/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-tekspice-ewen.briOutput
** File description:
** Output
*/

#ifndef CC0AAFBC_DF41_42E5_A927_E52669778602
#define CC0AAFBC_DF41_42E5_A927_E52669778602

#include <array>
#include "../PIN/PIN.hpp"
#include "nts.hpp"

namespace nts
{
    class Output : virtual public nts::IComponent {
      protected:
        std::unordered_map<int, nts::PIN *> _pins;

      public:
        Output(std::string name);
        ~Output();

        void simulate(std::size_t tick) override;
        void setLink(std::size_t pin, nts::IComponent &other,
            std::size_t otherPin) override;

        std::unordered_map<int, nts::PIN *> getList() const override;
    };
} // namespace nts

#endif /* CC0AAFBC_DF41_42E5_A927_E52669778601 */
