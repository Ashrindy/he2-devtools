#include "GLMUtils.h"

glm::vec3 EigenToGLM(const Eigen::Vector3f& v) {
	return glm::vec3(v.x(), v.y(), v.z());
}

Eigen::Vector3f GLMToEigen(const glm::vec3& v) {
	return Eigen::Vector3f(v.x, v.y, v.z);
}

glm::quat EigenToGLM(const Eigen::Quaternionf& q) {
	return glm::quat(q.w(), q.x(), q.y(), q.z());
}

Eigen::Quaternionf GLMToEigen(const glm::quat& q) {
	return Eigen::Quaternionf(q.w, q.x, q.y, q.z);
}
