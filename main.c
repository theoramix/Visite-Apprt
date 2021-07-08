/* *******************************************************/
/* Exemple de programme OpenGL / GLUT           (C) 2010 */
/* Venceslas Biri   Université Paris Est Marne La Vallée */
/* *******************************************************/

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include "rectangle.h"
#include "camera.h"

#define STEP_ANGLE 3.14/12
#define STEP_PROF 0.5

/* variables globales pour la gestion de la caméra */
float profondeur = 0.1;
float latitude = 0.0;
float longitude = 3.14/2.;
float offX=0;
float offY = 1.3;
float offZ=15;

void glDrawRepere(float length) {
    // dessin du repère
    glBegin(GL_LINES);
        glColor3f(1.,0.,0.);
        glVertex3f(0.,0.,0.);
        glVertex3f(length,0.,0.);
        glColor3f(0.,1.,0.);
        glVertex3i(0.,0.,0.);
        glVertex3i(0.,length,0.);
        glColor3f(0.,0.,1.);
        glVertex3i(0.,0.,0.);
        glVertex3i(0.,0.,length);
    glEnd();
}

/*********************************************************/
/* fonction de dessin de la scène à l'écran              */
static void drawFunc(void) { 
	/* reinitialisation des buffers : couleur et ZBuffer */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/* modification de la matrice de la scène */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	/* Debut du dessin de la scène */
	glPushMatrix();
	
	/* placement de la caméra */
	gluLookAt(profondeur*sin(longitude)*sin(latitude)+offX,profondeur*cos(latitude)+offY,profondeur*cos(longitude)*sin(latitude)+offZ,
              0.0+offX,0.0+offY,0.0+offZ,
              0.0,1.0,0.0);

	glColor3f(1.0,0.0,0.0);
	glDrawRepere(2.0);

    drawMurs1();
	drawMurs2();
	drawSol();
	drawTable();
	drawArmoire();
	drawLit();
	drawCommode();
	drawCommode2();
	drawConsole();
	drawMeuble();

	glPushMatrix();
	glColor3f(1.0,1.0,1.0);

	/* Fin du dessin */
	glPopMatrix();

	/* fin de la définition de la scène */
	glFinish();

	/* changement de buffer d'affichage */
	glutSwapBuffers();
}

/*********************************************************/
/* fonction de changement de dimension de la fenetre     */
/* paramètres :                                          */
/* - width : largeur (x) de la zone de visualisation     */
/* - height : hauteur (y) de la zone de visualisation    */
static void reshapeFunc(int width,int height) {
	GLfloat  h = (GLfloat) width / (GLfloat) height ;
	
	/* dimension de l'écran GL */
	glViewport(0, 0, (GLint)width, (GLint)height);
	/* construction de la matrice de projection */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	/* définition de la camera */
	gluPerspective( 60.0, h, 0.01, 100.0 );			// Angle de vue, rapport largeur/hauteur, near, far

	/* Retour a la pile de matrice Modelview
			et effacement de celle-ci */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void idle(void) {
	mouvement();
	glutPostRedisplay();

}

/*********************************************************/
/* fonction associée aux interruptions clavier           */
/* paramètres :                                          */
/* - c : caractère saisi                                 */
/* - x,y : coordonnée du curseur dans la fenêtre         */
static void kbdFunc(unsigned char c, int x, int y) {
	/* sortie du programme si utilisation des touches ESC, */
	/* 'q' ou 'Q'*/
	switch(c) {
		case 27 :
			exit(0);
			break;
		case 'F' : case 'f' : glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
			break;
		case 'P' : case 'p' : glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
			break;
		case 'S' : case 's' : glutIdleFunc(NULL);
			break;
		case 'Z' : case 'z' : 
			offX+=(-profondeur*sin(longitude)*sin(latitude));
			offZ+=(-profondeur*cos(longitude)*sin(latitude));
			break;	
		case 32 :
			glutIdleFunc(idle);
			break;
		default:
			printf("Appui sur la touche %c\n",c);
	}
	glutPostRedisplay();
}

/*********************************************************/
/* fonction associée aux interruptions clavier pour les  */
/*          touches spéciales                            */
/* paramètres :                                          */
/* - c : code de la touche saisie                        */
/* - x,y : coordonnée du curseur dans la fenêtre         */
static void kbdSpFunc(int c, int x, int y) {
	/* sortie du programme si utilisation des touches ESC, */
	switch(c) {
		case GLUT_KEY_UP :
			if (latitude>STEP_ANGLE) latitude += STEP_ANGLE;
			break;
		case GLUT_KEY_DOWN :
			if(latitude<3.14-STEP_ANGLE) latitude -= STEP_ANGLE;
			break;
		case GLUT_KEY_LEFT :
			longitude += STEP_ANGLE;
			break;
		case GLUT_KEY_RIGHT :
			longitude -= STEP_ANGLE;
			break;
		default:
			printf("Appui sur une touche spéciale\n");
	}
	glutPostRedisplay();
}

/*********************************************************/
/* fonction d'initialisation des paramètres de rendu et  */
/* des objets de la scènes.                              */
static void init() {
	profondeur = 0.1;
	latitude = 3.14/2.0;
	longitude = 0.0;

	/* INITIALISATION DES PARAMETRES GL */
	/* couleur du fond (gris sombre) */
	glClearColor(0.3,0.3,0.9,0.0);
	/* activation du ZBuffer */
	glEnable( GL_DEPTH_TEST);

	/* lissage des couleurs sur les facettes */
	glShadeModel(GL_SMOOTH);

	/* INITIALISATION DE LA SCENE */
}

int main(int argc, char** argv) {
	/* traitement des paramètres du programme propres à GL */
	glutInit(&argc, argv);
	/* initialisation du mode d'affichage :                */
	/* RVB + ZBuffer + Double buffer.                      */
	glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH|GLUT_DOUBLE);
	/* placement et dimentions originales de la fenêtre */
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1000, 1500);
	/* ouverture de la fenêtre */
	if (glutCreateWindow("VISITE APPART") == GL_FALSE) {
		return 1;
	}

	init();

	/* association de la fonction callback de redimensionnement */
	glutReshapeFunc(reshapeFunc);
	/* association de la fonction callback d'affichage */
	glutDisplayFunc(drawFunc);
	/* association de la fonction callback d'événement du clavier */
	glutKeyboardFunc(kbdFunc);
	/* association de la fonction callback d'événement du clavier (touches spéciales) */
	glutSpecialFunc(kbdSpFunc);

	/* boucle principale de gestion des événements */
	glutMainLoop();}