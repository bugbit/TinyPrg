#include <stdio.h>
#include <GL/freeglut.h>

int w=800,h=600;

void keyboardFunc(unsigned char k, int t1, int t2)
{
    int seed;

    switch (k)
    {
        case '\033':
        case 'q':
        case 'Q':
            printf("Shutting down...\n");

            #if defined(__APPLE__) || defined(MACOSX)
            exit(EXIT_SUCCESS);
            #else
            glutDestroyWindow(glutGetWindow());
            return;
            #endif
            break;
    }
}

static int initgl(int *argc, char **argv)
{
	printf("Initializing GLUT...\n");
	glutInit(argc, argv);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(w, h);
    glutCreateWindow("Autopilot Mandelbrot");

    glutKeyboardFunc(keyboardFunc);

    printf("OpenGL window created.\n");

    return 0;
}

int main(int argc, char **argv)
{
	printf("Autopilot Mandelbrot v.1.0\nCopyright (C) 2017 Oscar Hernández Bañó\n");

	initgl(&argc,argv);

    glutMainLoop();
}
