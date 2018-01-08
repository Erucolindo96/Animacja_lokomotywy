#include "Renderer.h"





Renderer::Renderer(OpenGlWindow & window, const Camera &cam):window_(window), shader_("..\\Animacja_lokomotywy\\shaders_code\\main.vert", DEFAULT_FRAG_SHADER), camera_(cam),fov_(45.0)
{
	//glEnable(GL_DEPTH_TEST);
}

void Renderer::setCamera(const Camera & other)
{
	camera_ = other;
}

Camera Renderer::getCamera() const
{
	return Camera(camera_);
}


void Renderer::render(Scene & scene)const
{
	//przekaz scenie id shadera, aby zaladowala go swoim aktorom
	scene.setShaderId(shader_.GetShaderId());
	
	//zaladuj macierze uniform do shadera
	glUniformMatrix4fv(shader_.getProjectionId(), 1, GL_FALSE, glm::value_ptr(getProjectionMatrix()) );
	glUniformMatrix4fv(shader_.getViewId(), 1, GL_FALSE, glm::value_ptr(camera_.getViewMatrix()) );

	scene.renderActors();

}

glm::mat4x4 Renderer::getProjectionMatrix() const
{
	return glm::perspective(glm::radians(fov_), (GLfloat)window_.getWidth()/ (GLfloat)window_.getHeigth(), NEAR, FAR);
}


Renderer::~Renderer()
{
}
