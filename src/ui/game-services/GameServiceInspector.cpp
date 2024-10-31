#include "GameServiceInspector.h"
#include <imgui_internal.h>
#include <ui/Desktop.h>

#ifdef DEVTOOLS_TARGET_SDK_wars
#include "game-service-inspectors/FxParamManager.h"
#include "game-service-inspectors/ObjectWorld.h"
#include "game-service-inspectors/StageInfo.h"
#include "game-service-inspectors/CameraManager.h"

typedef std::tuple<
	app::gfx::FxParamManager,
	hh::game::ObjectWorld,
	app::level::StageInfo,
	hh::game::CameraManager
> InspectableServices;
#endif

#ifdef DEVTOOLS_TARGET_SDK_rangers
#include "game-service-inspectors/FxParamManager.h"
#include "game-service-inspectors/ObjectWorld.h"
#include "game-service-inspectors/StageInfo.h"
#include "game-service-inspectors/LevelInfo.h"
#include "game-service-inspectors/PathManager.h"
#include "game-service-inspectors/CameraManager.h"
#include "game-service-inspectors/CameraService.h"
#include "game-service-inspectors/GameModeResourceManager.h"
#include "game-service-inspectors/TerrainManager.h"
#include "game-service-inspectors/SoundDirector.h"
#include "game-service-inspectors/FxColManager.h"
#include "game-service-inspectors/rangers/TimeService.h"
#include "game-service-inspectors/rangers/RespawnTimeManager.h"
#include "game-service-inspectors/rangers/MonologueService.h"

typedef std::tuple<
	app::gfx::FxParamManager,
	hh::game::ObjectWorld,
	app::level::StageInfo,
	app::level::LevelInfo,
	hh::path::PathManager,
	hh::game::CameraManager,
	app::camera::CameraService,
	app::game::GameModeResourceManager,
	app::trr::TerrainManager,
	app::snd::SoundDirector,
	app::game::TimeService,
	app::game::RespawnTimeManager,
	app::gfx::FxColManager,
	app::game::MonologueService
> InspectableServices;

#endif

#ifdef DEVTOOLS_TARGET_SDK_miller
#include "game-service-inspectors/FxParamManager.h"
#include "game-service-inspectors/StageInfo.h"
#include "game-service-inspectors/LevelInfo.h"

typedef std::tuple<
	app::gfx::FxParamManager,
	app::level::StageInfo,
	app::level::LevelInfo
> InspectableServices;
#endif

template<typename T>
bool RenderServiceInspector(hh::game::GameService& service) {
	bool result{ service.staticClass == T::GetClass() };
	
	if (result) {
		ImGui::PushID(&service);
		RenderGameServiceInspector(static_cast<T&>(service));
		ImGui::PopID();
	}

	return result;
}

template<typename = InspectableServices>
class ServiceIterator;
template<typename... T>
class ServiceIterator<std::tuple<T...>> {
public:
	static void Render(hh::game::GameService& service) {
		(RenderServiceInspector<T>(service) || ...) || (ImGui::Text("Inspector for this service not yet implemented"), true);
	}
};

using namespace hh::game;

GameServiceInspector::GameServiceInspector(csl::fnd::IAllocator* allocator) : StandaloneWindow{ allocator } {
	SetTitle("GameService inspector");
}

void GameServiceInspector::RenderContents() {
	auto* gameManager = GameManager::GetInstance();

	for (auto* service : gameManager->GetServices()) {
		ImGui::PushID(service);
		if (ImGui::CollapsingHeader(service->staticClass->name))
			ServiceIterator<>::Render(*service);
		ImGui::PopID();
	}
}
