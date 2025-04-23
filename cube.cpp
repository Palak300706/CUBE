#include<stdlib.h>
#include<math.h>
#include <GL/glut.h>



void DisplayFunc(void)
{
  static float alpha = 0;

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();/*It then resets the camera to a default position*/

  glTranslatef(0, 0, -10);/*it moves the cube to the desired location*/
  glRotatef(45, 1, 0, 0);
  glRotatef(alpha, 0, 1, 0);

/*the glRotate rotate it in the x axis and
 the below function rotate it in the y axis*/

  glBegin(GL_QUADS);

  /* The glColor3f() function sets the color for each vertex,
   and glVertex3f() sets the position of the vertex in 3D space.*/

   // Front face (Red)
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);
    glVertex3f( 1.0f, -1.0f,  1.0f);
    glVertex3f( 1.0f,  1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f,  1.0f);

    // Back face (Green)
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);
    glVertex3f( 1.0f,  1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);

    // Top face (Blue)
    glColor3f(0.0f, .0f, 1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);
    glVertex3f(-1.0f,  1.0f,  1.0f);
    glVertex3f( 1.0f,  1.0f,  1.0f);
    glVertex3f( 1.0f,  1.0f, -1.0f);

    // Bottom face (Yellow)
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f,  1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);

    // Right face (Cyan)
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f,  1.0f, -1.0f);
    glVertex3f( 1.0f,  1.0f,  1.0f);
    glVertex3f( 1.0f, -1.0f,  1.0f);

    // Left face (Magenta)
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);

  glEnd();

  /* the below code decide the speed of rotation
   which we used in glRotatef function */
  alpha = alpha + .03;

  /* This is useful when you want to make sure that OpenGL
  has finished executing commands before moving on to other tasks */
  glFlush();

  glutSwapBuffers();/* It ensures smooth animation by not
                    displaying partially rendered images.*/
  glutPostRedisplay();/* is used to request a redraw when needed.*/


}

/* the below function adjusts the perspective
so that the cube still looks 3D  and doesn't get distorted
when the window size changes*/
void ReshapeFunc(int width, int height)
{
  glMatrixMode(GL_PROJECTION);

  glLoadIdentity();//clear any previous errors
  gluPerspective(20, width / (float) height, 5, 15);// This ensures that the cube appears at a realistic size and angle.
  glViewport(0, 0, width, height);
  /*defines the portion of the window
  where OpenGL will do the rotation*/

  glMatrixMode(GL_MODELVIEW);
  glutPostRedisplay();
  /*glMatrixMode(GL_MODELVIEW) switches to modelview mode to modify how objects
are drawn and viewed (e.g., rotating or translating them).
glutPostRedisplay() then requests a redraw of the
scene to apply any changes made to the modelview matrix
 (like moving or rotating objects)*/
}


int	 main(int argc, char **argv)
{

  glutInit(&argc, argv);
  // Initializes GLUT
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
   // Set display mode to RGB, double buffering, and depth testing
  glutInitWindowSize(500, 500);
  // Create a window of 500x500 pixels
  glutCreateWindow("  Rotate cube");
  // Create a window with the title "rotating"


  glClearColor(0, 0, 0, 0);
  //sets the background color to black.
  glEnable(GL_DEPTH_TEST);
   /*ensuring proper orientation  of 3D scenes
   where objects can overlap based on their depth. */


  /* Declaration of the callbacks */
  glutDisplayFunc(DisplayFunc);
  glutReshapeFunc(ReshapeFunc);


  /* Loop */
  glutMainLoop();

  return 0;
}
