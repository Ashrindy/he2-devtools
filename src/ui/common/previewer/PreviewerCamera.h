#pragma once
#include <utilities/CompatibleObject.h>
#include <ui/common/previewer/Previewer.h>

class PreviewerCamera : public CompatibleObject {
public:
	Previewer* previewer;
	hh::gfnd::ViewportData viewportData;
	float controlSpeed = 0.015f;
	
	PreviewerCamera(csl::fnd::IAllocator* allocator);

	void Setup(Previewer* previewer);

	bool RotateControl(csl::math::Vector3& position, csl::math::Quaternion& rotation) const;
	void Render();
	void UpdateViewMatrix(const csl::math::Vector3& position, const csl::math::Quaternion& rotation);
};
