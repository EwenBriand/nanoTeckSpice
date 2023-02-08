/*
** EPITECH PROJECT, 2023
** B-OOP-400-BAR-4-1-tekspice-ewen.briand
** File description:
** parse
*/

#include "my.hpp"
#include "nts.hpp"

void tokenize(
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
    for (int i = str.size() - 1; i > 0; i--) {
        if (str[i] == ' ' && str[i] == str[i - 1]) {
            str.erase(str.begin() + i);
        }
    }
    if (str[0] == ' ')
        str.erase(str.begin());
    if (str[str.size() - 1] == ' ')
        str.erase(str.size() - 1);

    return str;
}

nts::ControlTower *parse(const char *file)
{
    nts::ControlTower *tower = new nts::ControlTower();
    std::string data;
    std::ostringstream ss;
    std::ifstream f(file);
    std::vector<std::string> out;
    std::vector<std::string> line;
    std::vector<std::string> pin1;
    std::vector<std::string> pin2;
    int stop = 0;

    if (f.is_open()) {
        ss << f.rdbuf();
        data = ss.str();
    } else {
        return nullptr;
    }

    tokenize(data, '\n', out);

    for (auto it = out.begin(); it != out.end(); it++)
        *it = remove_space(*it);

    for (auto it = out.begin(); it != out.end();) {
        if (*it == ".chipsets:") {
            break;
        }
        it = out.erase(it);
    }

    if (out.size() == 0)
        return nullptr;

    // for (size_t i = 0; i < out.size(); i++)
    //     std::cout << out[i] << std::endl;

    for (auto it = out.begin(); it != out.end() && stop == 0;) {
        if (*it == ".links:")
            break;

        line.clear();
        tokenize(*it, ' ', line);
        if (line.size() == 2)
            stop = tower->addElement(line[1], line[0]);
        it = out.erase(it);
    }

    if (out.size() == 0)
        return nullptr;

    for (auto it = out.begin(); it != out.end() && stop == 0; it++) {
        line.clear();
        tokenize(*it, ' ', line);
        if (line.size() == 2) {
            pin1.clear();
            pin2.clear();
            tokenize(line[0], ':', pin1);
            tokenize(line[1], ':', pin2);
            if (tower->getElement(pin1[0]) == nullptr) {
                std::cout << "Unknow component name '" << pin1[0] << "'"
                          << std::endl;
                stop = 84;
            } else if (tower->getElement(pin2[0]) == nullptr) {
                std::cout << "Unknow component name '" << pin2[0] << "'"
                          << std::endl;
                stop = 84;
            } else
                tower->getElement(pin1[0])->setLink(std::stoi(pin1[1]) - 1,
                    *tower->getElement(pin2[0]), std::stoi(pin2[1]) - 1);
        }
    }

    if (stop != 0)
        return nullptr;

    auto _circuit = tower->getCircuit();
    for (auto it : _circuit) {
        std::cout << it.first << std::endl;
    }
    return tower;
}
