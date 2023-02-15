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

void make_on_link(std::vector<std::string> &out,
    std::vector<std::string> &line, nts::ControlTower *tower, int &stop)
{
    std::vector<std::string> pin1;
    std::vector<std::string> pin2;
    tokenize(line[0], ':', pin1);
    tokenize(line[1], ':', pin2);

    if (tower->getElement(pin1[0]) == nullptr || std::stoi(pin1[1]) - 1 >= 3
        || (std::stoi(pin1[1]) - 1 >= 2
            && tower->getElement(pin1[0])->getType() == nts::Type::TNot)) {
        tower->_nameError = pin1[0];
        tower->_error.type = nts::ControlTower::Error::NAME;
        stop = 84;
    } else if (tower->getElement(pin2[0]) == nullptr
        || std::stoi(pin2[1]) - 1 >= 3
        || (std::stoi(pin2[1]) - 1 >= 2
            && tower->getElement(pin2[0])->getType() == nts::Type::TNot)) {
        tower->_nameError = pin2[0];
        tower->_error.type = nts::ControlTower::Error::NAME;
        stop = 84;
    } else {
        tower->getElement(pin1[0])->setLink(std::stoi(pin1[1]) - 1,
            *tower->getElement(pin2[0]), std::stoi(pin2[1]) - 1);
    }
}

void make_links(std::vector<std::string> &out, std::vector<std::string> &line,
    nts::ControlTower *tower, int &stop)
{
    for (auto it = out.begin(); it != out.end() && stop == 0; it++) {
        line.clear();
        tokenize(*it, ' ', line);
        if (line.size() == 2) {
            make_on_link(out, line, tower, stop);
        } else if (line.size() > 2) {
            tower->_error.type = nts::ControlTower::Error::LEX;
            stop = 84;
        }
    }
}

nts::ControlTower *parse(const char *file)
{
    nts::ControlTower *tower = new nts::ControlTower();
    std::string data;
    std::ostringstream ss;
    std::ifstream f(file);
    std::vector<std::string> out;
    std::vector<std::string> line;
    int stop = 0;

    if (check_path(file) && f.is_open()) {
        ss << f.rdbuf();
        data = ss.str();
    } else {
        tower->_error.type = nts::ControlTower::Error::LEX;
        return tower;
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

    if (out.size() == 0) {
        tower->_error.type = nts::ControlTower::Error::CHIPSET;
        return tower;
    }

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

    if (stop != 0)
        return tower;
    else if (out.size() == 0) {
        tower->_error.type = nts::ControlTower::Error::LEX;
        return tower;
    }

    make_links(out, line, tower, stop);

    // auto _circuit = tower->getCircuit();
    // for (auto it : _circuit) {
    //     std::cout << it.first << std::endl;
    // }
    return tower;
}
