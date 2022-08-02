// Framework.h
#pragma once

#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;


typedef unsigned int uint;

#include "Pet.h" 
// Pet헤더파일을 위에선언하지 않고 가장 아래에 선언해서
// 위에 헤더파일들을 전부 Pet.h에서도 사용할 수  있다.
#include "GameManager.h"