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
    _value = 0;
    _nameError = "";
    _error.type = Error::UNKNOWN;
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
        }
    }

    for (const auto &key : keys_to_remove) {
        delete _circuit[key];
        _circuit[key] = nullptr;
        _circuit.erase(key);
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
    }
}

int nts::ControlTower::addElement(std::string name, std::string type)
{
    std::map<std::string, int> typeMap = {{"input", 1}, {"output", 2},
        {"and", 3}, {"or", 4}, {"xor", 5}, {"not", 6}, {"clock", 7},
        {"true", 8}, {"false", 9}, {"logger", 10}, {"4001", 11}, {"4011", 12},
        {"4030", 13}, {"4069", 14}, {"4071", 15}, {"4081", 16}};

    int typeValue = 0;
    auto it = typeMap.find(type);

    if (_circuit.find(name) != _circuit.end()) {
        _nameError = name;
        _error.type = nts::ControlTower::Error::SAME;
        return 84;
    }

    if (it != typeMap.end()) {
        typeValue = it->second;
    } else {
        _nameError = type;
        _error.type = nts::ControlTower::Error::TYPE;
        return 84;
    }

    _name.push_back(name);
    _value++;
    switch (typeValue) {
        case 1: _circuit[name] = new nts::Input(name); break;
        case 2: _circuit[name] = new nts::Output(name); break;
        case 3: _circuit[name] = new nts::And(); break;
        case 4: _circuit[name] = new nts::Or(); break;
        case 5: _circuit[name] = new nts::Xor(); break;
        case 6: _circuit[name] = new nts::Invert(); break;
        case 7: _circuit[name] = new nts::Clock(name); break;
        case 8: _circuit[name] = new nts::ATrue(name); break;
        case 9: _circuit[name] = new nts::AFalse(name); break;
        case 10: _circuit[name] = new nts::Logger(); break;
        case 11: _circuit[name] = new nts::O4001(); break;
        case 12: _circuit[name] = new nts::C4011(); break;
        case 13: _circuit[name] = new nts::C4030(); break;
        case 14: _circuit[name] = new nts::C4069(); break;
        case 15: _circuit[name] = new nts::C4071(); break;
        case 16: _circuit[name] = new nts::C4081(); break;
        default:
            _nameError = type;
            _error.type = nts::ControlTower::Error::TYPE;
            return 84;
            ;
    }

    return 0;
}

const std::unordered_map<std::string, nts::IComponent *> &
nts::ControlTower::getCircuit()
{
    return _circuit;
}

std::vector<std::string> &nts::ControlTower::getName()
{
    return _name;
}

nts::IComponent *nts::ControlTower::getElement(std::string name)
{
    auto it = _circuit.find(name);

    if (it != _circuit.end())
        return it->second;
    return nullptr;
}

const char *nts::ControlTower::Error::what() const throw()
{
    switch (type) {
        case LEX: return "Bad Lexical or syntax error";
        case TYPE: return "Unknow component type '";
        case NAME: return "Unknow component name '";
        case SAME: return "' component already exists";
        case CHIPSET: return "No chipset defined";
        default: return "Unknonw error";
    }
}
