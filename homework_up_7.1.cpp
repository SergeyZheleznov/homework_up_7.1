// homework_up_7.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <algorithm>
#include <iterator>

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

    std::cout << "Hello World!\n";
    int count = 0;
    char s;
    std::vector<char> ivec1;

    std::cout << "������� �����" << std::endl;
    do
    {
        std::cin.get(s);
        ivec1.push_back(s);
    } while (s != '\n');

    std::cout << "�� ����� �����: " << std::endl;

    for (int i = 0; i < ivec1.size(); i++)
    {
        std::cout << ivec1[i];
    }

    std::vector<char> ivec2;

    copy(ivec1.begin(), ivec1.end(), back_inserter(ivec2));

    std::cout << "�������� ������� 2 :" << std::endl;

    for (int i = 0; i < ivec2.size(); i++)
    {
        std::cout << ivec2[i] << std::endl;
    }

    auto result = std::unique(std::begin(ivec1), std::end(ivec1));

    ivec1.erase(result, ivec1.end());
    
    std::cout << "�������� ������� 1 ����� ����, ��� ������ �� ���������� ��������:" << std::endl;
    
    for (auto element : ivec1)
    {
        std::cout << element << std::endl;
    }

    //������ ������ �� ��� (����, ��������), ��� ���� ��� �����, � �������� ��� ���������� ���� ����� �� �����

    std::vector<Letter> res;



    std::cout << "������ ���������� ���������� ��������� � �������������� �������" << std::endl;

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
       // std::cout << ivec1[i] << ":" << count << std::endl;
        Letter l1(ivec1[i], count);

        l1.print(ivec1[i], count);
        res.push_back(l1);
   }


   sort(res.begin(), res.end(), [](const Letter& p1, Letter& p2)
       {
           return p1.x > p2.x;
       });

   std::cout << "����� ��������������� ���������� ���������" << std::endl;
   for (auto element : res)
   {
       std::cout << element.a << " : "  << element.x << std::endl;
   }
   return 0;
}
