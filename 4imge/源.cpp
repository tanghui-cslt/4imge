#include  <iostream>
#include <GL/glut.h>
using namespace std;

int width = 400, height = 400;

static int times = 0;

static const float vertex_list[][3] =
{
	-0.5f, -0.5f, -0.5f,
	0.5f, -0.5f, -0.5f,
	-0.5f, 0.5f, -0.5f,
	0.5f, 0.5f, -0.5f,
	-0.5f, -0.5f, 0.5f,
	0.5f, -0.5f, 0.5f,
	-0.5f, 0.5f, 0.5f,
	0.5f, 0.5f, 0.5f,
};

// ��Ҫʹ�õĶ������ű��浽һ���������� 

static const GLint index_list[][2] =
{
	{ 0, 1 },
	{ 2, 3 },
	{ 4, 5 },
	{ 6, 7 },
	{ 0, 2 },
	{ 1, 3 },
	{ 4, 6 },
	{ 5, 7 },
	{ 0, 4 },
	{ 1, 5 },
	{ 7, 3 },
	{ 2, 6 }
};


void image1()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glViewport(0, 0, 200, 200);

	int i, j;

	glBegin(GL_LINES);
	for (i = 0; i<12; ++i) // 12 ���߶�

	{
		for (j = 0; j<2; ++j) // ÿ���߶� 2������

		{
			glVertex3fv(vertex_list[index_list[i][j]]);
		}
	}
	glEnd();

}

void image2()
{
//	glClear(GL_COLOR_BUFFER_BIT);

	//glMatrixMode(GL_PROJECTION);
	//// ����ǰ������Ϊ��λ����  
	//glLoadIdentity();

	// ͨ�������Ӿ��壬���޸ĵ�ǰ��ͶӰ����  
	glViewport(200, 0, 200, 200);


	//glLoadIdentity();                           // ���õ�ǰ��ģ�͹۲����  
	//glTranslatef(-1.5f, 0.0f, -6.0f);    // ���� 1.5 ��λ����������Ļ 6.0  
	//glRotatef(rtri, 0.0f, 1.0f, 0.0f);             // ��Y����ת������  
	glBegin(GL_TRIANGLES);                          // ����������      
	glColor3f(1.0f, 0.0f, 0.0f);          // ��ɫ  
	glVertex3f(0.0f, 0.5f, 0.0f);          // �����ε��϶��� (ǰ����)  
	//glColor3f(0.0f, 1.0f, 0.0f);          // ��ɫ  
	glVertex3f(-0.5f, -0.5f, 0.5f);          // �����ε����¶��� (ǰ����)  
	//glColor3f(0.0f, 0.0f, 1.0f);          // ��ɫ  
	glVertex3f(0.5f, -0.5f, 0.5f);          // �����ε����¶��� (ǰ����)  


	glColor3f(0.0f, 1.0f, 0.0f);          // ��ɫ  
	glVertex3f(0.0f, 0.5f, 0.0f);          // �����ε��϶��� (�Ҳ���)  
	//glColor3f(0.0f, 0.0f, 1.0f);          // ��ɫ  
	glVertex3f(0.5f, -0.5f, 0.5f);          // �����ε����¶��� (�Ҳ���)  
	//glColor3f(0.0f, 1.0f, 0.0f);          // ��ɫ  
	glVertex3f(0.5f, -0.5f, -0.5f);         // �����ε����¶��� (�Ҳ���)  



	glColor3f(0.0f, 0.0f, 1.0f);          // ��ɫ  
	glVertex3f(0.0f, 0.5f, 0.0f);          // �����ε��϶��� (�����)  
	//glColor3f(0.0f, 1.0f, 0.0f);          // ��ɫ  
	glVertex3f(0.5f, -0.5f, -0.5f);         // �����ε����¶��� (�����)  
	//glColor3f(0.0f, 0.0f, 1.0f);          // ��ɫ  
	glVertex3f(-0.5f, -0.5f, -0.5f);         // �����ε����¶��� (�����)  



	glColor3f(1.0f, 1.0f, 0.0f);          // ��ɫ  
	glVertex3f(0.0f, 0.5f, 0.0f);          // �����ε��϶��� (�����)  
	//glColor3f(0.0f, 0.0f, 1.0f);          // ��ɫ  
	glVertex3f(-0.5f, -0.5f, -0.5f);         // �����ε����¶��� (�����)  
	//glColor3f(0.0f, 1.0f, 0.0f);          // ��ɫ  
	glVertex3f(-0.5f, -0.5f, 0.5f);         // �����ε����¶��� (�����)  
	glEnd();                        // ���������ƽ���  

}
void Circle()
{
	glBegin(GL_TRIANGLE_FAN);//����������������δ�  
	glColor3f(1.0f, 0.4f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	int i = 0;
	for (i = 0; i <= 390; i += 15)
	{
		float p = i * 3.14 / 180;
		glVertex3f(sin(p)*0.5, cos(p)*0.5, 0.0f);
	}
	glEnd();
}
void image3()
{
	glViewport(0, 200, 200, 200);
	glutWireSphere(0.5, 10, 10);
	//Circle();
}

void image4()
{
	//	glClear(GL_COLOR_BUFFER_BIT);

	//glMatrixMode(GL_PROJECTION);
	//// ����ǰ������Ϊ��λ����  
	//glLoadIdentity();

	// ͨ�������Ӿ��壬���޸ĵ�ǰ��ͶӰ����  
	glViewport(200, 200, 200, 200);
	//glutSolidSphere(0.5,100,100);
	glColor3f(0.5f, 1.0f, 0.0f);
	glBegin(GL_QUAD_STRIP);//��������ı��δ�  
	int i = 0;
	for (i = 0; i <= 390; i += 15)
	{
		float p = i * 3.14 / 180;
		glVertex3f(0, 0, 1.0f);
		glVertex3f(sin(p)*0.5, cos(p)*0.5, 0.0f);
	}
	glEnd();
	Circle();

}


void renderScene(void)
{
	static float rotate = 0;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();

	//glTranslatef(-0.2, 0, 0); // ƽ��

	//glScalef(2, 1, 1);    // ����


	times++;
	if (times > 100)
	{
		times = 0;
	}

	if (times % 100 == 0)
	{
		rotate += 0.3;
	}

	glRotatef(rotate, 1, 1, 0);
	//glRotatef(rotate, 1, 0, 0);

	glColor3f(1, 0, 0);

	image1();
	image2();
	image3();
	image4();
	glPopMatrix();
	glutSwapBuffers();
}
void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 0.0);//������͸

	image1();
	image2();
	image3();
	image4();

	glFlush();
}
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("opengl ");

	
	glMatrixMode(GL_PROJECTION);
	// ����ǰ������Ϊ��λ����  
	glLoadIdentity();

	glFrustum(-1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 1.0f);
	glShadeModel(GL_SMOOTH);//���Բ�ֵ
	//gluOrtho2D(-1.0f, 1.0f, -1.0f, 1.0f);//����
	glutDisplayFunc(&myDisplay);
	glutIdleFunc(renderScene);
	glutMainLoop();
	return 0;
}
