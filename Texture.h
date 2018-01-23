#pragma once
#include "LoadTextureError.h"
#include"OpenGlWindow.h"
#include <memory>
class Texture
{
public:
	Texture(const std::string &tex_path);

	GLint getIdTexBuffer()const;
	virtual ~Texture();
	virtual std::unique_ptr<Texture> clone()const;
	std::string getTexturePath()const;
protected:
	GLint tex_buffer_id_;
	std::string texture_path_;

	void loadTextureFromFile(const std::string &tex_path);
	void createTextureBuffer();
};

