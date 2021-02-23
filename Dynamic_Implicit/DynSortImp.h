#pragma once

//!!! Тут должна быть шапка, включающаю условные макросы для
//!!! __declspec(dllexport) и __declspec(dllimport)
//!!! Также нет extern "C".
//!!! Для явного и неявного связывания достаточно использовать один проект dll.


__declspec(dllexport) void SortDyn(int*, int);