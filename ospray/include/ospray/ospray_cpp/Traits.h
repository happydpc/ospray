// ======================================================================== //
// Copyright 2009-2019 Intel Corporation                                    //
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
#include "ospray/ospray.h"
// ospcommon
#include "ospcommon/math/AffineSpace.h"
#include "ospcommon/math/box.h"
#include "ospcommon/math/vec.h"

namespace ospray {

// Infer (compile time) OSP_DATA_TYPE from input type /////////////////////

template <typename T>
struct OSPTypeFor
{
  static constexpr OSPDataType value = OSP_UNKNOWN;
};

#define OSPTYPEFOR_SPECIALIZATION(type, osp_type)                              \
  template <>                                                                  \
  struct OSPTypeFor<type>                                                      \
  {                                                                            \
    static constexpr OSPDataType value = osp_type;                             \
  };

OSPTYPEFOR_SPECIALIZATION(void *, OSP_VOID_PTR);
OSPTYPEFOR_SPECIALIZATION(char *, OSP_STRING);
OSPTYPEFOR_SPECIALIZATION(const char *, OSP_STRING);
OSPTYPEFOR_SPECIALIZATION(const char[], OSP_STRING);
OSPTYPEFOR_SPECIALIZATION(bool, OSP_BOOL);
OSPTYPEFOR_SPECIALIZATION(char, OSP_CHAR);
OSPTYPEFOR_SPECIALIZATION(unsigned char, OSP_UCHAR);
OSPTYPEFOR_SPECIALIZATION(ospcommon::math::vec2uc, OSP_VEC2UC);
OSPTYPEFOR_SPECIALIZATION(ospcommon::math::vec3uc, OSP_VEC3UC);
OSPTYPEFOR_SPECIALIZATION(ospcommon::math::vec4uc, OSP_VEC4UC);
OSPTYPEFOR_SPECIALIZATION(short, OSP_SHORT);
OSPTYPEFOR_SPECIALIZATION(unsigned short, OSP_USHORT);
OSPTYPEFOR_SPECIALIZATION(int32_t, OSP_INT);
OSPTYPEFOR_SPECIALIZATION(ospcommon::math::vec2i, OSP_VEC2I);
OSPTYPEFOR_SPECIALIZATION(ospcommon::math::vec3i, OSP_VEC3I);
OSPTYPEFOR_SPECIALIZATION(ospcommon::math::vec4i, OSP_VEC4I);
OSPTYPEFOR_SPECIALIZATION(uint32_t, OSP_UINT);
OSPTYPEFOR_SPECIALIZATION(ospcommon::math::vec2ui, OSP_VEC2UI);
OSPTYPEFOR_SPECIALIZATION(ospcommon::math::vec3ui, OSP_VEC3UI);
OSPTYPEFOR_SPECIALIZATION(ospcommon::math::vec4ui, OSP_VEC4UI);
OSPTYPEFOR_SPECIALIZATION(int64_t, OSP_LONG);
OSPTYPEFOR_SPECIALIZATION(ospcommon::math::vec2l, OSP_VEC2L);
OSPTYPEFOR_SPECIALIZATION(ospcommon::math::vec3l, OSP_VEC3L);
OSPTYPEFOR_SPECIALIZATION(ospcommon::math::vec4l, OSP_VEC4L);
OSPTYPEFOR_SPECIALIZATION(uint64_t, OSP_ULONG);
OSPTYPEFOR_SPECIALIZATION(ospcommon::math::vec2ul, OSP_VEC2UL);
OSPTYPEFOR_SPECIALIZATION(ospcommon::math::vec3ul, OSP_VEC3UL);
OSPTYPEFOR_SPECIALIZATION(ospcommon::math::vec4ul, OSP_VEC4UL);
OSPTYPEFOR_SPECIALIZATION(float, OSP_FLOAT);
OSPTYPEFOR_SPECIALIZATION(ospcommon::math::vec2f, OSP_VEC2F);
OSPTYPEFOR_SPECIALIZATION(ospcommon::math::vec3f, OSP_VEC3F);
OSPTYPEFOR_SPECIALIZATION(ospcommon::math::vec4f, OSP_VEC4F);
OSPTYPEFOR_SPECIALIZATION(double, OSP_DOUBLE);
OSPTYPEFOR_SPECIALIZATION(ospcommon::math::box1i, OSP_BOX1I);
OSPTYPEFOR_SPECIALIZATION(ospcommon::math::box2i, OSP_BOX2I);
OSPTYPEFOR_SPECIALIZATION(ospcommon::math::box3i, OSP_BOX3I);
OSPTYPEFOR_SPECIALIZATION(ospcommon::math::box4i, OSP_BOX4I);
OSPTYPEFOR_SPECIALIZATION(ospcommon::math::box1f, OSP_BOX1F);
OSPTYPEFOR_SPECIALIZATION(ospcommon::math::box2f, OSP_BOX2F);
OSPTYPEFOR_SPECIALIZATION(ospcommon::math::box3f, OSP_BOX3F);
OSPTYPEFOR_SPECIALIZATION(ospcommon::math::box4f, OSP_BOX4F);
OSPTYPEFOR_SPECIALIZATION(ospcommon::math::linear2f, OSP_LINEAR2F);
OSPTYPEFOR_SPECIALIZATION(ospcommon::math::linear3f, OSP_LINEAR3F);
OSPTYPEFOR_SPECIALIZATION(ospcommon::math::affine2f, OSP_AFFINE2F);
OSPTYPEFOR_SPECIALIZATION(ospcommon::math::affine3f, OSP_AFFINE3F);

OSPTYPEFOR_SPECIALIZATION(OSPObject, OSP_OBJECT);
OSPTYPEFOR_SPECIALIZATION(OSPCamera, OSP_CAMERA);
OSPTYPEFOR_SPECIALIZATION(OSPData, OSP_DATA);
OSPTYPEFOR_SPECIALIZATION(OSPFrameBuffer, OSP_FRAMEBUFFER);
OSPTYPEFOR_SPECIALIZATION(OSPFuture, OSP_FUTURE);
OSPTYPEFOR_SPECIALIZATION(OSPGeometricModel, OSP_GEOMETRIC_MODEL);
OSPTYPEFOR_SPECIALIZATION(OSPGeometry, OSP_GEOMETRY);
OSPTYPEFOR_SPECIALIZATION(OSPGroup, OSP_GROUP);
OSPTYPEFOR_SPECIALIZATION(OSPImageOperation, OSP_IMAGE_OPERATION);
OSPTYPEFOR_SPECIALIZATION(OSPInstance, OSP_INSTANCE);
OSPTYPEFOR_SPECIALIZATION(OSPLight, OSP_LIGHT);
OSPTYPEFOR_SPECIALIZATION(OSPMaterial, OSP_MATERIAL);
OSPTYPEFOR_SPECIALIZATION(OSPRenderer, OSP_RENDERER);
OSPTYPEFOR_SPECIALIZATION(OSPTexture, OSP_TEXTURE);
OSPTYPEFOR_SPECIALIZATION(OSPTransferFunction, OSP_TRANSFER_FUNCTION);
OSPTYPEFOR_SPECIALIZATION(OSPVolume, OSP_VOLUME);
OSPTYPEFOR_SPECIALIZATION(OSPVolumetricModel, OSP_VOLUMETRIC_MODEL);
OSPTYPEFOR_SPECIALIZATION(OSPWorld, OSP_WORLD);

} // namespace ospray
