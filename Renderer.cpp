#include "Renderer.h"





Renderer::Renderer(OpenGlWindow & window, const Camera &cam):window_(window), shader_(DEFAULT_VERT_SHADER, DEFAULT_FRAG_SHADER), camera_(cam),fov_(70.0)//, skybox_(skybox_paths)
{

}

void Renderer::setCamera(const Camera & other)
{
	camera_ = other;
}

Camera Renderer::getCamera() const
{
	return Camera(camera_);
}

void Renderer::moveCameraForward()
{
	camera_.moveForward();
}

void Renderer::moveCameraBackward()
{
	camera_.moveBackward();

}

void Renderer::moveCameraRight()
{
	camera_.roundRight();
}

void Renderer::moveCameraLeft()
{
	camera_.roundLeft();
}

void Renderer::moveCameraUp()
{
	camera_.moveUp();
}

void Renderer::moveCameraDown()
{
	camera_.moveDown();
}


void Renderer::render(Scene & scene)const
{
	//przekaz scenie id shadera, aby zaladowala go swoim aktorom
	scene.setShaderId(shader_.GetShaderId());
	//skybox_.draw(getProjectionMatrix(), camera_.getViewMatrix());
	
	//zaladuj macierze uniform dla aktorów do shadera
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
