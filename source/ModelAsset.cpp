#include "ModelAsset.hpp"

#include <assimp\Importer.hpp>
#include <assimp\scene.h>
#include <assimp\postprocess.h>

void fromAssimp(const aiVector3D& from, glm::vec2* to) {
	to->x = from.x;
	to->y = from.y;
}

void fromAssimp(const aiVector3D& from, glm::vec3* to) {
	to->x = from.x;
	to->y = from.y;
	to->z = from.z;
}

void fromAssimp(const aiQuaternion& from, glm::quat* to) {
	to->w = from.w;
	to->x = from.x;
	to->y = from.y;
	to->z = from.z;
}

uint32_t recusriveBufferMesh(const aiScene& scene, const aiNode& node, ModelAsset* meshHierarchy, uint32_t parentNode = 0, uint32_t nodeCounter = 0) {
	uint32_t currentNode = nodeCounter;
	ModelAsset::Node& meshNode = meshHierarchy->nodes[nodeCounter];

	aiVector3D position, scale;
	aiQuaternion rotation;
	node.mTransformation.Decompose(scale, rotation, position);

	fromAssimp(position, &meshNode.position);
	fromAssimp(rotation, &meshNode.rotation);
	fromAssimp(scale, &meshNode.scale);

	meshNode.parentNodeIndex = parentNode;

	//if (node.mNumMeshes) {
	//	meshNode.name = node.mName.C_Str();

		//meshNode.hasMesh = true;
		//meshNode.meshIndex = node.mMeshes[0];
	//}

	for (uint32_t i = 0; i < node.mNumChildren; i++)
		nodeCounter = recusriveBufferMesh(scene, *node.mChildren[i], meshHierarchy, currentNode, nodeCounter + 1);

	return nodeCounter;
}

uint32_t recursirveNodeCount(const aiNode& node, uint32_t count = 0) {
	for (uint32_t i = 0; i < node.mNumChildren; i++)
		count = recursirveNodeCount(*node.mChildren[i], count);

	return count + 1;
}

ModelAsset::ModelAsset(std::string path) {
	Assimp::Importer importer;

	const aiScene* scene = importer.ReadFile(path, aiProcessPreset_TargetRealtime_MaxQuality);

	if (!scene)
		return;

	meshes.resize(scene->mNumMeshes);
	nodes.resize(recursirveNodeCount(*scene->mRootNode));

	recusriveBufferMesh(*scene, *scene->mRootNode, this);

	_loaded = true;
}

bool ModelAsset::loaded() const {
	return _loaded;
}