#pragma once
#include "../Elements.h"

namespace ui::operation_modes::modes::dvscene_editor {
    const char* fanimationTypeNames[] = {
        "SKELETAL_ANIMATION",
        "UV_ANIMATION",
        "VISIBILITY_ANIMATION",
        "MATERIAL_ANIMATION",
    };

    template<>
#ifdef DEVTOOLS_TARGET_SDK_rangers
    bool RenderElementInspector<1025>(char* element) {
#elif DEVTOOLS_TARGET_SDK_miller
    bool RenderElementInspector<1027>(char* element) {
#endif
        bool changed = false;
        auto* data = reinterpret_cast<app::dv::DvElementFacialAnimation::Data*>(element);
		if(ImGui::TreeNode("Animations")) {
            char z = 0;
            for(auto i = 0; i < data->activeAnimationsCount; i++){
                auto& x = data->animations[i];
                char buffer[68];
                snprintf(buffer, sizeof(buffer), "%s##%s", x.fileName, z);
                if(ImGui::TreeNode(buffer)){
                    int curAnmType = static_cast<int>(x.animType)-1;
                    if (changed |= ImGui::Combo("Animation Type", &curAnmType, fanimationTypeNames, 4))
                        x.animType = static_cast<app::dv::DvElementFacialAnimation::Data::Animation::AnimationType>(curAnmType+1);
                    changed |= Editor("Filename", x.fileName);
                    ImGui::TreePop();
                }
                z++;
            }
            ImGui::TreePop();
        }
        if(Editor("Active Animation Count", data->activeAnimationsCount)) {
            changed |= true;
            if(data->activeAnimationsCount > 3)
                data->activeAnimationsCount = 3;
            else if(data->activeAnimationsCount < 0)
                data->activeAnimationsCount = 0;
        }
        return changed;
    }
}
