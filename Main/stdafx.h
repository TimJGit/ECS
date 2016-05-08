#pragma once

using namespace std;

#define _CRTDBG_MAP_ALLOC
#define _USE_MATH_DEFINES

#include <stdlib.h>
#include <crtdbg.h>

#include <algorithm>
#include <iostream>
#include <math.h>
#include <sstream>
#include <unordered_set>
#include <vector>
#include <Windows.h>

#include "../Components/ComponentIDs.h"
#include "../Helpers/Enums.h"
#include "../Helpers/Exceptions.h"
#include "../Helpers/Timer.h"
#include "../Helpers/Vector3.h"
#include "../Interfaces/IComponent.h"
#include "../Interfaces/IExecuteSystem.h"
#include "../Interfaces/IInitializeSystem.h"
#include "../Interfaces/INotifiable.h"
#include "../Interfaces/IReactiveSystem.h"
#include "../Interfaces/ISystem.h"
