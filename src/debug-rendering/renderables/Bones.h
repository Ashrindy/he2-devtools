#pragma once
#include <debug-rendering/DebugRenderable.h>

#ifndef DEVTOOLS_TARGET_SDK_hite
namespace devtools::debug_rendering::renderables {
	class Bones : public OptionalDebugRenderable {
	public:
		csl::ut::MoveArray<hh::gfnd::DrawVertex> xs{ hh::fnd::MemoryRouter::GetModuleAllocator() };
		csl::ut::MoveArray<hh::gfnd::DrawVertex> ys{ hh::fnd::MemoryRouter::GetModuleAllocator() };
		csl::ut::MoveArray<hh::gfnd::DrawVertex> zs{ hh::fnd::MemoryRouter::GetModuleAllocator() };
		csl::ut::MoveArray<unsigned short> indices{ hh::fnd::MemoryRouter::GetModuleAllocator() };

		bool enabled{};

		virtual void RenderIngameDebugVisuals(hh::gfnd::DrawContext& ctx) override;
		virtual void RenderImGuiDebugVisuals(const ImGuiDrawContext& ctx) override;
	};
}
#endif
