//
// Created by fernudev on 3/11/25.
//

#include "Solution.h"

///
/// Función encargada de buscar el número faltante en una matriz de nxn
/// en un rango de [1, n] y tambien retornar el número que se encuentra repetido
/// @param matrix std::vector< std::vector<int > matriz de números enteros que analizaremos
///
/// @return std::vector <int> Donde el primer elemento es el
std::vector<int> Solution::get_repeated_missing_number(const std::vector<std::vector<int> > &matrix){

    const size_t n = matrix.size();
    const int suma_estimada = static_cast<int>( ( (n*n) /2)*( (n*n) +1) ); // Usamos la formula de gauss para calcular la suma de [1,n]
    int suma = 0;
    int repetido = 0, faltante = 0;

    std::map<int, int> hashMap;

    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; j < n; j++ ) {
            if (hashMap.contains(matrix[i][j])) {
                hashMap[matrix[i][j]]++;
            } else {
                hashMap[matrix[i][j]] = 1;
            }
        }
    }

    for (auto [fst, snd] : hashMap) {
        if (snd == 2) {
            repetido = fst;
        }
        suma += fst;
    }

    faltante = abs(suma - suma_estimada);

    return {repetido, faltante};
}

/// Función que convierte un numero entero del sistema decimal al sistema romano
/// @param num Número entero a convertir en romano
/// @return Retorna un std::string que representa a num en el sistema romano
std::string Solution::integer_to_roman(int num) {
    std::string number = "";

    // Mapeamos los números romanos desde 1 hasta 1000 que son los que necesitaremos para construir el numero romano
    std::vector<std::pair<std::string, int>> roman;
    roman.push_back({"M",1000});
    roman.push_back({"CM",900});
    roman.push_back({"D",500});
    roman.push_back({"CD",400});
    roman.push_back({"C",100});
    roman.push_back({"XC",90});
    roman.push_back({"L",50});
    roman.push_back({"XL",40});
    roman.push_back({"X",10});
    roman.push_back({"IX",9});
    roman.push_back({"V",5});
    roman.push_back({"IV",4});
    roman.push_back({"I",1});

    for (auto r:roman){
        while(num>=r.second){
            number+=r.first;
            num-=r.second;
        }
    }

    return number;
}

///
/// Función encargada de calcular el equivalente de un número romano en entero en el sistema decimal
/// @param roman Es un string de un número romano
/// @return Retorna la conversion de dicho numero en un entero en nuestro sistema
///
int Solution::roman_to_integer(const std::string &roman) {
    std::map<char, int> roman_map;
    int number = 0;

    roman_map['I'] = 1;
    roman_map['V'] = 5;
    roman_map['X'] = 10;
    roman_map['L'] = 50;
    roman_map['C'] = 100;
    roman_map['D'] = 500;
    roman_map['M'] = 1000;

    for(int i=0;i<roman.size();i++){
        if(roman_map[roman[i]] > roman_map[roman[i+1]] || roman_map[roman[i]] == roman_map[roman[i+1]] ){
            number += roman_map[roman[i]];
        }else{
            number -= roman_map[roman[i]];
        }
    }
    return number;
}

std::string Solution::get_biggest_prefix(std::vector<std::string> words) {
    return "";
}

