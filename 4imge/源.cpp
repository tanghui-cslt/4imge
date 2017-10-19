#include  <iostream>
#include <GL/glut.h>
using namespace std;

int width = 400, height = 400;

void image1()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glMatrixMode(GL_PROJECTION);
	// ����ǰ������Ϊ��λ����  
	glLoadIdentity();

	// ͨ�������Ӿ��壬���޸ĵ�ǰ��ͶӰ����  
	glFrustum(-1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 1.0.0f);


	float vctPnt[][3] = {
		{ -0.5f,  0.5f, -1.0f },
		{ 0.5f,  0.5f, -1.0f },
		{ 0.5f, -0.5f, -1.0f },
		{ -0.5f, -0.5f, -1.0f }
	};

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINE_LOOP); // �����ı���  
	//glBegin(GL_TRIANGLES);
	for (int i = 0; i<4; i++)
	{
		glVertex3f(vctPnt[i][0], vctPnt[i][1], vctPnt[i][2]);
	}
	glEnd(); // �ı��λ��ƽ��� 

}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 0.0);//������͸

	image1();
	glFlush();
}
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("opengl ");

	//glClearColor(0.0, 0.0, 0.0, 0.0);//������͸
	glViewport(0, 0, 400, 400);
	glShadeModel(GL_SMOOTH);//���Բ�ֵ
	//gluOrtho2D(-1.0f, 1.0f, -1.0f, 1.0f);//����
	glutDisplayFunc(&myDisplay);

	glutMainLoop();
	return 0;
}
