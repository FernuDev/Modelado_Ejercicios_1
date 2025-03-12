#include <iostream>
#include "./src/Solution.h"

int main() {

    const std::vector<std::vector<int>> matrix = { {1,2}, {2,4} };
    const std::vector<int> respuesta = Solution::get_repeated_missing_number(matrix);
    std::cout << "\nRepetido: " << respuesta[0] << ", Faltante: " << respuesta[1] << std::endl;

    const std::string roman = "LVIII";
    const int number = Solution::roman_to_integer(roman);
    std::cout << number << std::endl;

    constexpr int num = 456;
    const std::string roman_solution = Solution::integer_to_roman(num);
    std::cout << roman_solution << std::endl;

    return 0;
}