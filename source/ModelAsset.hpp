#pragma once

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/gtc/quaternion.hpp>
#include <cstdint>
#include <string>
#include <vector>

struct ModelAsset {
	bool _loaded = false;

public:
	struct Mesh {
		const glm::vec3* positions = nullptr;
		uint32_t positionCount = 0;

		const glm::vec2* texcoords = nullptr;
		uint32_t texcoordCount = 0;

		const glm::vec3* normals = nullptr;
		uint32_t normalCount = 0;

		uint32_t materialIndex = 0;
	};

	struct Node {
		uint32_t parentNodeIndex = 0;
		std::vector<uint32_t> meshIndexes;

		glm::vec3 position;
		glm::quat rotation;
		glm::vec3 scale = { 1, 1, 1 };

		std::string name;
	};

	std::vector<Mesh> meshes;
	std::vector<Node> nodes;
	std::vector<std::string> materials;

	ModelAsset(std::string path);
	bool loaded() const;
};