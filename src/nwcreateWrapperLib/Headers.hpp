#pragma once

//system
#include "string"

//nwcreate
#include "nwcreate/LiNwcAll.h"

#ifdef _EXPORTING
#define CLASS_DECLSPEC __declspec(dllexport)
#else
#define CLASS_DECLSPEC __declspec(dllimport)
#endif