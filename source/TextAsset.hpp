#pragma once
#include <string>

class TextAsset {
	bool _loaded = false;

public:
	std::string text = "";

	TextAsset(std::string path);
	bool loaded() const;
};