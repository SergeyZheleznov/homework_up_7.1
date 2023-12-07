// homework_up_7.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <algorithm>
#include <iterator>

void dropDup(std::vector<char>& v1)
{
    for (auto base = v1.begin(); base != v1.end(); ++base)
    {
        for (auto it = base + 1; it != v1.end(); )
        {
            if (*base == *it)
            {
                it = v1.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }
}

class Letter 
{
public:
    Letter (char a, int x)
    {
        this->a = a;
        this->x = x;
    }
public:
    char a;
    int x;

    void print(char a, int x)
    {
        std::cout << a << " : " << x << std::endl;
    }
};


int main()
{
    setlocale(LC_ALL, "ru");
    int count = 0;
    char s;
    std::vector<char> ivec1;

    std::cout << "Введите фразу" << std::endl;
    do
    {
        std::cin.get(s);
        ivec1.push_back(s);
    } while (s != '\n');

    std::cout << "Вы ввели фразу: " << std::endl;

    std::cout << "[IN]:" << std::endl;

    for (int i = 0; i < ivec1.size(); i++)
    {
        std::cout << ivec1[i] << std::endl;
    }

    std::vector<char> ivec2;

    copy(ivec1.begin(), ivec1.end(), back_inserter(ivec2));

    auto result = std::unique(std::begin(ivec1), std::end(ivec1));

    dropDup(ivec1);

    std::vector<Letter> res;

    //Расчёт количества одинаковых элементов в первоначальном векторе;

   for (int i = 0; i < ivec1.size() - 1; i++)
   {
       count = 0;
       for (int j = 0; j < ivec2.size() - 1; j++)
       {
            if (ivec1[i] == ivec2[j])
            {
                count++;
            };   
        }
        Letter l1(ivec1[i], count);
        res.push_back(l1);
   }


   sort(res.begin(), res.end(), [](const Letter& p1, Letter& p2)
       {
           return p1.x > p2.x;
       });

   //Вывод отсортированных уникальных элементов
   std::cout << "[OUT]: " << std::endl;
   
   for (auto element : res)
   {
       std::cout << element.a << " : "  << element.x << std::endl;
   }
   return 0;
}
