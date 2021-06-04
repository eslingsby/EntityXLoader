#pragma once
#include <string>
#include <entityx/Event.h>

class AssetHandler {
	entityx::EventManager& _events;
	const std::string _root;

public:
	AssetHandler(entityx::EventManager& events, std::string root = "") : _root(root), _events(events) { }

	template <typename Asset, typename ...Ts>
	bool load(std::string path, Ts... args) {
		std::string globalPath = _root + path;

		Asset asset(globalPath, args...);

		if (!asset.loaded())
			return false;

		_events.emit<Asset>(asset);
		return true;
	}
};