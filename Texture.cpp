#include "Texture.h"


Texture::Texture(const std::string &tex_path):texture_path_(tex_path)
{
	createTextureBuffer();
	loadTextureFromFile(tex_path);
}

GLint Texture::getIdTexBuffer() const
{
	return tex_buffer_id_;
}


Texture::~Texture()
{
}

std::unique_ptr<Texture> Texture::clone() const
{
	return std::unique_ptr<Texture>(new Texture(this->texture_path_));
}

void Texture::loadTextureFromFile(const std::string &tex_path)
{
	int width, height, nrChannels;
	unsigned char *data = SOIL_load_image(tex_path.c_str(), &width, &height, 0, SOIL_LOAD_RGB);
	if (data == nullptr)
		throw LoadTextureError("Texture::nie mozna zaladowac tekstury z pliku: " + tex_path);
	glBindTexture(GL_TEXTURE_2D, tex_buffer_id_);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(data);
	glBindTexture(GL_TEXTURE_2D, 0);


}
void Texture::createTextureBuffer()
{
	GLuint tex_buf;
	glGenTextures(1,&tex_buf );
	tex_buffer_id_ = tex_buf;
	glBindTexture(GL_TEXTURE_2D, tex_buffer_id_);
	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);
}
