/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-tekspice-ewen.briOr
** File description:
** Or
*/

#ifndef D041E0C5_7AAD_47A0_9A37_7A6E9F13058
#define D041E0C5_7AAD_47A0_9A37_7A6E9F13058

#include "../PIN/PIN.hpp"
#include "nts.hpp"
#include <unordered_map>

namespace nts
{
    class Or : virtual public nts::IComponent {
      protected:
        std::unordered_map<int, nts::PIN *> _pins;

      public:
        Or();
        ~Or();

        void simulate(std::size_t tick) override;
        void setLink(std::size_t pin, nts::IComponent &other,
            std::size_t otherPin) override;

        std::unordered_map<int, nts::PIN *> getList() const override;
    };
} // namespace nts

#endif /* D041E0C5_7AAD_47A0_9A37_7A6E9F13058B */
