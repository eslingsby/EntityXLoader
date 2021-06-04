#pragma once
#include <entityx/System.h>
#include <entityx/Event.h>
#include <cstdint>
#include <iostream>
#include <entityx\entityx.h>
#include <filesystem>

#include "AssetHandler.hpp"
#include "TextAsset.hpp"
#include "ModelAsset.hpp"

class ModelEvent : public ModelAsset{
public:
	const std::string path;
	entityx::EntityManager& entities;
	entityx::Entity entity;
	const bool collider;
	const bool render;

	ModelEvent(std::string path, entityx::EntityManager* entities, entityx::Entity entity, bool collider = false, bool render = false) : ModelAsset(path), entities(*entities), path(path), entity(entity), collider(collider), render(render) { }
};

class MySystem : public entityx::System<MySystem>, public entityx::Receiver<MySystem> {
	AssetHandler& _assetHandler;

public:
	MySystem(AssetHandler& assetHandler) : _assetHandler(assetHandler) {	};

	void configure(entityx::EventManager& events) final {
		events.subscribe<TextAsset>(*this);
		events.subscribe<ModelEvent>(*this);
	}

	void update(entityx::EntityManager& entities, entityx::EventManager& events, double dt) final {
		entityx::Entity entity = entities.create();

		_assetHandler.load<TextAsset>("test.txt");
		_assetHandler.load<ModelEvent>("triangle_room.fbx", &entities, entity, true, false);
	}

	void receive(const TextAsset& textAsset) {
		std::cout << textAsset.text << std::endl;
	}

	void receive(const ModelEvent& modelEvent) {
		std::cout << "Model recieved" << std::endl;
	}
};

class Engine : public entityx::EntityX {
	AssetHandler _assetLoader;
	bool _running = true;

	static std::string _root(std::string path) {
		std::filesystem::path root(path);

		root.remove_filename();
		return root.string();
	}

public:
	Engine::Engine(int argc, char** argv) : _assetLoader(events, _root(argv[0]) + "data/") {
		systems.add<MySystem>(_assetLoader);

		systems.configure();
	}

	void update(double dt) {
		systems.update_all(dt);
	}

	const bool running() {
		return _running;
	}
};