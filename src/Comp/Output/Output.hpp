/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-tekspice-ewen.briOutput
** File description:
** Output
*/

#ifndef CC0AAFBC_DF41_42E5_A927_E52669778602
#define CC0AAFBC_DF41_42E5_A927_E52669778602

#include "../AComponent/AComponent.hpp"

namespace nts
{
    class Output : virtual public nts::AComponent {
      private:
        bool _set;

      public:
        Output(std::string name);
        ~Output();

        void simulate(std::size_t tick) override;
        void setLink(std::size_t pin, nts::IComponent &other,
            std::size_t otherPin) override;
    };
} // namespace nts

#endif /* CC0AAFBC_DF41_42E5_A927_E52669778601 */
