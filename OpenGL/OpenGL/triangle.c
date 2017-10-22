/*#include <GLUT/glut.h>
#include <iostream>

using namespace std;

void render(void);

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Triangle");
    
    glutDisplayFunc(render);
    
    glutMainLoop();
}

void render(void) {
    
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5, -0.5);
    
    glVertex2f(0.5, -0.5);
    glVertex2f(0.0, 0.5);
    glEnd();
    
    glutSwapBuffers();
}
*/
