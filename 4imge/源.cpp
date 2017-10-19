#include  <iostream>
#include <GL/glut.h>
using namespace std;

int width = 400, height = 400;

void image1()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glMatrixMode(GL_PROJECTION);
	// 将当前矩阵置为单位矩阵  
	glLoadIdentity();

	// 通过设置视景体，而修改当前的投影矩阵。  
	glFrustum(-1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 1.0.0f);


	float vctPnt[][3] = {
		{ -0.5f,  0.5f, -1.0f },
		{ 0.5f,  0.5f, -1.0f },
		{ 0.5f, -0.5f, -1.0f },
		{ -0.5f, -0.5f, -1.0f }
	};

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINE_LOOP); // 绘制四边形  
	//glBegin(GL_TRIANGLES);
	for (int i = 0; i<4; i++)
	{
		glVertex3f(vctPnt[i][0], vctPnt[i][1], vctPnt[i][2]);
	}
	glEnd(); // 四边形绘制结束 

}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 0.0);//红绿蓝透

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

	//glClearColor(0.0, 0.0, 0.0, 0.0);//红绿蓝透
	glViewport(0, 0, 400, 400);
	glShadeModel(GL_SMOOTH);//线性插值
	//gluOrtho2D(-1.0f, 1.0f, -1.0f, 1.0f);//窗口
	glutDisplayFunc(&myDisplay);

	glutMainLoop();
	return 0;
}
