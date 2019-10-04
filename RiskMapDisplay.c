// Kevin Bechman

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

void display();
void init();
void mouse();


#define WIDTH 1000
#define HEIGHT 512
#define NUM_REGIONS 44

// Represents a pixel's RGB values and their associated region/name
struct pixel { int r, g, b, region; };

// 2D array of ints representing the map:
// Currently, they are being read in from a text file (the .java file)
int map[WIDTH][HEIGHT];

// Array of Pixels representing the possible regions:
static struct pixel regions[NUM_REGIONS];

int main( int argc, char** argv )
{
	
	glutInit( &argc, argv );
	glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB );
	glutInitWindowSize ( WIDTH, HEIGHT );
	glutInitWindowPosition ( 500, 500 );
	glutCreateWindow ( "Risk!" );
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	
	init();
	
	glutMainLoop();
	return 0;
}


void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT && state == GLUT_DOWN) {
		printf("Mouse pressed at (%d, %d)\n", x, y);
		int r = regions[map[x][y]].region;
		
		// Each case refers to a name to be printed at the title, 
		switch (r) {
			case 0: glutSetWindowTitle("Ocean"); break;
			case 1: glutSetWindowTitle("Alaska"); break;
			case 2: glutSetWindowTitle("Alberta"); break;
			case 3: glutSetWindowTitle("Central America"); break;
			case 4: glutSetWindowTitle("Eastern US"); break;
			case 5: glutSetWindowTitle("Greenland"); break;
			case 6: glutSetWindowTitle("Northwest Territory"); break;
			case 7: glutSetWindowTitle("Ontario"); break;
			case 8: glutSetWindowTitle("Quebec"); break;
			case 9: glutSetWindowTitle("Western US"); break;
			case 10: glutSetWindowTitle("Argentina"); break;
			case 11: glutSetWindowTitle("Brazil"); break;
			case 12: glutSetWindowTitle("Peru"); break;
			case 13: glutSetWindowTitle("Venezuela"); break;
			case 14: glutSetWindowTitle("Great Britain"); break;
			case 15: glutSetWindowTitle("Iceland"); break;
			case 16: glutSetWindowTitle("Northern Europe"); break;
			case 17: glutSetWindowTitle("Scandinavia"); break;
			case 18: glutSetWindowTitle("Southern Europe"); break;
			case 19: glutSetWindowTitle("Eastern Europe"); break;
			case 20: glutSetWindowTitle("Western Europe"); break;
			case 21: glutSetWindowTitle("Central Africa"); break;
			case 22: glutSetWindowTitle("Eastern Africa"); break;
			case 23: glutSetWindowTitle("Egypt"); break;
			case 24: glutSetWindowTitle("Madagascar"); break;
			case 25: glutSetWindowTitle("North Africa"); break;
			case 26: glutSetWindowTitle("South Africa"); break;
			case 27: glutSetWindowTitle("Afghanistan"); break;
			case 28: glutSetWindowTitle("China"); break;
			case 29: glutSetWindowTitle("India"); break;
			case 30: glutSetWindowTitle("Irkutsk"); break;
			case 31: glutSetWindowTitle("Japan"); break;
			case 32: glutSetWindowTitle("Kamchatka"); break;
			case 33: glutSetWindowTitle("Middle East"); break;
			case 34: glutSetWindowTitle("Mongolia"); break;
			case 35: glutSetWindowTitle("Siam"); break;
			case 36: glutSetWindowTitle("Siberia"); break;
			case 37: glutSetWindowTitle("Ural"); break;
			case 38: glutSetWindowTitle("Yakutsk"); break;
			case 39: glutSetWindowTitle("Eastern Australia"); break;
			case 40: glutSetWindowTitle("Indonesia"); break;
			case 41: glutSetWindowTitle("New Guinea"); break;
			case 42: glutSetWindowTitle("Western Australia"); break;
			case 43: break;
		}
	}
}

void display()
{
	glClear ( GL_COLOR_BUFFER_BIT );
	
	// Drawing the actual map, pixel-by-pixel:
	for (int x = 0; x < WIDTH; x++) {
		for (int y = 0; y < HEIGHT; y++) {
			int r = regions[map[x][y]].r;
			int g = regions[map[x][y]].g;
			int b = regions[map[x][y]].b;
			glBegin(GL_POINTS);
			    glColor3ub(r, g, b);	//
			    glVertex2i(x, y);
			glEnd();
		}
	}
	
	glFlush();
}

void init() {
	glClearColor ( 1.0, 1.0, 1.0, 1.0 );
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, WIDTH, HEIGHT, 0.0);
	
	// Read the integer-represented pixels from file
	FILE * infile;
	infile = fopen ("map_data.java","r");
	for(int x = 0; x < WIDTH; x++) {
		for(int y = 0; y < HEIGHT; y++) {
			fscanf(infile, "%i,", &map[x][y]);
		}
	}

	// Initializing the regions (produced with Java code)
	regions[0].r = 255; regions[0].g = 255; regions[0].b = 255; regions[0].region = 0;
	regions[1].r = 128; regions[1].g = 128; regions[1].b = 0; regions[1].region = 1;
	regions[2].r = 245; regions[2].g = 245; regions[2].b = 0; regions[2].region = 2;
	regions[3].r = 255; regions[3].g = 255; regions[3].b = 128; regions[3].region = 3;
	regions[4].r = 128; regions[4].g = 128; regions[4].b = 5; regions[4].region = 4;
	regions[5].r = 255; regions[5].g = 255; regions[5].b = 0; regions[5].region = 5;
	regions[6].r = 80; regions[6].g = 80; regions[6].b = 39; regions[6].region = 6;
	regions[7].r = 148; regions[7].g = 148; regions[7].b = 73; regions[7].region = 7;
	regions[8].r = 255; regions[8].g = 255; regions[8].b = 133; regions[8].region = 8;
	regions[9].r = 90; regions[9].g = 90; regions[9].b = 39; regions[9].region = 9;
	regions[10].r = 255; regions[10].g = 0; regions[10].b = 0; regions[10].region = 10;
	regions[11].r = 128; regions[11].g = 64; regions[11].b = 64; regions[11].region = 11;
	regions[12].r = 128; regions[12].g = 0; regions[12].b = 0; regions[12].region = 12;
	regions[13].r = 255; regions[13].g = 128; regions[13].b = 128; regions[13].region = 13;
	regions[14].r = 0; regions[14].g = 74; regions[14].b = 128; regions[14].region = 14;
	regions[15].r = 0; regions[15].g = 0; regions[15].b = 255; regions[15].region = 15;
	regions[16].r = 0; regions[16].g = 0; regions[16].b = 245; regions[16].region = 16;
	regions[17].r = 0; regions[17].g = 128; regions[17].b = 255; regions[17].region = 17;
	regions[18].r = 0; regions[18].g = 64; regions[18].b = 128; regions[18].region = 18;
	regions[19].r = 0; regions[19].g = 0; regions[19].b = 128; regions[19].region = 19;
	regions[20].r = 5; regions[20].g = 128; regions[20].b = 255; regions[20].region = 20;
	regions[21].r = 174; regions[21].g = 87; regions[21].b = 0; regions[21].region = 21;
	regions[22].r = 255; regions[22].g = 128; regions[22].b = 0; regions[22].region = 22;
	regions[23].r = 128; regions[23].g = 74; regions[23].b = 0; regions[23].region = 23;
	regions[24].r = 179; regions[24].g = 87; regions[24].b = 0; regions[24].region = 24;
	regions[25].r = 255; regions[25].g = 145; regions[25].b = 91; regions[25].region = 25;
	regions[26].r = 128; regions[26].g = 64; regions[26].b = 0; regions[26].region = 26;
	regions[27].r = 133; regions[27].g = 255; regions[27].b = 128; regions[27].region = 27;
	regions[28].r = 5; regions[28].g = 128; regions[28].b = 64; regions[28].region = 28;
	regions[29].r = 0; regions[29].g = 128; regions[29].b = 128; regions[29].region = 29;
	regions[30].r = 133; regions[30].g = 255; regions[30].b = 0; regions[30].region = 30;
	regions[31].r = 128; regions[31].g = 255; regions[31].b = 0; regions[31].region = 31;
	regions[32].r = 0; regions[32].g = 128; regions[32].b = 64; regions[32].region = 32;
	regions[33].r = 0; regions[33].g = 128; regions[33].b = 0; regions[33].region = 33;
	regions[34].r = 0; regions[34].g = 64; regions[34].b = 0; regions[34].region = 34;
	regions[35].r = 128; regions[35].g = 255; regions[35].b = 128; regions[35].region = 35;
	regions[36].r = 5; regions[36].g = 128; regions[36].b = 0; regions[36].region = 36;
	regions[37].r = 5; regions[37].g = 64; regions[37].b = 0; regions[37].region = 37;
	regions[38].r = 5; regions[38].g = 128; regions[38].b = 128; regions[38].region = 38;
	regions[39].r = 64; regions[39].g = 0; regions[39].b = 64; regions[39].region = 39;
	regions[40].r = 128; regions[40].g = 0; regions[40].b = 255; regions[40].region = 40;
	regions[41].r = 255; regions[41].g = 0; regions[41].b = 255; regions[41].region = 41;
	regions[42].r = 128; regions[42].g = 0; regions[42].b = 64; regions[42].region = 42;
	regions[43].r = 0; regions[43].g = 0; regions[43].b = 0; regions[43].region = 43;
}
