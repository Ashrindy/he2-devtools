#include "Resources.h"
#ifndef DEVTOOLS_TARGET_SDK_hite
#include <ui/resources/editors/ResFxColFile2Editor.h>
#endif

#if !defined(DEVTOOLS_TARGET_SDK_miller) && !defined(DEVTOOLS_TARGET_SDK_hite)
void Editor(const char* label, app::gfx::ResFxColFile2& obj) {
	if (ImGui::Button("Edit"))
		ResFxColFile2Editor::Create(Desktop::instance->GetAllocator(), &obj);
	ImGui::Text("%s: ResFxColFile2 - %s", label, obj.GetName());
}
#endif
