/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-tekspice-ewen.briAComponent
** File description:
** AComponent
*/

#ifndef D041E0C5_7AAD_47A0_9A37_7A6E9F13058B12332432
#define D041E0C5_7AAD_47A0_9A37_7A6E9F13058B12332432

#include "../PIN/PIN.hpp"
#include "nts.hpp"
#include <unordered_map>

namespace nts
{
    class AComponent : virtual public nts::IComponent {
      protected:
        nts::Type _type;
        bool _returned;
        std::unordered_map<int, nts::PIN *> _pins;
        std::vector<int> _deleting;

      public:
        AComponent();
        ~AComponent();

        void setLink(std::size_t pin, nts::IComponent &other,
            std::size_t otherPin) override;
        std::unordered_map<int, nts::PIN *> getList() const override;
        int getNbPins() const;
        virtual void print() override;
        virtual nts::Type getType() override;
    };
} // namespace nts

#endif /* D041E0C5_7AAD_47A0_9A37_7A6E9F13058B */
