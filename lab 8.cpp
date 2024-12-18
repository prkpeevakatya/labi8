#include<fstream>
#include <iostream>
#include<cmath>
#include<iomanip>
#include <locale.h>
using namespace std;


string vowels = "AEIOUYaeiouy";
string consonants = "QWRTPSDFGHJKLZXVBNMqwrtpsdfghjklzxvbnm";


bool is_palindrome(string s)
{
    int n = s.length();
    if (n == 1) return false;
    for (int i = 0; i < n / 2; i++)
        if (s[i] != s[n - i - 1]) return false;
    return true;
}

bool has_palindromes(string* words, int n)
{
    for (int i = 0; i < n; i++)
        if (is_palindrome(words[i])) return true;
    return false;
}

int count_consonants(string s) //счёт согласных 
{
    int counter = 0;
    for (int i = 0; i < s.length(); i++)
        if (consonants.find(s[i]) != -1) counter++;
    return counter;
}

void duplicate_vowels(string& s)
{
    for (int i = 0; i < s.length(); )
        if (vowels.find(s[i]) != -1)
        {
            s.insert(i + 1, 1, s[i]);
            i += 2;
        }
        else i++;
}

void delete_consonants(string& s)
{
    for (int i = 0; i < s.length(); )
        if (consonants.find(s[i]) != -1) s.erase(i, 1);
        else i++;
}
void sort_1(string* words, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (count_consonants(words[i]) < count_consonants(words[j]))
                swap(words[i], words[j]);
}

void sort_2(string* words, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (words[i] < words[j])
                swap(words[i], words[j]);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    string s = "ANTANANARIVU";
    int const maxi = 100;
    string words[maxi] = { "ANTANANARIVU" };
    if (!is_palindrome(s)) sort_1(words, s.length());
    else
    {
        duplicate_vowels(s);
        sort_2(words, s.length());
    }
    duplicate_vowels(s);
    cout << s;
    return 0;
}
