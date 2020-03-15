#include<bits/stdc++.h>
#include <math.h>
#include <GL/glut.h>
#include <GL/gl.h>

int rotX = 0;
int rotY = 90;
GLUquadricObj *pObj;

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

void display(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glPushMatrix();

  glTranslatef(0,-1,-5);
  glRotatef((GLfloat)rotX,1,0,0);
  glRotatef((GLfloat)rotY,0,1,0);
  //bola maior
  glColor3f(0.99999,0.99999,0.99999);
  gluSphere(pObj,1,26,13);
  //bola media
  glTranslatef(0,1,0);
  gluSphere(pObj,0.75,26,13);
  //bola da cabeca
  glTranslatef(0,0.9,0);
  gluSphere(pObj,0.5,26,13);

  //rosto
  //olho esquerdo
  glColor3f(0.1,0.1,0.1);
  glTranslatef(-0.45,0.1,-0.15);
  gluSphere(pObj,0.08,8,8);
  //olho direito
  glColor3f(0.1,0.1,0.1);
  glTranslatef(0,0,0.30);
  gluSphere(pObj,0.08,8,8);
  //cenoura
  glColor3f(1,0.3,0);
  glRotatef(-90,0,1,0);
  glTranslatef(-0.15,-0.2,-0.1);
  gluCylinder(pObj,0.1,0.02,0.4,26,13);
  glTranslatef(0,0,0.39);
  gluSphere(pObj,0.02,8,8);


  //bracos
  //esquerdo
  //ante-braço
  glColor3f(0.5f, 0.35f, 0.05f);
  glRotatef(90,0,1,0);
  glTranslatef(0.65,-0.7,0);
  gluCylinder(pObj,0.09,0.09,0.9,26,13);
  //cotovelo
  glTranslatef(0,0,0.9);
  gluSphere(pObj,0.09,26,13);
  //braço
  glRotatef(-50,1,0,0);
  gluCylinder(pObj,0.09,0.09,0.5,26,13);
  glRotatef(50,0.09,0,0);
  //mão
  glTranslatef(0,0.4,0.34);
  gluSphere(pObj,0.1,26,13);
  //galho do braço
  glTranslatef(0,-0.4,-0.3);
  glRotatef(20,0.09,0,0);
  gluCylinder(pObj,0.06,0.06,0.5,26,13);
  glTranslatef(0,0,0.5);
  gluSphere(pObj,0.07,26,13);
  
  //direito
  //ante-braço
  glRotatef(-180,0,1,0);
  glTranslatef(0,-0.5,1.54);
  gluCylinder(pObj,0.09,0.09,0.9,26,13);
  //cotovelo
  glTranslatef(0,0,0.86);
  gluSphere(pObj,0.09,26,13);
  //braço
  glRotatef(50,1,0,0);
  gluCylinder(pObj,0.09,0.09,0.5,26,13);
  glRotatef(-50,1,0,0);
  //mão
  glTranslatef(0,-0.4,0.34);
  gluSphere(pObj,0.1,26,13);
  //galho
  glTranslatef(0,0.1,-0.1);
  glRotatef(140,0.09,0,0);
  gluCylinder(pObj,0.06,0.06,0.2,26,13);
  glTranslatef(0,0,0.2);
  gluSphere(pObj,0.07,26,13);

  //botoes da camisa
  //botao mais de baixo
  glColor3f(0.9,0.1,0.1);
  glTranslatef(0.9,-0.55,1.5);
  gluSphere(pObj,0.08,8,8);
  //botao do meio
  glTranslatef(-0.1,-0.3,-0.5);
  gluSphere(pObj,0.08,8,8);
  //botao de cima
  glTranslatef(-0.15,-0.25,-0.45);
  gluSphere(pObj,0.08,8,8);

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

  pObj = gluNewQuadric();
  gluQuadricNormals(pObj,GLU_SMOOTH);
}

int main(int argc, char *argv[]){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(800, 600);
  glutCreateWindow("Boneco de neve: Gustavo M. Bonassa");
  // Inicia
  init();
  glutReshapeFunc(reshape);
  glutDisplayFunc(display);
  // Le o teclado
  glutKeyboardFunc(keyboard);
  glClear(GL_COLOR_BUFFER_BIT);
  glClearColor(0, 0, 0, 1);
  glutMainLoop();

  return 0;
}