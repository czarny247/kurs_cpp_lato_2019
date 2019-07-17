#include <string>

/*
palindrom.cpp: In function ‘bool palindrom(std::__cxx11::string)’:
palindrom.cpp:5:31: warning: conversion to ‘float’
from ‘std::__cxx11::basic_string<char>::size_type
{aka long unsigned int}’ may alter its value [-Wconversion]
     float dlugosc = napis.size();
                     ~~~~~~~~~~^~
palindrom.cpp:8:19: warning: conversion to ‘std::__cxx11::basic_string<char>::size_type
{aka long unsigned int}’ from ‘float’ may alter its value [-Wfloat-conversion]
         if(napis[i] != napis[dlugosc - (i + 1)])
                   ^
palindrom.cpp:8:38: warning: conversion to ‘std::__cxx11::basic_string<char>::size_type
{aka long unsigned int}’ from ‘float’ may alter its value [-Wfloat-conversion]
         if(napis[i] != napis[dlugosc - (i + 1)])
*/
bool palindrom(std::string napis)
{
    float dlugosc = napis.size();
    for(float i = 0; i < (dlugosc / 2); ++i)
    {
        if(napis[i] != napis[dlugosc - (i + 1)])
            return false;
    }
    return true;
}

int main()
{
	return 0;
}