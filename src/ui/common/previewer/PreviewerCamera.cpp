#include "PreviewerCamera.h"
#include <utilities/math/MathUtils.h>
#define IMVIEWGUIZMO_IMPLEMENTATION
#include <ImViewGuizmo.h>

PreviewerCamera::~PreviewerCamera()
{
}

PreviewerCamera::PreviewerCamera(csl::fnd::IAllocator* allocator) : CompatibleObject{ allocator }
{
}

void PreviewerCamera::Setup(Previewer* previewer)
{
	this->previewer = previewer;
	viewportData = previewer->viewportData;
}

bool PreviewerCamera::RotateControl(csl::math::Vector3& position, csl::math::Quaternion& rotation) const
{
	glm::vec3 camPos = EigenToGLM(position);
	glm::quat camRot = EigenToGLM(rotation);

	const ImVec2 guizmoHRes = ImVec2{ 80, 80 } * ImViewGuizmo::GetStyle().scale;

	ImVec2 guizmoPos = 
		ImGui::GetWindowContentRegionMin() + ImGui::GetWindowPos() + // base position
		ImVec2{ viewportData.viewportDimensions.resX - guizmoHRes.x, guizmoHRes.y }; // offset position

	// dirty hack to stop the window from moving
	ImVec2 invisPos = guizmoPos - guizmoHRes;
	ImVec2 invisSize = guizmoHRes * 2;
	ImGui::SetCursorScreenPos(invisPos);
	ImGui::InvisibleButton("unmovable", invisSize);
	
	bool changed = false;

	if (changed |= ImViewGuizmo::Rotate(camPos, camRot, guizmoPos, previewer->GetZoomToAABB(), controlSpeed)) {
		position = GLMToEigen(camPos);
		rotation = GLMToEigen(camRot);
	}

	return changed;
}

void PreviewerCamera::Render()
{
	auto& viewMatrix = viewportData.viewMatrix;

	csl::math::Vector3 camPos = viewMatrix.translation();
	csl::math::Quaternion camRot{ viewMatrix.rotation() };

	if (RotateControl(camPos, camRot))
		UpdateViewMatrix(camPos, camRot);
}

void PreviewerCamera::UpdateViewMatrix(const csl::math::Vector3& position, const csl::math::Quaternion& rotation)
{
	auto& viewMatrix = viewportData.viewMatrix;
	viewMatrix.linear() = rotation.toRotationMatrix();
	viewMatrix.translation() = position;
	viewportData.viewMatrix = viewMatrix;

	if (previewer) {
		previewer->SetViewMatrix(viewMatrix);
		previewer->UpdateViewMatrix();
	}
}
