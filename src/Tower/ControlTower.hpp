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
        const std::unordered_map<int, std::string> &getName();

      protected:
      private:
        std::unordered_map<std::string, nts::IComponent *> _circuit;
        std::unordered_map<int, std::string> _name;
        int _value;
    };
}; // namespace nts

#endif /* !CONTROLTOWER_HPP_ */
