#include "TextAsset.hpp"
#include <fstream>

TextAsset::TextAsset(std::string path) {
	std::ifstream file(path);

	if (!file.is_open())
		return;

	text = std::string(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
	_loaded = true;
}

bool TextAsset::loaded() const {
	return _loaded;
}