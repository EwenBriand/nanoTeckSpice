/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-tekspice-ewen.briand
** File description:
** parse
*/

#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <vector>
#include "my.hpp"
#include "nts.hpp"
#include <string_view>

void split_string(
    std::string const &str, const char delim, std::vector<std::string> &out)
{
    std::stringstream ss(str);

    std::string s;
    while (std::getline(ss, s, delim)) {
        out.push_back(s);
    }
}

std::string remove_space(std::string str)
{
    for (int i = str.size() - 1; i > 0; i--)
        if (str[i] == '\t')
            str[i] = ' ';
        else if (str[i] == ' ' && str[i] == str[i - 1])
            str.erase(str.begin() + i);

    if (str[0] == ' ')
        str.erase(str.begin());
    if (str[str.size() - 1] == ' ')
        str.erase(str.size() - 1);

    return str;
}

bool check_path(const char *file)
{
    std::string path(file);
    std::string ext = path.substr(path.find_last_of(".") + 1);

    if (ext != "nts")
        return false;
    return true;
}

bool check_pin(nts::IComponent *comp, int pin)
{
    if (comp == nullptr)
        return true;
    if (pin < 0 || pin > comp->getNbPins() - 1)
        return true;
    return false;
}

void make_on_link(
    std::vector<std::string> &line, nts::ControlTower *tower, int &stop)
{
    std::vector<std::string> pin1;
    std::vector<std::string> pin2;
    split_string(line[0], ':', pin1);
    split_string(line[1], ':', pin2);

    if (pin1.size() != 2 || pin2.size() != 2) {
        tower->_error.type = nts::ControlTower::Error::LEX;
        stop = 84;
    } else if (tower->getElement(pin1[0]) == nullptr) {
        tower->_nameError = pin1[0];
        tower->_error.type = nts::ControlTower::Error::NAME;
        stop = 84;
    } else if (tower->getElement(pin2[0]) == nullptr) {
        tower->_nameError = pin2[0];
        tower->_error.type = nts::ControlTower::Error::NAME;
        stop = 84;
    } else if (check_pin(tower->getElement(pin1[0]), std::stoi(pin1[1]) - 1)
        || check_pin(tower->getElement(pin2[0]), std::stoi(pin2[1]) - 1)) {
        tower->_error.type = nts::ControlTower::Error::LEX;
        stop = 84;
    } else
        tower->getElement(pin1[0])->setLink(std::stoi(pin1[1]) - 1,
            *tower->getElement(pin2[0]), std::stoi(pin2[1]) - 1);
}

void make_links(std::vector<std::string> &out, nts::ControlTower *tower)
{
    int stop = 0;
    std::vector<std::string> line;

    for (auto it = out.begin(); it != out.end() && stop == 0; it++) {
        line.clear();
        split_string(*it, ' ', line);

        if (line.size() == 2 && line[0][0] != '#')
            make_on_link(line, tower, stop);
        else if (line.size() > 2) {
            tower->_error.type = nts::ControlTower::Error::LEX;
            stop = 84;
        }
    }
}

std::vector<std::string> remove_comments(std::vector<std::string> &out)
{
    for (auto it = out.begin(); it != out.end(); it++)
        (*it) = (*it).substr(0, (*it).find('#'));

    return out;
}

int get_data(const char *file, nts::ControlTower *tower, std::string &data)
{
    std::ostringstream ss;
    std::ifstream f(file);

    if (check_path(file) && f.is_open()) {
        ss << f.rdbuf();
        data = ss.str();
    } else {
        tower->_error.type = nts::ControlTower::Error::LEX;
        return ERROR_VALUE;
    }

    data = remove_space(data);
    return END_VALUE;
}

nts::ControlTower *parse(const char *file)
{
    nts::ControlTower *tower = new nts::ControlTower();
    std::string data;
    std::vector<std::string> out;
    std::vector<std::string> line;
    int stop = 0;

    if (get_data(file, tower, data) == ERROR_VALUE)
        return tower;

    split_string(data, '\n', out);
    remove_comments(out);

    for (auto it = out.begin(); it != out.end();) {
        if (*it == ".chipsets:")
            break;
        it = out.erase(it);
    }

    if (out.size() == 0) {
        tower->_error.type = nts::ControlTower::Error::CHIPSET;
        return tower;
    }

    for (auto it = out.begin(); it != out.end() && stop == 0;) {
        if (*it == ".links:")
            break;

        line.clear();
        split_string(*it, ' ', line);
        if (line.size() == 2 && line[0][0] != '#')
            stop = tower->addElement(line[1], line[0]);
        it = out.erase(it);
    }

    if (stop != 0)
        return tower;
    else if (out.size() == 0) {
        tower->_error.type = nts::ControlTower::Error::LEX;
        return tower;
    }

    make_links(out, tower);
    std::sort(tower->getName().begin(), tower->getName().end(),
        [](const std::string &a, const std::string &b) {
            return a < b;
        });

    return tower;
}
