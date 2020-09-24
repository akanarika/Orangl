#include "Renderer.h"

#include <iostream>

/**
static void GLCheckError()
{
	while (GLenum error = glGetError()) {
		std::cout << "[OpenGL Error](" << error << ")" << std::endl;
	}
}
**/

void GLClearError()
{
	while (glGetError() != GL_NO_ERROR); {

	}
}

bool GLLogCall(const char* function, const char* file, int line)
{
	while (GLenum error = glGetError())
	{
		std::cout << "[OpenGL Error]" << error << "): " << function <<
			" " << file << ":" << line << std::endl;
		return false;
	}
	return true;
}

void Renderer::Clear() const
{
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
}

void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const
{
	shader.Bind();
	//shader.SetUniform4f("u_Color", r, .3f, .7f, 1.f);

	va.Bind();
	ib.Bind();
	GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}