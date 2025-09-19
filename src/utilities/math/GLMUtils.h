#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

glm::vec3 EigenToGLM(const Eigen::Vector3f& v);
Eigen::Vector3f GLMToEigen(const glm::vec3& v);
glm::quat EigenToGLM(const Eigen::Quaternionf& q);
Eigen::Quaternionf GLMToEigen(const glm::quat& q);
