//
// Created by nicola on 04/02/2021.
//
#include <string>
#include <iostream>
#include "Validation.h"

const char alphabet[] = {'Q', 'W', 'E','R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J',
                         'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M'};

enum SYMB
{
    AND = '&',
    OR = '|',
    NEGAT = '-',
    LEFT_BRACE = '(',
    RIGHT_BRACE = ')',
    SPACE = ' '
};

bool checkAndOr(char prev) noexcept;
bool checkNegat(char prev) noexcept;
bool checkLeftBrace(char prev) noexcept;
bool checkRightBrace(char prev) noexcept;
bool checkLetter(char prev) noexcept;


bool Validate(const std::string& str) noexcept
{
    if (str.empty()) return false;

    int left = 0, right = 0;
    char prev = '(';

    for (auto ch : str)
    {
        switch (ch)
        {
            case AND:
            case OR:
            {
                if (!checkAndOr(prev))
                    return false;
                break;
            }

            case NEGAT:
            {
                if (!checkNegat(prev))
                    return false;
                break;
            }

            case LEFT_BRACE:
            {
                if (!checkLeftBrace(prev))
                    return false;
                left++;
                break;
            }

            case RIGHT_BRACE:
            {
                if (!checkRightBrace(prev))
                    return false;
                right++;
                break;
            }

            case SPACE:
            {
                ch = prev;
                break;
            }

            default: {
                bool miss_literal = true;
                for (auto temp : alphabet) {
                    if (ch == temp) {
                        if (!checkLetter(prev)) {
                            return false;
                        } else {
                            miss_literal = false;
                        }
                    }
                }
                if (miss_literal)
                {
                    std::cout << "literal not found\n";
                    return false;
                }
                break;
            }
        }

        prev = ch;
    }

    return left == right;
}

/** @brief formats & in \/ and | in /\ */
std::string reformatInput(const std::string& str) noexcept
{
	std::string result{};
	bool skip = false;
	for (const auto ch : str)
	{
		if (skip)
		{
			skip = false;
			continue;
		}
		if (ch == '/')
		{
			result.push_back('&');
			skip = true;
		}
		else if (ch == '\\')
		{
			result.push_back('|');
			skip = true;
		}
		else
		{
			result.push_back(ch);
		}
	}
	return result;
}

bool checkAndOr(char prev) noexcept
{
    if (prev == RIGHT_BRACE)
    {
        return true;
    }
    for (auto ch : alphabet)
    {
        if (ch == prev) return true;
    }
    return false;
}

bool checkNegat(char prev)noexcept
{
    if (prev == AND ||
        prev == OR ||
        prev == LEFT_BRACE)
    {
        return true;
    }
    return false;
}

bool checkLeftBrace(char prev)noexcept
{
    if (prev == AND ||
        prev == OR ||
        prev == LEFT_BRACE ||
        prev == NEGAT)
    {
        return true;
    }
    return false;
}

bool checkRightBrace(char prev)noexcept
{
    if (prev == RIGHT_BRACE)
    {
        return true;
    }
    for (auto ch : alphabet)
    {
        if (ch == prev)
        {
            return true;
        }
    }
    return false;
}

bool checkLetter(char prev) noexcept
{
    if (prev == AND ||
        prev == OR ||
        prev == LEFT_BRACE ||
        prev == NEGAT)
    {
        return true;
    }
    return false;
}