## ======================================================================== ##
## Copyright 2018-2019 Intel Corporation                                    ##
##                                                                          ##
## Licensed under the Apache License, Version 2.0 (the "License");          ##
## you may not use this file except in compliance with the License.         ##
## You may obtain a copy of the License at                                  ##
##                                                                          ##
##     http://www.apache.org/licenses/LICENSE-2.0                           ##
##                                                                          ##
## Unless required by applicable law or agreed to in writing, software      ##
## distributed under the License is distributed on an "AS IS" BASIS,        ##
## WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. ##
## See the License for the specific language governing permissions and      ##
## limitations under the License.                                           ##
## ======================================================================== ##

# prefer libGL over libOpenGl for better compatibility with SWR
set(OpenGL_GL_PREFERENCE "LEGACY")
find_package(OpenGL 2 REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(ospExamples
  ArcballCamera.cpp
  example_util.cpp
  GLFWOSPRayWindow.cpp
  imgui_impl_glfw_gl3.cpp
  ospExample.cpp
)

target_link_libraries(ospExamples PRIVATE
  ospcommon::ospcommon
  ospray
  ospray_testing
  ospray_imgui
  glfw
  ${OPENGL_LIBRARIES}
)

add_executable(ospExampleVolumePT
  ArcballCamera.cpp
  example_util.cpp
  GLFWOSPRayWindow.cpp
  imgui_impl_glfw_gl3.cpp
  ospExampleVolumePT.cpp
)

target_link_libraries(ospExampleVolumePT PRIVATE
  ospcommon::ospcommon
  ospray
  ospray_testing
  ospray_imgui
  glfw
  ${OPENGL_LIBRARIES}
)