#include <GL/glut.h>
#include <MMSystem.h>
#include <bits/stdc++.h>


#include <iostream>
using std::cerr;
using std::endl;
#include <string>
using std::string;
#include <stdlib.h>  // Some versions of MS-Vis C++ have broken <cstdlib>
//using std::exit;
#include <sstream>
using std::ostringstream;
#include <iomanip>
using std::setfill;
using std::setw;
#include <GL/glut.h> // GLUT stuff, includes OpenGL headers as well


#define FPS 1


const int startwinsize = 400; // Starting window width & height, in pixels

// Keyboard
const int ESCKEY = 27;        // ASCII value of escape character

// Globals affecting display
bool showtext = true;         // True if text (help) is shown
bool startclock = true;       // True if clock is running
int hour=0, min=0, sec=0;     // time variables
string timestring="00:00:00";


#define PI 3.142

GLint i, j, k;
GLfloat sun_spin = 0, sun_x = 0, sun_y = 0, bird_spin = 0, sun_r = 0;
GLfloat ax = 0, bx = 0, cx = 0, dx = 0, str = 500.0, mn = 500.0, snailx1 = 0, snailx2 = 0;
GLfloat sr = 0.0, sg = 0.749, sb = 1.0;
GLfloat spin1 = 0.0;
GLfloat spin2 = 0.0;
GLfloat spin3 = 0.0;
GLfloat spin = 0.0, rotate_speed = .1;
GLfloat sky_spin = 0.0;


void init(void)
{
    glClearColor(.40, .110, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 1000.0, 0.0, 500.0);
	// gluOrthor2D(left, right, top, bottom): dinh nghia he truc toa do co gioi han
	/*
		left = 0
		top = 0
		right = 1000 
		bottom = 500
	*/
}
void printbitmap(const string msg, double x, double y)
{
   glRasterPos2d(x, y);
   for (string::const_iterator ii = msg.begin(); ii != msg.end(); ++ii)
   {
      glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *ii);
   }
}
///*** Circle_Model***///
void circle(GLdouble rad)
{
    GLint points = 50;
//    GLint points = 180;
    GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
//    GLdouble delTheta = (3.0 * PI) / (GLdouble)points;
    GLdouble theta = 0.0;

    glBegin(GL_POLYGON);
    {
        for (i = 0; i <= 50; i++, theta += delTheta)
        {
            glVertex2f(rad * cos(theta), rad * sin(theta));
        }
    }
    glEnd();
}
/// *** Sun_Model **///
void Sun_Model()
{
    glPushMatrix();
    glTranslatef(500, 0, 0);
    circle(sun_r);
    glPopMatrix();
}
void Moving_Sun_Model()
{
    glPushMatrix();
    glRotatef(-sun_spin, 0, 0, 1.0);
    Sun_Model();
    glPopMatrix();
}
///*** Cloud_Model***///
void cloud_model_one()
{

    glColor3f(1.25, 0.924, 0.930);

    /// Top_Left

    glPushMatrix();
    glTranslatef(320, 210, 0);
    circle(15);
    glPopMatrix();

    /// Top

    glPushMatrix();
    glTranslatef(340, 225, 0);
    circle(16);
    glPopMatrix();

    /// Right

    glPushMatrix();
    glTranslatef(360, 210, 0);
    circle(16);
    glPopMatrix();

    /// middle_Fill
    glPushMatrix();
    glTranslatef(355, 210, 0);
    circle(16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(350, 210, 0);
    circle(16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(345, 204, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(340, 204, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(335, 204, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(330, 204, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(325, 204, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(320, 204, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(315, 204, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(310, 204, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(305, 204, 0);
    circle(10);
    glPopMatrix();
}
void cloud_model_Two()
{
    glColor3f(1.25, 0.924, 0.930);

    /// Left_Part
    glPushMatrix();
    glTranslatef(305, 205, 0);
    circle(10);
    glPopMatrix();

    /// Top

    glPushMatrix();
    glTranslatef(320, 210, 0);
    circle(15);
    glPopMatrix();

    /// Right_Part
    glPushMatrix();
    glTranslatef(334, 207, 0);
    circle(10);
    glPopMatrix();

    /// Bottom_Part
    glPushMatrix();
    glTranslatef(320, 207, 0);
    circle(10);
    glPopMatrix();
}
void cloud_model_Three()
{
    glColor3f(1.25, 0.924, 0.930);

    /// Left_Part
    glPushMatrix();
    glTranslatef(300, 200, 0);
    circle(15);
    glPopMatrix();

    /// Top_Left

    glPushMatrix();
    glTranslatef(320, 210, 0);
    circle(15);
    glPopMatrix();

    /// Top
    glPushMatrix();
    glTranslatef(340, 220, 0);
    circle(16);
    glPopMatrix();

    /// Top_Right
    glPushMatrix();
    glTranslatef(360, 210, 0);
    circle(15);
    glPopMatrix();

    /// Right_Part
    glPushMatrix();
    glTranslatef(380, 200, 0);
    circle(15);
    glPopMatrix();

    /// Bottom_Right
    glPushMatrix();
    glTranslatef(360, 190, 0);
    circle(20);
    glPopMatrix();

    /// Bottom_Left
    glPushMatrix();
    glTranslatef(320, 190, 0);
    circle(20);
    glPopMatrix();

    /// Bottom
    glPushMatrix();
    glTranslatef(340, 190, 0);
    circle(20);
    glPopMatrix();

    ///****Fill End****
}
///*** Hill_Model***///
void hill_big()
{

    /// Hill
    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.41, 0.36);
    glVertex2i(70, 70);
    glVertex2i(200, 225);
    glVertex2i(330, 70);

    glEnd();

    /// Hill_Snow
    glBegin(GL_POLYGON);
    glColor3f(1.25, 0.924, 0.930);

    glVertex2i(200, 225);
    glVertex2i(230, 190);
    glVertex2i(220, 180);
    glVertex2i(200, 190);
    glVertex2i(190, 180);
    glVertex2i(170, 190);

    glEnd();
}
void hill_small()
{
    /// Hill_Small
    glBegin(GL_POLYGON);
    glColor3f(0.11, 0.23, 0.36);
    glVertex2i(250, 100);
    glVertex2i(310, 175);
    glVertex2i(370, 100);

    glEnd();

    /// Hill_Small_Snow
    glBegin(GL_POLYGON);
    glColor3f(1.25, 0.924, 0.930);
    glVertex2i(290, 150);
    glVertex2i(310, 175);
    glVertex2i(330, 150);
    glVertex2i(325, 140);
    glVertex2i(310, 150);
    glVertex2i(300, 140);

    glEnd();
}
///*** Tilla_Model ***///
void Tilla_One_Model()
{
    /// Tilla
    glBegin(GL_POLYGON);
    glColor3f(0.1, 1.293, 0.0);
    glVertex2i(125, 70);
    glVertex2i(150, 80);
    glVertex2i(160, 90);
    glVertex2i(170, 90);
    glVertex2i(180, 100);
    glVertex2i(190, 105);
    glVertex2i(200, 108);
    glVertex2i(300, 110);
    glVertex2i(300, 70);

    glEnd();
}
void Tilla_Two_Model()
{

    glColor3f(0.1, 1.293, 0.0);
    /// Left_Part
    glPushMatrix();
    glTranslatef(430, 90, 0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(420, 87, 0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(410, 80, 0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(400, 80, 0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(390, 70, 0);
    circle(30);
    glPopMatrix();

    /// Right_Part
    glPushMatrix();
    glTranslatef(445, 80, 0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(455, 75, 0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(465, 70, 0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(470, 65, 0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(480, 60, 0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(485, 55, 0);
    circle(20);
    glPopMatrix();
}
///*** House_Model ***///
void house()
{
    /// House_Roof
    glBegin(GL_POLYGON);
    glColor3f(.990, 0.0, 0.0);
    glVertex2i(285, 105);
    glVertex2i(285, 130);
    glVertex2i(380, 115);
    glVertex2i(380, 105);

    glEnd();

    /// House_Roof_Shadow
    glBegin(GL_POLYGON);
    glColor3f(.890, 0.0, 0.0);
    glVertex2i(285, 105);
    glVertex2i(285, 120);
    glVertex2i(380, 105);
    glVertex2i(380, 105);

    glEnd();

    /// House_Fence
    glBegin(GL_POLYGON);
    glColor3f(.555, 1.0, 1.0);
    glVertex2i(290, 70);
    glVertex2i(290, 104);
    glVertex2i(375, 104);
    glVertex2i(375, 70);

    glEnd();

    /// House_Fence_Shadow
    glBegin(GL_POLYGON);
    glColor3f(.555, 0.924, 0.930);
    glVertex2i(310, 70);
    glVertex2i(350, 104);
    glVertex2i(375, 104);
    glVertex2i(375, 70);

    glEnd();

    /// House_Door
    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.41, 0.36);
    glVertex2i(330, 70);
    glVertex2i(330, 100);
    glVertex2i(350, 100);
    glVertex2i(350, 70);
	
    glEnd();
    
   

    /// House_Window1
    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
//    glColor3f(0, 0, 1);
    glVertex2i(295, 75);
    glVertex2i(295, 90);
    glVertex2i(310, 90);
    glVertex2i(310, 75);

    glEnd();

    /// House_Window2
    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
    glVertex2i(312, 75);
    glVertex2i(312, 90);
    glVertex2i(327, 90);
    glVertex2i(327, 75);

    glEnd();

    /// House_Window3
    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
    glVertex2i(355, 75);
    glVertex2i(355, 90);
    glVertex2i(370, 90);
    glVertex2i(370, 75);

    glEnd();

    /// House_Small_Roof
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(250, 90);
    glVertex2i(257, 104);
    glVertex2i(290, 104);
    glVertex2i(290, 90);

    glEnd();

    /// House_Small_Fence
    glBegin(GL_POLYGON);
    glColor3f(.555, .724, .930);
    glVertex2i(255, 70);
    glVertex2i(255, 90);
    glVertex2i(290, 90);
    glVertex2i(290, 70);

    glEnd();

    /// House_Small_Door
    glBegin(GL_POLYGON);
    glColor3f(0.11, 0.23, 0.36);
    glVertex2i(260, 70);
    glVertex2i(260, 80);
    glVertex2i(285, 80);
    glVertex2i(285, 70);

    glEnd();    
}
// window_night_model
void window_night(){
	/// House_Window1
    glBegin(GL_POLYGON);
    glColor3f(1.2, 0.8, 0.0);
    glVertex2i(295, 75);
    glVertex2i(295, 90);
    glVertex2i(310, 90);
    glVertex2i(310, 75);

    glEnd();

    /// House_Window2
    glBegin(GL_POLYGON);
    glColor3f(1.2, 0.8, 0.0);
    glVertex2i(312, 75);
    glVertex2i(312, 90);
    glVertex2i(327, 90);
    glVertex2i(327, 75);

    glEnd();

    /// House_Window3
    glBegin(GL_POLYGON);
    glColor3f(1.2, 0.8, 0.0);
    glVertex2i(355, 75);
    glVertex2i(355, 90);
    glVertex2i(370, 90);
    glVertex2i(370, 75);

    glEnd();
}
void sky()
{
	glBegin(GL_POLYGON); 
	glColor3f(211.0/255, 136.0/255, 158.0/255);
	glVertex2i(-1000, 2000);
    glVertex2i(-1000, 1000000);
    glVertex2i(2000, 1000000);
    glVertex2i(2000, 2000);
	glEnd(); 
}
void sky_br()
{
	glBegin(GL_POLYGON); 
	glColor3f(211.0/255, 136.0/255, 158.0/255);
	glVertex2i(-1000, 0000);
    glVertex2i(-1000, 1000000);
    glVertex2i(2000, 1000000);
    glVertex2i(2000, 0000);
	glEnd(); 
}
// sky_night
void sky_night() {
	glPushMatrix();
    glTranslatef(0, -sky_spin, 0);
    sky();
    glPopMatrix();
}
///*** Field_Model ***///
void field()
{
    /// Field
    glBegin(GL_POLYGON);
    glColor3f(0.533, 1.293, 0.0);
    glVertex2i(0, 50);
    glVertex2i(0, 70);
    glVertex2i(1000, 70);
    glVertex2i(1000, 50);

    glEnd();

    /// Field_Shadow
    glBegin(GL_POLYGON);
    glColor3f(0.1, 1.293, 0.0);
    glVertex2i(0, 0);
    glVertex2i(0, 50);
    glVertex2i(1000, 50);
    glVertex2i(1000, 0);

    glEnd();
}
///*** Tree_Model ***///
void Tree_Model_One()
{

    glPushMatrix();
    glTranslatef(110, 110, 0);
    circle(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(110, 100, 0);
    circle(15);
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
    glVertex2f(109, 70);
    glVertex2f(109, 90);
    glVertex2f(111, 90);
    glVertex2f(111, 70);

    glEnd();
}
void Tree_Model_Two()
{
    glPushMatrix();
    glTranslatef(130, 130, 0);
    circle(5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(125, 126, 0);
    circle(5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(135, 126, 0);
    circle(5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(130, 125, 0);
    circle(5);
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
    glVertex2f(129, 110);
    glVertex2f(129, 124);
    glVertex2f(131, 124);
    glVertex2f(131, 110);

    glEnd();
}
void Tree_Model_Three()
{

    glBegin(GL_POLYGON);

    glVertex2f(125, 123);
    glVertex2f(133, 145);
    glVertex2f(141, 123);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
    glVertex2f(132, 110);
    glVertex2f(132, 124);
    glVertex2f(134, 124);
    glVertex2f(134, 110);

    glEnd();
}
/// *** Windmill_Stand_Model ***///
void Windmill_Stand_Model()
{
	glColor3f(0.38, 0.41, 0.5);
    glBegin(GL_POLYGON);
    glVertex2i(-7, 0);
	glVertex2i(-3, 145);
    glVertex2i(3, 145);
    glVertex2i(7, 0);
    glEnd();
}
///*** Windmill_Blades_Model ***///
void Windmill_Single_Blade() {
    glRotatef(spin, 0, 0, 90);
    glBegin(GL_POLYGON);
    glVertex2i(-1, 0);
    glVertex2i(0, 90);
    glVertex2i(2, 90);
    glVertex2i(7, 20);
    glVertex2i(1, 0);
    glEnd();
}

void Windmill_Blade()
{
    /// Blade_One

    glPushMatrix();
	Windmill_Single_Blade();
    glPopMatrix();

    /// Blade_Two
    glPushMatrix();
    glRotatef(120, 0, 0, 90);
	Windmill_Single_Blade();
    glPopMatrix();

    /// Blade_Three
    glPushMatrix();
    glRotatef(240, 0, 0, 90);
	Windmill_Single_Blade();
    glPopMatrix();
}
///*** Windmill_Final_Model ***///
void Windmill(int ver)
{

    /// Windmill_Stand
    glColor3f(0.38, 0.41, 0.36);
    glPushMatrix();
    glTranslatef(380, 100, 0);
    Windmill_Stand_Model();
    glPopMatrix();

    /// Windmill_Rotary_Blades
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(380, 251, 0);
    glRotatef(20*ver, 0, 0, 90);
    Windmill_Blade();
    glPopMatrix();
    
    /// Windmill_Motor
    glColor3f(0.11, 0.23, 0.66);
    glPushMatrix();
    glTranslatef(380, 250, 0);
    circle(8);
    glPopMatrix();
}
void Star() 
{
	glBegin(GL_POLYGON); 
    glColor3f(1.0, 0.8, 0.0);
	glVertex2i(180, 380);
    glVertex2i(220, 390);
    glVertex2i(180, 400);
    glVertex2i(170, 440);
    glVertex2i(160, 400);
    glVertex2i(120, 390);
    glVertex2i(160, 380);
    glVertex2i(170, 340);
	glEnd(); 
}
/// Model_End
///=======================================================================================================///

///=================///
///***   Object  ***///
///=================///

///*** Sun ***///
void Sun()
{
    glColor3f(1.0, 0.8, 0.0);
    glPushMatrix();
    Moving_Sun_Model();
    glPopMatrix();
}
///*** Cloud_One_Model_One ***///
void cloud_one()
{
    glPushMatrix();
    glTranslatef(cx, -40, 0);
    cloud_model_one();
    glPopMatrix();
}
///*** Cloud_Two_Model_one ***///
void cloud_two()
{
    glPushMatrix();
    glTranslatef(bx + 100, 150, 0);
    cloud_model_one();
    glPopMatrix();
}
///*** Cloud_Three_Model_Two ***///
void cloud_three()
{
    glPushMatrix();
    glTranslatef(ax - 80, 80, 0);
    cloud_model_Two();
    glPopMatrix();
}
///*** Cloud_Four_Model_Two ***///
void cloud_four()
{
    glPushMatrix();
    glTranslatef(dx + 300, 125, 0);
    cloud_model_Two();
    glPopMatrix();
}
///*** Cloud_Five_Model_Three ***///
void cloud_five()
{

    glPushMatrix();
    glTranslatef(ax + -300, 170, 0);
    cloud_model_Three();
    glPopMatrix();
}
///*** Cloud_Six_Model_Three ***///
void cloud_six()
{

    glPushMatrix();
    glTranslatef(cx + -500, 20, 0);
    cloud_model_Three();
    glPopMatrix();
}

///*** House_One ***///
void house_one(){
    glPushMatrix();
    glTranslatef(0,0,0);
    house();
    glPopMatrix();
}
///*** House_Two ***///
void house_two(){
    glPushMatrix();
    glTranslatef(450,0,0);
    house();
    glPopMatrix();
}
///*** House_Three ***///
void house_three(){
    glPushMatrix();
    glTranslatef(320, 37,0);
    house();
    glPopMatrix();
}
///*** Window_night_One ***///
void Window_one(){
    glPushMatrix();
    glTranslatef(0,0,0);
    window_night();
    glPopMatrix();
}
///*** Window_night_Two ***///
void Window_two(){
    glPushMatrix();
    glTranslatef(450,0,0);
    window_night();
    glPopMatrix();
}
///*** Window_night_Three ***///
void Window_three(){
    glPushMatrix();
    glTranslatef(320, 37,0);
    window_night();
    glPopMatrix();
}
///*** Hill_big_One ***///
void Hill_Big_One()
{
    glPushMatrix();
    glTranslatef(0, 0, 0);
    hill_big();
    glPopMatrix();
}
///*** Hill_big_Two ***///
void Hill_Big_Two()
{
    glPushMatrix();
    glTranslatef(550, -20, 0);
    hill_big();
    glPopMatrix();
}
///*** Hill_Small_One ***///
void Hill_Small_One()
{
    glPushMatrix();
    glTranslatef(0, 0, 0);
    hill_small();
    glPopMatrix();
}
/// *** Tilla_One_Model_One ***///

void Tilla_One()
{

    glPushMatrix();
    glTranslatef(0, 0, 0);
    Tilla_One_Model();
    glPopMatrix();
}
/// *** Tilla_Two_Model_Two ***///
void Tilla_Two()
{

    glPushMatrix();
    glTranslatef(0, 0, 0);
    Tilla_Two_Model();
    glPopMatrix();
}
/// *** Tilla_Three_Model_Two ***///
void Tilla_Three()
{

    glPushMatrix();
    glTranslatef(400, 0, 0);
    Tilla_Two_Model();
    glPopMatrix();
}
/// *** Tilla_Four_Model_One ***///
void Tilla_Four()
{

    glColor3f(0.833, 1., 0.0);
    glPushMatrix();
    glTranslatef(380, 0, 0);
    Tilla_One_Model();
    glPopMatrix();
}
///*** Tree_1 ***///
void Tree_One()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(0, 0, 0);
    Tree_Model_One();
    glPopMatrix();
}

///*** Tree_2 ***///
void Tree_Two()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(540, 0, 0);
    Tree_Model_One();
    glPopMatrix();
}

///*** Tree_3 ***///
void Tree_Three()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(750, 0, 0);
    Tree_Model_One();
    glPopMatrix();
}
///*** Tree_4 ***///
void Tree_Four()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(292, 40, 0);
    Tree_Model_One();
    glPopMatrix();
}

///*** Tree_5 ***///
void Tree_Five()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(30, -20, 0);
    Tree_Model_Two();
    glPopMatrix();
}

///*** Tree_6 ***///
void Tree_Six()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(50, -10, 0);
    Tree_Model_Two();
    glPopMatrix();
}
///*** Tree_7 ***///
void Tree_Seven()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(322, 0, 0);
    Tree_Model_Two();
    glPopMatrix();
}

///*** Tree_8 ***///
void Tree_Eight()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(350, -15, 0);
    Tree_Model_Two();
    glPopMatrix();
}

///*** Tree_9 ***///
void Tree_Nine()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(760, -25, 0);
    Tree_Model_Two();
    glPopMatrix();
}

///*** Tree_10 ***///
void Tree_Ten()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(90, -2, 0);
    Tree_Model_Three();
    glPopMatrix();
}

///*** Tree_11 ***///
void Tree_Eleven()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(125, 0, 0);
    Tree_Model_Three();
    glPopMatrix();
}

///*** Tree_12 ***///
void Tree_Twelve()
{
    glColor3f(0.533, 1.293, 0.0);
    glPushMatrix();
    glTranslatef(408, -22, 0);
    Tree_Model_Three();
    glPopMatrix();
}
/// * Windmill ***///
void Windmill_One()
{
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(0, -10, 0);
    Windmill(1);
    glPopMatrix();
}

void Windmill_Two()
{
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glScalef(.9f, .9f, 1.0f);
    glTranslatef(520, -5, 0);
    Windmill(2);
    glPopMatrix();
}
void Windmill_Three()
{
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glScalef(.8f, .8f, 1.0f);
    // glTranslatef(108, -90, 0);
    glTranslatef(300, 0, 0);
    Windmill(3);
    glPopMatrix();
}
///*** Star ***///
void Star_one()
{
    glPushMatrix();
    glTranslatef(0, 0, 0);
    Star();
    glPopMatrix();
}
void snail_model1()
{
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    
    glTranslatef(10, 0, 0); // thay doi he truc toa do sang vi tri moi co cac gia tri tuong ung la 
    glBegin(GL_POLYGON);
    glColor3f(238.0/255, 238.0/255, 238.0/255);
    glVertex2i(60, 50);
    glVertex2i(110, 50);  
    glVertex2i(100, 65); // top
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(249.0/255, 215.0/255, 215.0/255);
    glVertex2i(65, 50);
    glVertex2i(108, 50);  
    glVertex2i(99, 63); // top
    glEnd();
    
    glTranslatef(70, 65, 0);
    glColor3f(180.0/255, 137.0/225, 137.0/255);
    circle(18);
    glColor3f(249.0/255, 215.0/225, 215.0/255);
    circle(10);
    glPopMatrix();
}
void snail1()
{
    glPushMatrix();
    glTranslatef(snailx1 + 10, 0, 0);
    snail_model1();
    glPopMatrix();
}
void snail_model2()
{
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    
    glTranslatef(300, 0, 0); // thay doi he truc toa do sang vi tri moi co cac gia tri tuong ung la 
    glBegin(GL_POLYGON);
    glColor3f(238.0/255, 238.0/255, 238.0/255);
    glVertex2i(65, 50);
    glVertex2i(107, 50);  
    glVertex2i(100, 62); // top
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(249.0/255, 215.0/255, 215.0/255);
    glVertex2i(70, 50);
    glVertex2i(105, 50);  
    glVertex2i(99, 60); // top
    glEnd();
    
    glTranslatef(70, 65, 0);
    glColor3f(180.0/255, 137.0/225, 137.0/255);
    circle(15);
    glColor3f(249.0/255, 215.0/225, 215.0/255);
    circle(9);
    glPopMatrix();
}
void snail2()
{
    glPushMatrix();
    glTranslatef(snailx2 + 10, 0, 0);
    snail_model2();
    glPopMatrix();
}
// bird model
void Bird_model1()
{
    glColor3f(0.1, 0.23, 0.36);
    glPushMatrix();
    
    glTranslatef(500, 0, 0); // thay doi he truc toa do sang vi tri moi co cac gia tri tuong ung la 
    glBegin(GL_POLYGON);
	    glColor3f(46.0/255, 119.0/255, 134.0/255);
		glVertex2i(205, 50);
	    glVertex2i(220, 5);  
	    glVertex2i(200, 30);
    glEnd();
    
    // doi xung
	glBegin(GL_POLYGON);
	    glColor3f(104.0/255, 152.0/255, 161.0/255);
		glVertex2i(205, 50);
	    glVertex2i(165, 20);  
	    glVertex2i(200, 30);
    glEnd();
    

    glPopMatrix();
}

//  2
void Bird_model2()
{
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    
    glTranslatef(650, 0, 0); // thay doi he truc toa do sang vi tri moi co cac gia tri tuong ung la 
    glBegin(GL_POLYGON);
	    glColor3f(46.0/255, 119.0/255, 134.0/255);
		glVertex2i(205/2, 50/2);
	    glVertex2i(220/2, 5/2);  
	    glVertex2i(200/2, 30/2);
    glEnd();
    
    // doi xung
	glBegin(GL_POLYGON);
	    glColor3f(104.0/255, 152.0/255, 161.0/255);
		glVertex2i(205/2, 50/2);
	    glVertex2i(165/2, 20/2);  
	    glVertex2i(200/2, 30/2);
    glEnd();
    

    glPopMatrix();
}
void Bird_model3()
{
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    
    glTranslatef(680, 10, 0); // thay doi he truc toa do sang vi tri moi co cac gia tri tuong ung la 
    glBegin(GL_POLYGON);
	    glColor3f(46.0/255, 119.0/255, 134.0/255);
		glVertex2i(205/1.5, 50/1.5);
	    glVertex2i(220/1.5, 5/1.5);  
	    glVertex2i(200/1.5, 30/1.5);
    glEnd();
    
    // doi xung
	glBegin(GL_POLYGON);
	    glColor3f(104.0/255, 152.0/255, 161.0/255);
		glVertex2i(205/1.5, 50/1.5);
	    glVertex2i(165/1.5, 20/1.5);  
	    glVertex2i(200/1.5, 30/1.5);
    glEnd();
    

    glPopMatrix();
}

// bird moving
void Moving_bird_model1()
{
    glPushMatrix();
//    glRotatef(-bird_spin, 0, 0, -.009);
	glRotatef(bird_spin, 0, 0, 1.0); // duong nguoc am cung
    Bird_model1();
    glPopMatrix();
}
void bird1(){
	glColor3f(1, 1, 0);
    glPushMatrix();
    Moving_bird_model1();
    glPopMatrix();
}
void Moving_bird_model2()
{
    glPushMatrix();
//    glRotatef(-bird_spin, 0, 0, -.009);
	glRotatef(bird_spin, 0, 0, 1.0); // duong nguoc am cung
    Bird_model2();
    glPopMatrix();
}
void bird2(){
	glColor3f(1, 1, 0);
    glPushMatrix();
    Moving_bird_model2();
    glPopMatrix();
}
void Moving_bird_model3()
{
    glPushMatrix();
//    glRotatef(-bird_spin, 0, 0, -.009);
	glRotatef(bird_spin, 0, 0, 1.0); // duong nguoc am cung
    Bird_model3();
    glPopMatrix();
}
void bird3(){
	glColor3f(1, 1, 0);
    glPushMatrix();
    Moving_bird_model3();
    glPopMatrix();
}
/// Object_End
///=========================================================================================================///

///========================///
///*** Display Function ***///
///========================///

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 1.0);

    ///*** Object_Layer ***///
    Sun();
    if(timestring[6] >= '1') sky_night();
    if(timestring[4] >= '1') sky_br();
    if(timestring[4] >= '1') Star_one();

    Windmill_Three();

    Hill_Big_One();
    Tilla_Four();

    house_three();
    if(timestring[4] >= '1') Window_three();

 	bird1();
	bird2();
	bird3();
    Hill_Big_Two();
   
    Hill_Small_One();

    cloud_three();
    cloud_four();

    Windmill_One();
    Windmill_Two();


    Tilla_One();
    Tilla_Two();
    Tilla_Three();


    house_one();
    if(timestring[4] >= '1') Window_one();
    cloud_one();
    house_two();
    if(timestring[4] >= '1') Window_two();

    Tree_One();
    Tree_Two();
    Tree_Three();
    Tree_Four();
    Tree_Five();
    Tree_Six();
    Tree_Seven();
    Tree_Eight();
    Tree_Nine();
    Tree_Ten();
    Tree_Eleven();
    Tree_Twelve();



    cloud_two();
    cloud_five();
    cloud_six();
    field();
    
    snail1();
    snail2();
//	Bird_model1();
//	bird1();
//	bird2();
//	bird3();
//	Bird_model2();
//	printbitmap(timestring, 500, 400);
	
    glFlush();
}
// set timer
void myTimer(int v)     // timer function to update time
{
    ostringstream timestream;      // used to format time string
    if (startclock) sec++;         // increment second
    if (sec==60) { min++; sec=0; } // increment minute
    if (min==60) { hour=hour++ % 24; min=0; } //increment hour
    timestream << setfill('0') << setw(2) << hour <<":" << setw(2)
               << min << ":" << setw(2) << sec;
    timestring=timestream.str();  //convert stream to string
    glutPostRedisplay();
    glutTimerFunc(1000/v, myTimer, v);  //repost timer 
}
///========================///
///*** Speed & Movement ***///
///========================///
///*** Sun_Move ***///
void sun_move()
{
    sun_spin = sun_spin + 0.005;
    sun_r += 0.15;
}
// bird move
void bird_move()
{
    bird_spin = bird_spin + .0019;
}
void move_right()
{
	spin = spin - rotate_speed;
    sun_move();
    bird_move();
    sky_spin = sky_spin + 0.15;

    spin1 = spin1 + .1;
    spin2 = spin2 + .15;
    spin3 = spin3 + .241;
    ax = ax + .05;
    bx = bx + .08;
    cx = cx + .10;
    dx = dx + .15;
    snailx1 = snailx1 + .025;
    snailx2 = snailx2 + .005;

    if (cx > 1000)
    {
        cx = -300;
    }
    if (bx > 1000)
    {
        bx = -400;
    }
    if (cx > 1000)
    {
        cx = -400;
    }
    if (dx > 1000)
    {
        dx = -500;
    }

    glutPostRedisplay(); // thong bao cho chuong trinh rang, can phai thuc hien viec ve lai
}
void mouse(int key, int state, int x, int y)
{
	
    switch (key)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(move_right);
            PlaySound("sang-amthanh.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC); // repeat many time
        }
        break;
    case GLUT_MIDDLE_BUTTON:
    case GLUT_RIGHT_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(NULL);
            PlaySound(0, 0, 0);
//			PlaySound(NULL, NULL, SND_ASYNC);
//			PlaySound(NULL, 0, 0);  
        }
        break;
    default:
        break;
    }
}
void keyboard(int key, int x, int y) {
	switch (key) {
		case 101:
			//cout << "GLUT_KEY_UP " << key << endl;
			rotate_speed += .1;
			break;
		case 103:
			//cout << "GLUT_KEY_DOWN " << key << endl;
			rotate_speed -= .1;
			break;
	}
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    //    glutInitWindowPosition(50, 50);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 1920) / 2,
                           (glutGet(GLUT_SCREEN_HEIGHT) - 1080) / 2);
//    glutInitWindowSize(1900, 1080);
	
    glutCreateWindow("Smart Village");
    init();
    glutDisplayFunc(display);
//    if(timestring[6] >= '1')	window_night();
//    window_night();
    glutMouseFunc(mouse);
    glutSpecialFunc(keyboard);
    glutTimerFunc(1000,myTimer,FPS);
    glutFullScreen();
//    sndPlaySound("sang-amthanh.wav", SND_ASYNC);
    glutMainLoop();
}
