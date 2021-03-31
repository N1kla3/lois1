//
// Created by nicola on 04/02/2021.
//

#include <string>
#include <iostream>
#include <set>
#include "KNF.h"
#include "Validation.h"

bool CheckKNF(const std::string& str) noexcept
{
    if (!Validate(str))
    {
        std::cout << "Validation Failed\n";
        return false;
    }

    std::set<int> conjunction;
    std::set<int> disjunction;

    int left_count = 0, right_count = 0;
    for (auto literal : str)
    {
        if (literal == '(')
        {
            left_count++;
        }
        if (literal == ')')
        {
            right_count++;
        }
        if (literal == '|')
        {
            disjunction.insert(left_count - right_count);
        }
        if (literal == '&')
        {
            conjunction.insert(left_count - right_count);
        }
    }
	if (!conjunction.empty() && left_count == 0) return false;
    bool good_conjunction = conjunction.size() == 1;
    bool good_disjunction = disjunction.size() == 1 && *conjunction.cbegin() < *disjunction.cbegin();
    good_disjunction = good_disjunction ? good_disjunction : disjunction.empty();
    if (good_conjunction && good_disjunction)
    {
        return true;
    }
    return false;
}
