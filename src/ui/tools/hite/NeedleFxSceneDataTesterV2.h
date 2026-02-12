#pragma once
#include <ui/common/StandaloneWindow.h>

class NeedleFxSceneDataTesterV2 : public StandaloneWindow {
	hh::fnd::Reference<hh::fnd::ResReflectionT<hh::needle::NeedleFxSceneData>> resource{};
	bool setConfig{ false };
	bool setParam{ false };
	bool setTimeParam{ false };
	int collectionType{ 0 };
	int itemId{ 0 };
	int timeItemId{ 0 };
	bool timeUseEventCameraControl{ false };
public:
	NeedleFxSceneDataTesterV2(csl::fnd::IAllocator* allocator);
	~NeedleFxSceneDataTesterV2();
	virtual void PreRender() override;
	virtual void RenderContents() override;
};
