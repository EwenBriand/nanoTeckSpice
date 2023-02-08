/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-tekspice-ewen.briand
** File description:
** ControlTower
*/

#ifndef CONTROLTOWER_HPP_
#define CONTROLTOWER_HPP_

#include "my.hpp"
#include "nts.hpp"

namespace nts
{
    class ControlTower {
      public:
        ControlTower();
        ~ControlTower();
        int addElement(std::string name, std::string type);
        nts::IComponent *getElement(std::string name);
        const std::unordered_map<std::string, nts::IComponent *> &getCircuit();

      protected:
      private:
        std::unordered_map<std::string, nts::IComponent *> _circuit;
    };
}; // namespace nts

#endif /* !CONTROLTOWER_HPP_ */
