/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-tekspice-ewen.briO4001
** File description:
** O4001
*/

#ifndef D041E0C5_7AAD_47A0_9A37_7A6E9F1305213
#define D041E0C5_7AAD_47A0_9A37_7A6E9F1305213

#include "../PIN/PIN.hpp"
#include "nts.hpp"
#include <unordered_map>

namespace nts
{
    class O4001 : virtual public nts::IComponent {
      protected:
        std::unordered_map<int, nts::PIN *> _pins;
        std::vector<int> _deleting;

      public:
        O4001();
        ~O4001();

        void simulate(std::size_t tick) override;
        void setLink(std::size_t pin, nts::IComponent &other,
            std::size_t otherPin) override;

        std::unordered_map<int, nts::PIN *> getList() const override;
    };
} // namespace nts

#endif /* A65A9156_8F10_44C2_A7A0_484D77F59676 */
