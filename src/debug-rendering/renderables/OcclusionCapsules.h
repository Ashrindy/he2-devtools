#pragma once
#include <debug-rendering/DebugRenderable.h>

#ifndef DEVTOOLS_TARGET_SDK_hite
namespace devtools::debug_rendering::renderables {
	class OcclusionCapsules : public OptionalDebugRenderable {
	public:
		bool enabled{};

		virtual void RenderIngameDebugVisuals(hh::gfnd::DrawContext& ctx) override;
	};
}
#endif
