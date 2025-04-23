CUBE


Firstly download glut to run this code 

 This program creates a 3D rotating colored cube using OpenGL and GLUT.
 The `DisplayFunc` handles drawing the cube, applying rotation on both X and Y axes.
 Each face of the cube is colored differently using `glColor3f()` for visual distinction.
 The cube rotates continuously by updating the rotation angle `alpha`.
 `glFlush()` and `glutSwapBuffers()` ensure smooth and complete rendering.
 `glutPostRedisplay()` requests continuous redrawing for animation.
 The `ReshapeFunc` adjusts perspective when the window is resized to maintain proper 3D appearance.
 `glEnable(GL_DEPTH_TEST)` ensures correct rendering of overlapping cube faces.
 GLUT handles window creation, rendering, and input via its event loop.
 The program uses double buffering and depth testing for realistic 3D rendering and smooth visuals.
