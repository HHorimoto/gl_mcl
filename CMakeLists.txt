cmake_minimum_required(VERSION 3.0.2)
project(gl_mcl)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  geometry_msgs
  tf2
  tf2_ros
)

catkin_package()

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_library(ParticleFilter src/ParticleFilter.cpp)
add_library(Particle src/Particle.cpp)
add_library(OdomModel src/OdomModel.cpp)
add_library(Pose src/Pose.cpp)
add_library(LikelihoodFieldMap src/LikelihoodFieldMap.cpp)

add_executable(${PROJECT_NAME}_node src/gl_mcl_node.cpp)

add_dependencies(${PROJECT_NAME}_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(${PROJECT_NAME}_node
	ParticleFilter
	Particle
	Pose
	OdomModel
	LikelihoodFieldMap
	${catkin_LIBRARIES})