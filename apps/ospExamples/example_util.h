// ======================================================================== //
// Copyright 2018-2019 Intel Corporation                                    //
//                                                                          //
// Licensed under the Apache License, Version 2.0 (the "License");          //
// you may not use this file except in compliance with the License.         //
// You may obtain a copy of the License at                                  //
//                                                                          //
//     http://www.apache.org/licenses/LICENSE-2.0                           //
//                                                                          //
// Unless required by applicable law or agreed to in writing, software      //
// distributed under the License is distributed on an "AS IS" BASIS,        //
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. //
// See the License for the specific language governing permissions and      //
// limitations under the License.                                           //
// ======================================================================== //

#pragma once

// ospray
#include "ospray/ospray_util.h"
// ospcommon
#include "ospcommon/math/box.h"
#include "ospcommon/math/vec.h"
using namespace ospcommon::math;
// std
#include <string>

void initializeOSPRay(int argc, const char **argv, bool errorsFatal = true);

OSPInstance createGroundPlane(std::string renderer_type,
                              float planeExtent = 1.5f);