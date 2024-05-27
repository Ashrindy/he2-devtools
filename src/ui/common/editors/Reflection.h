#pragma once

inline float rflMinFloatStep{ 0.01f };
inline unsigned int rflSliderCutOff{ 3000 };

bool ReflectionEditor(const char* label, void* reflectionData, const hh::fnd::RflClass* rflClass);

template<typename T, typename = decltype(T::rflClass)>
static bool Editor(const char* label, T& reflectionData) {
    return ReflectionEditor(label, &reflectionData, &RESOLVE_STATIC_VARIABLE(T::rflClass));
}

bool ResettableReflectionEditor(const char* label, void* reflectionData, void* originalReflectionData, const hh::fnd::RflClass* rflClass);

template<typename T, typename = decltype(T::rflClass)>
static bool Editor(const char* label, T& reflectionData, T& originalReflectionData) {
    return ResettableReflectionEditor(label, &reflectionData, originalReflectionData, &RESOLVE_STATIC_VARIABLE(T::rflClass));
}
