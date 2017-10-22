#include <iostream>

#define GLEW_STATIC
#include <GL/glew.h>

#include <GL/glfw3>

const GLint WIDTH=800, HEIGHT = 600;

using namespace std;


int main(int argc, char** argv) {
    glfwInit();
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
}

