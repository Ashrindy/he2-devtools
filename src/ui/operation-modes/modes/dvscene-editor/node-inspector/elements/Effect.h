#pragma once
#include "../Elements.h"

namespace ui::operation_modes::modes::dvscene_editor {
    const char* transTypeNames[] = {
        "NODE",
        "NODE_AND_FRAME",
        "NODE_POSITION"
    };

    template<>
    bool RenderElementInspector<hh::dv::DvNodeElement::ElementID::EFFECT>(char* element) {
        bool changed = false;
        auto* data = reinterpret_cast<hh::dv::DvElementEffect::Data*>(element);
        csl::math::Transform transform = Affine3fToTransform(Eigen::Affine3f{ data->effectMatrix.matrix() });
        if (changed |= Editor("Effect Transform", transform))
            data->effectMatrix = Eigen::Affine3f{ TransformToAffine3f(transform) };
        changed |= Editor("Effect Name", data->effectName);
        changed |= CheckboxFlags("Unk0", data->flags, hh::dv::DvElementEffect::Data::Flags::UNK0);
        changed |= CheckboxFlags("Quaternion", data->flags, hh::dv::DvElementEffect::Data::Flags::QUATERNION);
        changed |= CheckboxFlags("Unk1", data->flags, hh::dv::DvElementEffect::Data::Flags::UNK1);
        changed |= CheckboxFlags("Model Space Node", data->flags, hh::dv::DvElementEffect::Data::Flags::MODEL_SPACE_NODE);
        changed |= Editor("Eff Create Info Unk1a", data->effCreateInfoUnk1A);
        changed |= CheckboxFlags("Unk0 flags2", data->flags2, hh::dv::DvElementEffect::Data::Flags2::UNK0);
        changed |= CheckboxFlags("Persistent", data->flags2, hh::dv::DvElementEffect::Data::Flags2::PERSISTENT);
        unsigned char color[4] = { data->r, data->g, data->b, data->a };
        changed |= ColorEditor("Effect Color", color);
        changed |= Editor("Eff Create Info Unk5a", data->effCreateInfoUnk5A);
        changed |= Editor("Eff Create Info Unk5", data->effCreateInfoUnk5);
        changed |= ComboEnum("Eff Trans Type", data->effTransType, transTypeNames);
        changed |= Editor("Unk7", data->unk7);
        changed |= Editor("Unk8", data->unk8);
        return changed;
    }
}
