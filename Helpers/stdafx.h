#pragma once

using namespace std;

#define _CRTDBG_MAP_ALLOC
#define _USE_MATH_DEFINES

#include <stdlib.h>
#include <crtdbg.h>

#include <algorithm>
#include <functional>
#include <iostream>
#include <math.h>
#include <sstream>
#include <unordered_set>
#include <vector>
#include <Windows.h>

#include "Enums.h"
#include "Exceptions.h"
#include "Vector3.h"
#include "../Components/ComponentIDs.h"
#include "../Interfaces/IComponent.h"
#include "../Interfaces/INotifiable.h"
#include "../Interfaces/ISystem.h"
#include "../Interfaces/IInitializeSystem.h"
#include "../Interfaces/IReactiveSystem.h"
#include "../Interfaces/IExecuteSystem.h"
