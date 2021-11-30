#include "numbersystem.h"

using namespace stl;
void NumberSystem::setNumber(double const& num) {
    decimalNumber = num;
    binaryNumber = decToBinary();
    octalNumber = decToOct();
    hexNumber = decToHex();
}
std::string NumberSystem::binaryNotation() {
    return binaryNumber;
}
std::string NumberSystem::octalNotation() {
    return octalNumber;
}
std::string NumberSystem::hexNotation() {
    return hexNumber;
}

std::string NumberSystem::decToBinary(){
    auto isNegative = 0 > decimalNumber ? true : false;
    std::optional<std::string> decPart{ std::nullopt };
    if (isNegative)
        decimalNumber *= -1;
    float fractionalPart = decimalNumber - ullType(decimalNumber);
    if (fractionalPart > 0.0) {
        decPart = fractionalPartToBinary(fractionalPart);
    }
    ullType quotient{ ullType(decimalNumber) }, remainder;
    std::string answer;
    while (quotient > 0) {
        remainder = quotient % 2;
        quotient /= 2;
        answer += std::to_string(remainder);
    }
    std::reverse(std::begin(answer), std::end(answer));

    std::string prefix((4 - (std::size(answer) % 4)), '0');
    prefix = prefix + answer;
    answer.clear();
    for (std::size_t i{ 0 }; i < std::size(prefix); ++i) {
        if (i % 4 == 0 && i != 0)
            answer += ' ';
        answer += prefix[i];
    }
    if (decPart.has_value())
        answer = answer + '.' + decPart.value();
    if (isNegative)
        answer = "-" + answer;
    return answer;
}

std::string NumberSystem::fractionalPartToBinary(double const& decimalPart) {
    std::uint32_t remainder{ 0 };
    double quotient{ decimalPart };
    std::string answer{ "" };
    while (std::size(answer) < 9) {
        if (std::size(answer) == 4)
            answer += ' ';
        remainder = std::uint32_t(quotient * 2);
        auto t = std::to_string(quotient * 2);
        t.at(0) = '0';
        quotient = std::stof(t);
        answer += std::to_string(remainder);
    }
    return answer;
}

std::string NumberSystem::decToOct() {
    auto isNegative = 0 > decimalNumber ? true : false;
    std::optional<std::string> decPart{ std::nullopt };
    if (isNegative)
        decimalNumber *= -1;
    float fractionalPart = decimalNumber - ullType(decimalNumber);
    if (fractionalPart > 0.0) {
        decPart = fractionalPartToOctal(fractionalPart);
    }
    ullType quotient{ ullType(decimalNumber) }, remainder;
    std::string answer;
    while (quotient > 0) {
        remainder = quotient % 8;
        quotient /= 8;
        answer += std::to_string(remainder);
    }
    std::reverse(std::begin(answer), std::end(answer));
    if (decPart.has_value())
        answer = answer + '.' + decPart.value();
    if (isNegative)
        answer = "-" + answer;
    return answer;
}

std::string NumberSystem::fractionalPartToOctal(double const& decimalPart) {
    std::uint32_t remainder{ 0 };
    double quotient{ decimalPart };
    std::string answer{ "" };
    while (std::size(answer) < 4) {
        remainder = std::uint32_t(quotient * 8);
        auto t = std::to_string(quotient * 8);
        t.at(0) = '0';
        quotient = std::stof(t);
        answer += std::to_string(remainder);
    }
    return answer;
}

std::string NumberSystem::decToHex() {
    std::unordered_map<std::string, std::string> binaryHexEquivalent{
     {"0001", "1"}, {"0010", "2"}, {"0011", "3"}, {"0100", "4"}, {"0101", "5"},
     {"0110", "6"}, {"0111", " 7"}, {"1000", "8"}, {"1001", "9"}, {"1010", "A"},
     {"1011", "B"}, {"1100", "C"}, {"1101", "D"}, {"1110", "E"}, {"1111", "F"}
    };
    std::string integerPart{ "" };
    std::optional<std::string> decimalPart{ std::nullopt };
    auto radixPosition = binaryNumber.find('.');
    if (radixPosition != std::string::npos) {
        decimalPart = { binaryNumber, radixPosition + 1, binaryNumber.size() - radixPosition };
    }
    integerPart = { binaryNumber, 0, radixPosition};

    std::string answer{ "" };
    auto split = [](std::string_view number) {
        std::vector<std::string> ans;
        std::string tempStr;
        for (auto elem : number) {
            if (elem == ' ') {
                ans.push_back(tempStr);
                tempStr.clear();
            }
            else tempStr += elem;
        }
        ans.push_back(tempStr);
        return ans;
    };
    for (auto& elem : split(integerPart)) {
        answer += binaryHexEquivalent[elem];
    }
    if (decimalPart.has_value()) {
        answer += '.';
        for (auto& elem : split(decimalPart.value())) {
            answer += binaryHexEquivalent[elem];
        }
    }
    return answer;
}
