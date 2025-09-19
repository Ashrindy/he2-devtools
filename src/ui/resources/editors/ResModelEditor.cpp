#include "ResModelEditor.h"
#include <ui/common/editors/Basic.h>
#include <ui/common/Textures.h>
#include <utilities/CompatibleObject.h>

using namespace hh::gfx;
using namespace hh::needle;

ResModelEditor::ResModelEditor(csl::fnd::IAllocator* allocator, ResModel* resource) : StandaloneWindow{ allocator } {
	char namebuf[500];
	snprintf(namebuf, sizeof(namebuf), "%s - %s @ 0x%zx (file mapped @ 0x%zx)", resource->GetName(), resource->GetClass().pName, (size_t)&resource, (size_t)resource);
	SetTitle(namebuf);

	static const char* nameTemplate = "ModelViewport";
	static const size_t nameTemplateLen = strlen(nameTemplate);

	const char* resName = resource->name.c_str();
	const size_t resNameLen = strlen(resName);

	const size_t nameLen = resNameLen + nameTemplateLen + 1;
	char* nameRaw = new (GetAllocator()) char[nameLen];
	snprintf(nameRaw, nameLen, "%s%s", resName, nameTemplate);

	viewport = new (allocator) InteractiveViewport{ allocator };
	viewport->Setup({.name = nameRaw});
	viewport->AddModel(resource, true);

	GetAllocator()->Free(nameRaw);
}

ResModelEditor* ResModelEditor::Create(csl::fnd::IAllocator* allocator, ResModel* resource) {
	return new (allocator) ResModelEditor{ allocator, resource };
}

void ResModelEditor::RenderContents() {
	viewport->Render();
}
