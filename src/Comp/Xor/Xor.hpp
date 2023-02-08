/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-tekspice-ewen.briXor
** File description:
** Xor
*/

#ifndef D041E0C5_7AAD_47A0_9A37_7A6E9F13059
#define D041E0C5_7AAD_47A0_9A37_7A6E9F13059

#include "../PIN/PIN.hpp"
#include "nts.hpp"
#include <unordered_map>

namespace nts
{
    class Xor : virtual public nts::IComponent {
      protected:
        std::unordered_map<int, nts::PIN *> _pins;
        std::vector<int> _deleting;

      public:
        Xor();
        ~Xor();

        void simulate(std::size_t tick) override;
        void setLink(std::size_t pin, nts::IComponent &other,
            std::size_t otherPin) override;

        std::unordered_map<int, nts::PIN *> getList() const override;
    };
} // namespace nts

#endif /* D041E0C5_7AAD_47A0_9A37_7A6E9F13058B */
