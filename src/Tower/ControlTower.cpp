/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-tekspice-ewen.briand
** File description:
** ControlTower
*/

#include "ControlTower.hpp"
#include <map>

nts::ControlTower::ControlTower()
{
}

nts::ControlTower::~ControlTower()
{
    std::vector<std::string> keys_to_remove;

    for (auto it : _circuit) {
        if (it.second != nullptr
            && it.second->getType() == nts::Type::output) {
            delete it.second;
            _circuit[it.first] = nullptr;
            keys_to_remove.push_back(it.first);
            std::cout << "Deleting element 1: " << it.first << std::endl;
        }
        std::cout << "Deleting element 2: " << it.first << std::endl;
    }

    for (const auto &key : keys_to_remove) {
        delete _circuit[key];
        _circuit[key] = nullptr;
        _circuit.erase(key);
        std::cout << "Deleting element: " << key << std::endl;
    }

    keys_to_remove.clear();

    for (auto it : _circuit)
        if (it.second != nullptr) {
            delete _circuit[it.first];
            _circuit[it.first] = nullptr;
            keys_to_remove.push_back(it.first);
        }

    for (const auto &key : keys_to_remove) {
        delete _circuit[key];
        _circuit[key] = nullptr;
        _circuit.erase(key);
        std::cout << "Deleting element: " << key << std::endl;
    }
}

int nts::ControlTower::addElement(std::string name, std::string type)
{
    std::cout << "Adding element: " << name << " of type: " << type
              << std::endl;
    std::map<std::string, int> typeMap = {{"input", 1}, {"output", 2},
        {"and", 3}, {"or", 4}, {"xor", 5}, {"not", 6}};

    int typeValue = 0;
    auto it = typeMap.find(type);

    if (_circuit.find(name) != _circuit.end())
        return 84;

    if (it != typeMap.end()) {
        typeValue = it->second;
    } else {
        return 84;
    }

    switch (typeValue) {
        case 1: _circuit[name] = new nts::Input(name); break;
        case 2: _circuit[name] = new nts::Output(name); break;
        case 3: _circuit[name] = new nts::And(); break;
        case 4: _circuit[name] = new nts::Or(); break;
        case 5: _circuit[name] = new nts::Xor(); break;
        case 6: _circuit[name] = new nts::Invert(); break;
        // case "clock": _circuit[name] = new Clock(name); break;
        // case "true": _circuit[name] = new ATrue(name); break;
        // case "false": _circuit[name] = new AFalse(name); break;
        // case "4001": _circuit[name] = new c4001(name); break;
        // case "4011": _circuit[name] = new c4011(name); break;
        // case "4030": _circuit[name] = new c4030(name); break;
        // case "4069": _circuit[name] = new c4069(name); break;
        // case "4071": _circuit[name] = new c4071(name); break;
        // case "4081": _circuit[name] = new c4081(name); break;
        default: return 84;
    }

    return 0;
}

const std::unordered_map<std::string, nts::IComponent *> &
nts::ControlTower::getCircuit()
{
    return _circuit;
}

nts::IComponent *nts::ControlTower::getElement(std::string name)
{
    auto it = _circuit.find(name);

    if (it != _circuit.end())
        return it->second;
    return nullptr;
}
