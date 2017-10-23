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

// 将要使用的顶点的序号保存到一个数组里面 

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
	for (i = 0; i<12; ++i) // 12 条线段

	{
		for (j = 0; j<2; ++j) // 每条线段 2个顶点

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
	//// 将当前矩阵置为单位矩阵  
	//glLoadIdentity();

	// 通过设置视景体，而修改当前的投影矩阵。  
	glViewport(200, 0, 200, 200);


	//glLoadIdentity();                           // 重置当前的模型观察矩阵  
	//glTranslatef(-1.5f, 0.0f, -6.0f);    // 左移 1.5 单位，并移入屏幕 6.0  
	//glRotatef(rtri, 0.0f, 1.0f, 0.0f);             // 绕Y轴旋转三角形  
	glBegin(GL_TRIANGLES);                          // 绘制三角形      
	glColor3f(1.0f, 0.0f, 0.0f);          // 红色  
	glVertex3f(0.0f, 0.5f, 0.0f);          // 三角形的上顶点 (前侧面)  
	//glColor3f(0.0f, 1.0f, 0.0f);          // 绿色  
	glVertex3f(-0.5f, -0.5f, 0.5f);          // 三角形的左下顶点 (前侧面)  
	//glColor3f(0.0f, 0.0f, 1.0f);          // 蓝色  
	glVertex3f(0.5f, -0.5f, 0.5f);          // 三角形的右下顶点 (前侧面)  


	glColor3f(0.0f, 1.0f, 0.0f);          // 绿色  
	glVertex3f(0.0f, 0.5f, 0.0f);          // 三角形的上顶点 (右侧面)  
	//glColor3f(0.0f, 0.0f, 1.0f);          // 蓝色  
	glVertex3f(0.5f, -0.5f, 0.5f);          // 三角形的左下顶点 (右侧面)  
	//glColor3f(0.0f, 1.0f, 0.0f);          // 绿色  
	glVertex3f(0.5f, -0.5f, -0.5f);         // 三角形的右下顶点 (右侧面)  



	glColor3f(0.0f, 0.0f, 1.0f);          // 蓝色  
	glVertex3f(0.0f, 0.5f, 0.0f);          // 三角形的上顶点 (后侧面)  
	//glColor3f(0.0f, 1.0f, 0.0f);          // 绿色  
	glVertex3f(0.5f, -0.5f, -0.5f);         // 三角形的左下顶点 (后侧面)  
	//glColor3f(0.0f, 0.0f, 1.0f);          // 蓝色  
	glVertex3f(-0.5f, -0.5f, -0.5f);         // 三角形的右下顶点 (后侧面)  



	glColor3f(1.0f, 1.0f, 0.0f);          // 红色  
	glVertex3f(0.0f, 0.5f, 0.0f);          // 三角形的上顶点 (左侧面)  
	//glColor3f(0.0f, 0.0f, 1.0f);          // 蓝色  
	glVertex3f(-0.5f, -0.5f, -0.5f);         // 三角形的左下顶点 (左侧面)  
	//glColor3f(0.0f, 1.0f, 0.0f);          // 绿色  
	glVertex3f(-0.5f, -0.5f, 0.5f);         // 三角形的右下顶点 (左侧面)  
	glEnd();                        // 金字塔绘制结束  

}
void Circle()
{
	glBegin(GL_TRIANGLE_FAN);//扇形连续填充三角形串  
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
	//// 将当前矩阵置为单位矩阵  
	//glLoadIdentity();

	// 通过设置视景体，而修改当前的投影矩阵。  
	glViewport(200, 200, 200, 200);
	//glutSolidSphere(0.5,100,100);
	glColor3f(0.5f, 1.0f, 0.0f);
	glBegin(GL_QUAD_STRIP);//连续填充四边形串  
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

	//glTranslatef(-0.2, 0, 0); // 平移

	//glScalef(2, 1, 1);    // 缩放


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
	glClearColor(0.0, 0.0, 0.0, 0.0);//红绿蓝透

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
	// 将当前矩阵置为单位矩阵  
	glLoadIdentity();

	glFrustum(-1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 1.0f);
	glShadeModel(GL_SMOOTH);//线性插值
	//gluOrtho2D(-1.0f, 1.0f, -1.0f, 1.0f);//窗口
	glutDisplayFunc(&myDisplay);
	glutIdleFunc(renderScene);
	glutMainLoop();
	return 0;
}
