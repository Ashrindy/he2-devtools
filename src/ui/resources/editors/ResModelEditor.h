#pragma once
#include <ui/common/StandaloneWindow.h>
#include <ui/common/viewport/InteractiveViewport.h>

class ResModelEditor : public StandaloneWindow {
public:
	hh::fnd::Reference<InteractiveViewport> viewport;

	ResModelEditor(csl::fnd::IAllocator* allocator, hh::gfx::ResModel* resource);
	virtual void RenderContents();
	static ResModelEditor* Create(csl::fnd::IAllocator* allocator, hh::gfx::ResModel* resource);
};
