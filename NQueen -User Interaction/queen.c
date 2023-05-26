#include <Windows.h>
#include<mmsystem.h>
#include<stdio.h>
#include<stdlib.h>
#include <GL/GL.h>
#include <GL/glut.h>

char chessboard[222][222] = {};
int queens;
int queenShape=0;
int  viewPage=0;
void display();
float W; float H;
int currentstate=0;
int savingposition[222][2] = {};



void init()
{
    glClearColor(0,0,0,0);

//gluOrtho2D(0,150,0,150);
}

bool checking(int row, int column) {
	for (int i = 0; i< queens; i++) {
		for (int j = 0; j < queens; j++) {
			if ((j + i == column + row || column - row == j - i || i == row || j == column) && chessboard[i][j] == 'Q')


               return false;
		}
	}
	return true;
}
void removeflag(int row)
{
	for (int i = 0; i < queens; i++)
	{
		chessboard[row][i] = '0';

	}
}
void backtracking(void)
{
	for (int row = 0; row < queens; row++)
	{
		for (int column = 0; column <queens; column++) {
			if (checking(row, column) && chessboard[row][column] != '-') {
				chessboard[row][column] = 'Q'; removeflag(row + 1);
				savingposition[row][0] = row;
				savingposition[row][1] = column;
				row++; column = -1;
				if (row == queens) break;
			}
			else if (column == queens - 1 && chessboard[row][column] != 'Q')
			{
			    PlaySound("stack_empty.wav", NULL, SND_FILENAME | SND_ASYNC);


				row--;
				column = savingposition[row][1];
				//cout << row << " " << column << endl;
				chessboard[row][column] = '-';

				column = 0;
			}
		}
	}
}
void displaytable(void)
{
	for (int i = 0; i< queens; i++) {
		for (int j = 0; j < queens; j++) {
			if (chessboard[i][j] != 'Q')
				printf(".");//cout << '.';

			else
				printf("%c",chessboard[i][j]);//cout << chessboard[i][j];
		}
		printf("\n");;
	}
}
void keyboard(unsigned char key, int x, int y)
{
    switch (key) {


        case '\r': // Enter key
            currentstate = 1; // switch to chessboard display
            glutPostRedisplay();
            break;


}
}
void displayboard()
{
    glTranslatef(75, H - 75, 0.0);
    glPushMatrix();
    for (int i = 0; i<queens; i++) {
        glPushMatrix();
        for (int j = 0; j < queens; j++) {
            if ((i + j) % 2 == 0)
                glColor3f(1.0, 1.0, 1.0);
            else
                glColor3f(0.0, 0.0, 0.0);
            glPushMatrix();
            glScalef(150.0, 150.0, 0.0);
            glutSolidCube(1);
             if (chessboard[i][j] == 'Q') {
                glPushMatrix();
                // user's choice of queen shape

                    // Draw a sphere for the queen
                    glColor3f(0, 1, 0);
                    glutSolidSphere(0.4, 150, 150);

                glPopMatrix();
            }

            glPopMatrix();
            glTranslatef(150.0, 0.0, 0.0);
        }
        glPopMatrix();
        glTranslatef(0.0, -150.0, 0.0);
    }
    glPopMatrix();
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Check if we're on the starting page
    if (currentstate == 0) {
        // Draw the starting page here
        // This might include some instructions or a prompt to start the program
        // You could use glColor3f and glRasterPos2f to draw text to the screen, for example
         glColor3f(0.0, 0.0, 1.0);
        glRasterPos2f(200.0, 700.0);
        char m[] = "NMAM INSTITUTE OF TECHNOLOGY";
        for (int i = 0; i < strlen(m); i++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, m[i]);
        }
        glColor3f(1.0, 0.0, 1.0);
        glRasterPos2f(180.0, 670.0);
        char me[] = "Department of Computer Science & Enginnering";
        for (int i = 0; i < strlen(me); i++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, me[i]);
        }
         glColor3f(1.0, 1.0, 0.0);
        glRasterPos2f(180.0, 630.0);
        char mes[] = "MINI PROJECT ON:";
        for (int i = 0; i < strlen(mes); i++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, mes[i]);
        }
         glColor3f(1.0, 1.0, 1.0);
        glRasterPos2f(400.0, 630.0);
        char mess[] = "N-Queen's Visualisation";
        for (int i = 0; i < strlen(mess); i++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, mess[i]);
        }
        glColor3f(0.0, 1.0, 1.0);
        glRasterPos2f(00.0, 500.0);
        char messa[] = "Presented By:";
        for (int i = 0; i < strlen(messa); i++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, messa[i]);
        }
         glColor3f(1.0, 1.0, 1.0);
        glRasterPos2f(00.0, 480.0);
        char messag[] = "Vasudha.G";
        for (int i = 0; i < strlen(messag); i++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, messag[i]);
        }
         glColor3f(1.0, 1.0, 1.0);
        glRasterPos2f(00.0, 460.0);
        char messaga[] = "Shweta Sanjay";
        for (int i = 0; i < strlen(messaga); i++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, messaga[i]);
        }
        glColor3f(0.0, 1.0, 1.0);
        glRasterPos2f(500.0, 500.0);
        char v[] = "Under the guidance of:";
        for (int i = 0; i < strlen(v); i++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, v[i]);
        }
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos2f(500.0, 480.0);
        char va[] = "Mr.Puneeth R.P";
        for (int i = 0; i < strlen(va); i++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, va[i]);
        }
         glColor3f(1.0, 1.0, 1.0);
        glRasterPos2f(500.0, 460.0);
        char vas[] = "Assistant Professor,NMAMIT";
        for (int i = 0; i < strlen(vas); i++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, vas[i]);
        }
        glColor3f(1.0, 05.0, 1.0);
        glRasterPos2f(00.0, 450.0);
        char vasu[] = "========================================================================================================================================================================================================================================";
        for (int i = 0; i < strlen(vasu); i++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, vasu[i]);
        }

        glColor3f(1.0, 1.0, 1.0);
        glRasterPos2f(150.0, 150.0);
        char message[] = "Press Enter to begin!";
        for (int i = 0; i < strlen(message); i++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
        }



        }else {
        // Draw the chessboard and queen placement as usual
        glPushMatrix();
        displayboard();
        glPopMatrix();
        displaytable();
    }

    glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, W, 0, H);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();//important: last line must be glLoadIdentity() for coloring with openGL
					 //glTranslatef (.0, .0, -5.); //do not translate at all if glLoadIdentity() is used
}
void mouse(int button, int state, int x, int y) //mouse function...
{
	int row, column;
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
		{
			row = (y / 150);
			column = (x / 150);
			if (checking(row, column))
				chessboard[row][column] = 'Q';
            else
            {

                PlaySound("stack_empty.wav", NULL, SND_FILENAME | SND_ASYNC);

            }

		}

		glutPostRedisplay();
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN)
		{

			row = (y / 150);
			column = (x / 150);
			chessboard[row][column] = ' ';
		}

		glutPostRedisplay();

		break;
	}
}


int main(int argc, char ** argv)
{
    int input;
    int queenShape;
   printf("Declare the size of the Queen you want to play\n");
    scanf("%d",&queens);
    printf("Queen's Shape changes according to the user's wish\n");
    printf("Press 1 for Queen Shape to be sphere\n Press 2 for Queen Shape to be Triangle");
W = 150 * queens;
	H = 150 * queens;
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(W,H);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Chessboard");
	init();
	glutDisplayFunc(display);

	 glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
