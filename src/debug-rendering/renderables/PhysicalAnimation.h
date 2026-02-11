#pragma once
#if !defined(DEVTOOLS_TARGET_SDK_wars) && !defined(DEVTOOLS_TARGET_SDK_hite)
#include <debug-rendering/DebugRenderable.h>

namespace devtools::debug_rendering::renderables {
	class PhysicalAnimation : public OptionalDebugRenderable {
	public:
		bool enabled{};

		virtual void RenderIngameDebugVisuals(hh::gfnd::DrawContext& ctx) override;
		virtual void RenderImGuiDebugVisuals(const ImGuiDrawContext& ctx) override;
	};
}
#endif
