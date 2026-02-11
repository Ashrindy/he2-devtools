#include <ui/resources/editors/ResReflectionEditor.h>
#include <ui/Desktop.h>

template<typename T>
void Editor(const char* label, hh::fnd::ResReflectionT<T>& obj) {
	if (ImGui::Button("Edit"))
		ResReflectionEditor::Create(Desktop::instance->GetAllocator(), obj);
	ImGui::Text("%s: ResReflection - %s", label, obj->GetName());
}

#if !defined(DEVTOOLS_TARGET_SDK_miller) && !defined(DEVTOOLS_TARGET_SDK_hite)
void Editor(const char* label, app::gfx::ResFxColFile2& obj);
#endif

