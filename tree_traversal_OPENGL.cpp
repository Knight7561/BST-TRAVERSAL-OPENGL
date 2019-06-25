
#include<stdlib.h>
#include<windows.h>
#include<GL\glut.h>
#include<stdio.h>
#include<math.h>
#define pi 3.141592
#define size 512
typedef struct
{
	char data[5];
	int value, left, right, key, level, parent;
	float x, y;
}node;
node a[30];
int p[20];
float color[6][3] = { { 0.0, 0.2, 0.5 }, { 0.5, 0.4, 0.5 }, { 0.0, 1.0, 0.0 }, { 1.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0 } ,{0.5f, 0.0f, 1.0f}};
int n = 0;
int flag = 1, ins = 0, del = 0, pre = 0, in = 0, post = 0, ex = 0, rflag = 0, lflag = 0, eflag = 1,eqflag=0;
int count = 0, c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0;
float rad = 1.0;
void delay(int limit=50000)
{
	printf("IN delay Func\n");
	int i, j;
	for (i = 0; i<limit; i++)
	for (j = 0; j<10000; j++);
}
void drawstring(float x, float y, char *string, int col)
{
	printf("IN drawstring Func\n");
	char *c;
	glColor3fv(color[col]);
	glRasterPos2f(x, y);
	for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
	}
}
void drawWindow(int x1, int y1, int x2, int y2)
{
	printf("IN drawWindow Func\n");
	glColor3f(0.5f, 0.0f, 1.0f);
	drawstring(9.0, 27.0, "TREE TRAVERSAL TECHINQUES", 1);
	
	glLineWidth(3);
	glBegin(GL_LINE_LOOP);
	glVertex2i(x1, y1);
	glColor3f(0.5f, 0.0f, 1.0f);
	glVertex2i(x2, y1);
	glColor3f(0.0f, 0.5f, 1.0f);
	glVertex2i(x2, y2);
	glColor3f(1.0f, 0.0f, 1.5f);
	glVertex2i(x1, y2);
	glEnd();
	glLineWidth(1);
	glFlush();
}
void drawWindow2(float x1, float y1, float x2, float y2)
{
	printf("IN drawWindow Func\n");
	glColor3f(0.5f, 0.0f, 1.0f);
	
	
	glLineWidth(3);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x1, y1);
	glColor3f(0.5f, 0.0f, 1.0f);
	glVertex2f(x2, y1);
	glColor3f(0.0f, 0.5f, 1.0f);
	glVertex2f(x2, y2);
	glColor3f(1.0f, 0.0f, 1.5f);
	glVertex2f(x1, y2);
	glEnd();
	glLineWidth(1);
	glFlush();
}
void preorder()
{
	printf("IN preorder Func\n");
	int stack[20], top = -1, cur, j = 0,temp;
	cur = 0;
	for (;;)
	{
		while (cur != -1)
		{
			p[j++] = cur;
			stack[++top] = cur;
			cur = a[cur].left;
			temp=j;
		}
		if (top != -1)
		{
			cur = stack[top--];
			cur = a[cur].right;
		}
		else
			break;
	}
	printf("STACK ELEMNTS FOR PRE ORDER \t : ");
for(j=0;j<temp;j++)
	printf("%s",a[p[j]].data);

}
void inorder()
{
	printf("IN inorder Func\n");
	int stack[20], top = -1, cur, j = 0,temp;
	cur = 0;
	for (;;)
	{
		while (cur != -1)
		{
			stack[++top] = cur;
			cur = a[cur].left;
		}
		if (top != -1)
		{
			cur = stack[top--];
			p[j++] = cur;
			cur = a[cur].right;
			temp=j;
		}
		else
			break;
	}
	printf("STACK ELEMNTS FOR IN ORDER \t : ");
for(j=0;j<temp;j++)
	printf("%s",a[p[j]].data);
}
void postorder()
{
	printf("IN postorder Func\n");
	struct stack
	{
		int address, flag;
	};
	int cur = 0, j = 0, top = -1,temp;
	struct stack s[20];
	top++;
	for (;;)
	{
		while (cur != -1)
		{
			top++;
			s[top].address = cur;
			s[top].flag = 1;
			cur = a[cur].left;
		}
		while (s[top].flag<0)
		{
			cur = s[top].address;
			top--;
			p[j++] = cur;
			temp=j;
			if (top == -1)
				return;
		}
		cur = s[top].address;
		cur = a[cur].right;
		s[top].flag = -1;
	}
	printf("STACK ELEMNTS FOR post ORDER \t : ");
for(j=0;j<temp;j++)
	printf("%s",a[p[j]].data);
}
void menu(GLenum mode)
{
	printf("IN menu Func\n");
	glColor3f(1,0,0);
	drawWindow2(24.5, 24, 29, 26);
	glColor3fv(color[c1]);
	if (mode == GL_SELECT)
		glLoadName(0);

	//glRecti(25, 24, 29, 26);
	glRecti(2, 2, 6, 4);
	//drawstring(26, 25, "INSERT", 2);
	drawstring(3, 3, "INSERT", 2);
	glColor3fv(color[c2]);
	if (mode == GL_SELECT)
		glLoadName(1);
	//glRecti(25, 21, 29, 23);
	glRecti(8, 2, 12, 4);
	//drawstring(26, 22, "DELETE", 2);
	drawstring(9, 3, "DELETE", 2);
	glColor3fv(color[c3]);
	if (mode == GL_SELECT)
		glLoadName(2);
	//glRecti(25, 18, 29, 20);
	glRecti(14, 2, 18, 4);
	//drawstring(26, 19, "PREORDER", 2);
	drawstring(15, 3, "PREORDER", 2);
	glColor3fv(color[c4]);
	if (mode == GL_SELECT)
		glLoadName(3);
	//glRecti(25, 15, 29, 17);
	glRecti(20, 2, 24, 4);
	//drawstring(26, 16, "INORDER", 2);
	drawstring(21, 3, "INORDER", 2);
	glColor3fv(color[c5]);
	if (mode == GL_SELECT)
		glLoadName(4);
	//glRecti(25, 12, 29, 14);
	glRecti(26, 2, 29, 4);
	//drawstring(26, 13, "POSTORDER", 2);
	drawstring(26.1, 3, "POSTORDER", 2);
	glColor3fv(color[c6]);
	if (mode == GL_SELECT)
		glLoadName(5);
	glRecti(25, 9, 29, 11);
	drawstring(26, 10, "EXIT", 2);
	
}
void drawbox(float x, float y, float w, int key, int c)
{
	printf("IN drawbox Func\n");
	int j = 0;
	glColor3fv(color[c]);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x, y);
	glVertex2f(x, y + w);
	glVertex2f(x + w, y + w);
	glVertex2f(x + w, y);
	glEnd();
	glFlush();
	glRasterPos2f(x + w / 2.0, y + w / 2.0f);
	while (a[key].data[j] != '\0')
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, a[key].data[j++]);
	glFlush();
}
void drawnode(int i, int c)
{
	printf("IN drawnode Func\n");
	float angle, x, y;
	int j = 0;
	glColor3fv(color[c]);
	glBegin(GL_POINTS);
	for (angle = 0.0; angle <= 2 * pi; angle += pi / 100.0f)
	{
		x = 0.75*cos(angle) + a[i].x;
		y = rad*sin(angle) + a[i].y;
		glVertex2f(x, y);
	}
	glEnd();
	glRasterPos2f(a[i].x, a[i].y);
	//printf("%f,%f %F",a[i].x, a[i].y,a[i].data);
	while (a[i].data[j] != '\0')
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, a[i].data[j++]);
	glFlush();
}
void processHits(GLuint hits, GLuint buffer[])
{
	printf("IN processHits Func\n\n ");

	GLuint *ptr;
	ptr = (GLuint *)buffer;
	ptr += 3;
	if (*ptr == 0)
	{
		c1++;
		ins = 1;
	}
	if (*ptr == 1)
	{
		c2++;
		del = 1;
	}
	if (*ptr == 2)
	{
		c3++;
		pre = 1;
	}
	if (*ptr == 3)
	{
		c4++;
		in = 1;
	}
	if (*ptr == 4)
	{
		c5++;
		post = 1;
	}
	if (*ptr == 5)
	{
		c6++;
		ex = 1;
	}
}
void title()	 // to draw the starting screen
{
	printf("IN title Func \n\n\n");
	drawstring(5.0, 30.0, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", 6);
	drawstring(5.0, 28.0, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", 6);
	drawstring(5.0, 26.0, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~TREE TRAVERSAL TECHINQUES~~~~~~~~~~~~~~~~~~~~~~~~~~", 6);
	drawstring(5.0, 24.0, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", 6);
	drawstring(5.0, 22.0, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", 6);
	
	drawstring(20.0, 10.0, "SUBMITTED   BY", 0);
	drawstring(20.0, 8.0, "NAME: V R ROHITH", 0);
	drawstring(2.0, 2.0, "*  *LEFT CLICK THE MOUSE TO CONTINUE*  *", 3);
	glFlush();
}

void drawedge(int root, int i, int c)
{
	printf("IN drawedge Func\n");
	glColor3fv(color[c]);
	glBegin(GL_LINES);
	glVertex2f(a[root].x, a[root].y - rad);
	glVertex2f(a[i].x, a[i].y + rad);
	glEnd();
	glFlush();
}
