#pragma once
#include "Ray.h"
#include "Frustum.h"

Eigen::Quaternionf EulerToQuat(const Eigen::Vector3f& vec);
Eigen::Vector3f MatrixToEuler(const Eigen::Matrix3f& mat);
Eigen::Affine3f TransformToAffine3f(const csl::math::Transform& transform);
csl::math::Transform Affine3fToTransform(const Eigen::Affine3f& transform);
Ray3f ScreenPosToWorldRay(const ImVec2 screenPos, const Eigen::Matrix4f& inverseCameraMatrix);
Frustum ScreenRectToFrustum(const ImVec2& screenRect1, const ImVec2& screenRect2, const Eigen::Matrix4f inverseCameraMatrix);

Eigen::Vector2f ImGuiCoordsToNDC(const ImVec2& coords);
ImVec2 NDCCoordsToImGui(const Eigen::Vector2f& coords);
