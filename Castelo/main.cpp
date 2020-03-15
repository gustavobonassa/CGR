#include<bits/stdc++.h>
#include <math.h>
#include <GL/glut.h>
#include <GL/gl.h>

int rotX = 0;
int rotY = 90;


GLUquadricObj *pObj;


void init(){
    GLfloat sourceLight[] = {.3,.3,.3,0};

    glEnable(GL_DEPTH_TEST);
    glFrontFace(GL_CCW);
    glEnable(GL_CULL_FACE);

    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0,GL_AMBIENT,sourceLight);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,sourceLight);
    glEnable(GL_LIGHT0);

    glEnable(GL_COLOR_MATERIAL);

    glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);

    glClearColor(0,0,0,0);

    pObj = gluNewQuadric();
    gluQuadricNormals(pObj,GLU_SMOOTH);


}
void reshape(int w, int h){

    GLfloat f;
    if(h==0) h=1;

    glViewport(0,0,w,h);

    f = (GLfloat)w/(GLfloat)h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(35,f,1,40);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void torre(float r, float g, float b)
{
    glColor3f(r,g,b);
    glColor3f(1,0.5,0);
    //Torre
    glTranslatef(0,0,-1);
    gluCylinder(pObj,0.25,0.25,0.7,6,6);
    glColor3f(1,0.3,0);
    //Telhado
    glTranslatef(0,0,-0.35);
    gluCylinder(pObj,0,0.3,0.35,6,6);
    //para raio
    glColor3f(1,1,1);
    glTranslatef(0,0,-0.05);
    gluCylinder(pObj,0.005, 0.005, 0.2, 6, 6);

    glTranslatef(0,0,1.4);
}
void muro() {
  glColor3f(1,0.5,0);
  glBegin(GL_QUADS);
    glVertex3f(1.0, 0.0, 0.1);
    glVertex3f(1.0, 0.5, 0.1);
    glVertex3f(-1.0, 0.5, 0.1);
    glVertex3f(-1.0, 0.0, 0.1);

    glVertex3f(-1.0, 0.0, -0.1);
    glVertex3f(-1.0, 0.5, -0.1);
    glVertex3f(1.0, 0.5, -0.1);
    glVertex3f(1.0, 0.0, -0.1);

    glVertex3f(1.0, 0.5, 0.1);
    glVertex3f(1.0, 0.5, -0.1);
    glVertex3f(-1.0, 0.5, -0.1);
    glVertex3f(-1.0, 0.5, 0.1);

    glVertex3f(1.0, 0.0, -0.1);
    glVertex3f(1.0, 0.0, 0.1);
    glVertex3f(-1.0, 0.0, 0.1);
    glVertex3f(-1.0, 0.0, -0.1);

    glVertex3f(-1.0, 0.5, 0.1);
    glVertex3f(-1.0, 0.5, -0.1);
    glVertex3f(-1.0, 0.0, -0.1);
    glVertex3f(-1.0, 0.0, 0.1);

    glVertex3f(1.0, 0.5, -0.1);
    glVertex3f(1.0, 0.5, 0.1);
    glVertex3f(1.0, 0.0, 0.1);
    glVertex3f(1.0, 0.0, -0.1);

  glEnd();
}

void display(void){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();

    glTranslatef(0,-1,-5);
    glRotatef((GLfloat)rotX,1,0,0);
    glRotatef((GLfloat)rotY,0,1,0);
    glTranslatef(0,.4,0);
    glRotatef(90,1,0,0);

    //Torre central
    glColor3f(1,0.5,0);
    glTranslatef(0,0,-1);
    gluCylinder(pObj,0.2,0.2,1,6,6);
    //Telhado
    glColor3f(1,0.3,0);
    glTranslatef(0,0,-0.2);
    gluCylinder(pObj,0,0.3,0.3,6,6);

    glTranslatef(-1,-1,1.8);
    torre(0.99999, 0.99999, 0.99999);
    glTranslatef(0,2,0);
    torre(0, 0, 255);
    glTranslatef(2,0,0);
    torre(0, 255, 0);
    glTranslatef(0,-2,0);
    torre(255, 0, 0);

    glRotatef(90,1,0,0);
    glTranslatef(-1,-0.81,0);

    muro();

    glRotatef(90,0,1,0);
    glTranslatef(1,0,1);
    muro();

    glRotatef(90,0,1,0);
    glTranslatef(1,0,1);
    muro();

    glRotatef(90,0,1,0);
    glTranslatef(1,0,1);
    muro();
    glTranslatef(0,0.2,0);
    // entrada
    glColor3f(1,0.5,0);
    glutSolidCube(0.6);
    glRotatef(90,1,0,0);
    glColor3f(1,0.3,0);
    glTranslatef(0,0,0.28);
    gluCylinder(pObj,0.5,0,0.3,6,6);
    glColor3f(1,1,1);

    glTranslatef(0,-3,-0.7);
    glTranslatef(0,1,0.2);

    glColor3f(1,1,1);
    glTranslatef(0,2.22,0.02);
    glutSolidCube(0.2);

    glPopMatrix();
    glutSwapBuffers();

}

void keyboard (unsigned char key, int x, int y){
  switch(key){
    case 'w':
      rotX = (rotX - 10) %360;
      glutPostRedisplay();
      break;
    case 'a':
      rotY = (rotY - 10) %360;
      glutPostRedisplay();
      break;
    case 's':
      rotX = (rotX + 10) %360;
      glutPostRedisplay();
      break;
    case 'd':
      rotY = (rotY + 10) %360;
      glutPostRedisplay();
      break;
  }
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Castelo");
    init();
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}