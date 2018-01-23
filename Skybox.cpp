#include "Skybox.h"



GLuint Skybox::loadSkyboxTextureFromFiles(const std::vector<std::string>& paths)
{
	if (paths.size() != 6)//tyle ma skybox tekstur
		throw std::logic_error("Skybox: Zla ilosc sciezek tekstur. Powinno byc 6, jest: " + 6);
	glGenTextures(1, &texture_id_);
	glBindTexture(GL_TEXTURE_CUBE_MAP, texture_id_);

	int width, height;
	paths_ = paths;
	int i = 0;
	int ret;
	while (ret = glGetError() != GL_NO_ERROR)
	{
		std::cout << "ERROR_GL:" << ret << std::endl;
	}
	for (auto &path: paths)
	{
		unsigned char *data = SOIL_load_image(path.c_str(), &width, &height, 0, SOIL_LOAD_RGB);
		if (data == nullptr)
			throw LoadTextureError("Skybox::nie mozna zaladowac tekstury z pliku: " + path);
		
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

		while (ret = glGetError() != GL_NO_ERROR)
		{
			std::cout<<"ERR020OR_GL:" << ret << std::endl;
		}
		++i;//zeby przejsc na kolejny fragment skyboxa
		SOIL_free_image_data(data);
		data = nullptr;
	}
	
	/*
	texture_id_ = SOIL_load_OGL_cubemap
	(
		paths[0].c_str(),
		paths[1].c_str(),
		paths[2].c_str(),
		paths[3].c_str(),
		paths[4].c_str(),
		paths[5].c_str(),
		0,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS
	);
	if (texture_id_ == 0)
		throw LoadTextureError("Skybox::nie mozna zaladowac tekstury z jednego z plikow: " + paths[0] + paths[1]+ paths[2]+ paths[3]+ paths[4]+ paths[5]);
	*/
//	glBindTexture(GL_TEXTURE_CUBE_MAP, texture_id_);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
	return texture_id_;
}

void Skybox::initBuffers()
{
	glGenVertexArrays(1, &VAO_);
	glGenBuffers(1, &VBO_);
	glBindBuffer(GL_ARRAY_BUFFER, VBO_);
	glBindVertexArray(VAO_);
	glBufferData(GL_ARRAY_BUFFER, verts_.size() * sizeof(float), &verts_[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float), (GLvoid*)0);
	glBindVertexArray(0);
}



Skybox::Skybox(const std::vector<std::string>& paths):skybox_shader_(SKYBOX_VERTEX_SHADER, SKYBOX_FRAGMENT_SHADER)
{
	loadSkyboxTextureFromFiles(paths);
	initBuffers();
}

Skybox::Skybox(const Skybox & other):skybox_shader_(other.skybox_shader_.GetShaderId())
{
	texture_id_ = other.texture_id_;
	initBuffers();
}

Skybox & Skybox::operator=(const Skybox & other)
{
	if (&other == this)
		return *this;
	texture_id_ = other.texture_id_;
	return *this;
}

void Skybox::draw(const glm::mat4 &projection, const glm::mat4 &view) const
{
	glm::mat3 view_truncated = static_cast<glm::mat3>(view);
	glm::mat4 view_final (view_truncated);

	glDepthMask(GL_FALSE);
	skybox_shader_.Use();
	GLuint view_id =  glGetUniformLocation(skybox_shader_.GetShaderId(), "view");
	glUniformMatrix4fv(view_id, 1, GL_FALSE, glm::value_ptr(view_final));
	GLuint projection_id = glGetUniformLocation(skybox_shader_.GetShaderId(), "projection");
	glUniformMatrix4fv(projection_id, 1, GL_FALSE, glm::value_ptr(projection));
	
	glBindVertexArray(VAO_);
	glBindTexture(GL_TEXTURE_CUBE_MAP, texture_id_);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glDepthMask(GL_TRUE);
}




Skybox::~Skybox()
{
	glDeleteVertexArrays(1, &VAO_);
	glDeleteBuffers(1, &VBO_);
}
