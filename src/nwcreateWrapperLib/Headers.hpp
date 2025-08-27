#pragma once

//system
#include "string"

//nwcreate
#include "nwcreate/LiNwcAll.h"

#ifdef _EXPORTING
#define NWCREATE_SWIG_API __declspec(dllexport)
#else
#define NWCREATE_SWIG_API __declspec(dllimport)
#endif