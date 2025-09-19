#pragma once
#include <utilities/CompatibleObject.h>
#include <ui/common/viewport/Viewport.h>

class InteractiveViewport : public Viewport {
public:
	float controlSpeed{ 0.015f };
	
	InteractiveViewport(csl::fnd::IAllocator* allocator);

	bool RotateControl(csl::math::Vector3& position, csl::math::Quaternion& rotation) const;
	virtual void Render() override;
	void UpdateMatrix(const csl::math::Vector3& position, const csl::math::Quaternion& rotation);
};
