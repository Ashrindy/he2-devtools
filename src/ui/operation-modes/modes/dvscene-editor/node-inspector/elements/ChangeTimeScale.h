#pragma once
#include "../Elements.h"

namespace ui::operation_modes::modes::dvscene_editor {
    template<>
    bool RenderElementInspector<hh::dv::DvNodeElement::ElementID::CHANGE_TIME_SCALE>(char* element) {
        bool changed = false;
        auto* data = reinterpret_cast<app::dv::DvElementChangeTimeScale::Data*>(element);
        changed |= Editor("Unk Enabled", data->unkEnabled);
        changed |= Editor("Time Scale", data->timeScale);
        changed |= Editor("Unk1", data->unk1);
        changed |= Editor("Multiplier", data->multiplier);
        return changed;
    }
}
