#ifndef NUMBERSYSTEM_H
#define NUMBERSYSTEM_H


#include <string>
#include <vector>
#include <algorithm>
#include <charconv>
#include <string_view>
#include <string>
#include <optional>
#include <unordered_map>
#include <tuple>

namespace stl {
    class NumberSystem
    {
    public:
        NumberSystem() = default;
        void setValue(std::string const&);
        [[nodiscard]] std::string binaryNotation();
        [[nodiscard]] std::string octalNotation();
        [[nodiscard]] std::string hexNotation();
    private:
        using ullType = unsigned long long;
        [[nodiscard]] std::string decToBinary();
        [[nodiscard]] std::string fractionalPartToBinary(double const&);
        [[nodiscard]] std::string decToOct();
        [[nodiscard]] std::string decToHex();
        [[nodiscard]] std::string add(std::string_view, std::string_view);
        [[nodiscard]] std::string getTwosComplementForm(std::string_view);
        std::string decimalNumber{""};
        std::string binaryNumber{ "" };
        std::string octalNumber{ "" };
        std::string hexNumber{ "" };
    };
}
#endif // NUMBERSYSTEM_H
