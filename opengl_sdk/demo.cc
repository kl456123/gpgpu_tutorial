#include "init.h"
#include "context.h"

#include <iostream>
#include <GLES3/gl32.h>

GLuint CreateTexture(const GLfloat *data, GLsizei width_, GLsizei height_){
    GLuint texture_;

    // Create a texture.
    OPENGL_CALL(glGenTextures(1, &texture_));

    glBindTexture(GL_TEXTURE_2D, texture_);

    // Similar to cudaMemcpy.
    OPENGL_CALL(glTexImage2D(GL_TEXTURE_2D, /*level=*/0, GL_HALF_FLOAT_OES,
                width_, height_, /*border=*/0,
                GL_RGBA, GL_HALF_FLOAT_OES, nullptr));
    // TODO(zhixunt): What are these?
    OPENGL_CALL(
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
    OPENGL_CALL(
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));
    OPENGL_CALL(
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
    OPENGL_CALL(
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));

    if(data){
        OPENGL_CALL(glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width_, height_,
                    GL_RGBA, GL_FLOAT, data));
    }

    return texture_;
}

void LogExtension(){
	//eglGetProcAddress("
	int num_extensions;
	glGetIntegerv(GL_NUM_EXTENSIONS, &num_extensions);
	std::cout<<"num_extensions: "<<num_extensions<<std::endl;
//	for(int i=0; i<num_extensions; ++i){
//		const GLubyte *ccc = glGetStringi(GL_EXTENSIONS, i);
//		std::cout<<ccc<<std::endl;
//	}
}

int main(){
	// init opengl context first
	opengl::glfw_init();
 	LogExtension();

	// create float texture
//	auto input0 = CreateTexture(nullptr, 10, 10);
//	auto input1 = CreateTexture(nullptr, 10, 10);
	return 0;
}
