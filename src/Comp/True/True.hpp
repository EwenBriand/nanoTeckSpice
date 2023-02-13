/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-tekspice-ewen.briTrue
** File description:
** True
*/

#ifndef CC0AAFBC_DF41_42E5_A927_E5266977860145
#define CC0AAFBC_DF41_42E5_A927_E5266977860145

#include <array>
#include "../PIN/PIN.hpp"
#include "nts.hpp"

namespace nts
{
    class ATrue : virtual public nts::IComponent {
      protected:
        std::unordered_map<int, nts::PIN *> _pins;

      public:
        ATrue(std::string name);
        ~ATrue();

        void simulate(std::size_t tick) override;
        void setLink(std::size_t pin, nts::IComponent &other,
            std::size_t otherPin) override;

        std::unordered_map<int, nts::PIN *> getList() const override;
    };
} // namespace nts

#endif /* CC0AAFBC_DF41_42E5_A927_E52669778601 */
