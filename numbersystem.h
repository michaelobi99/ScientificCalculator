#ifndef NUMBERSYSTEM_H
#define NUMBERSYSTEM_H


#include <string>
#include <vector>
#include <algorithm>
#include <string_view>
#include <string>
#include <optional>
#include <unordered_map>

namespace stl {
class NumberSystem
    {
    public:
        NumberSystem() = default;
        void setNumber(double const&);
        [[nodiscard]] std::string binaryNotation();
        [[nodiscard]] std::string octalNotation();
        [[nodiscard]] std::string hexNotation();
    private:
        using ullType = unsigned long long;
        [[nodiscard]] std::string decToBinary();
        [[nodiscard]] std::string fractionalPartToBinary(double const&);
        [[nodiscard]] std::string decToOct();
        [[nodiscard]] std::string fractionalPartToOctal(double const&);
        [[nodiscard]] std::string decToHex();
        double decimalNumber{ 0 };
        std::string binaryNumber{ "" };
        std::string octalNumber{ "" };
        std::string hexNumber{ "" };
    };
}

#endif // NUMBERSYSTEM_H
