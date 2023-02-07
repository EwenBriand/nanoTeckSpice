/*
** EPITECH PROJECT, 2022
** my project
** File description:
** main
*/

#include <stddef.h>
#include <string>
#include "my.hpp"
#include "nts.hpp"

int main(int argc, char **argv, char **env)
{
    if (env[0] == NULL)
        return ERROR_VALUE;

    // parsing(argv[1]);

    nts::Output out("output");
    nts::Output out2("output2");
    nts::Input input(std::string("input1"));
    nts::Input input2(std::string("input2"));
    nts::And and_m;
    nts::Xor or_m;

    input.setLink(0, and_m, 0);
    and_m.setLink(1, input2, 0);
    out.setLink(0, and_m, 2);

    input.getList()[0]->setState(nts::Tristate::True);
    // input2.getList()[0]->setState(nts::Tristate::False);
    and_m.simulate(1);
    input.simulate(1);
    input2.simulate(1);
    out.simulate(1);
    out2.simulate(1);

    or_m.setLink(0, input, 0);
    or_m.setLink(1, input2, 0);
    or_m.setLink(2, out2, 0);

    input.getList()[0]->setState(nts::Tristate::False);
    input2.getList()[0]->setState(nts::Tristate::False);

    or_m.simulate(1);
    input.simulate(1);
    input2.simulate(1);
    out2.simulate(1);

    return END_VALUE;
}
