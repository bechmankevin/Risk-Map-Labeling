/** Kevin Bechman
Risk Map
Objectives:
	- display a risk map using C code and OpenGL
	- when the mouse is clicked over a territory, display the territory's name in the title bar of the window (or that it's in the ocean)

Plan:
	Displaying the map
	- Edit the map so that all territories are different colors
	- Use Java to analyze the picture of the map pixel by pixel, recording the RNG values in a manner compatible with C (in a 2D array of RGB structs?)
	- The 2d array of pixels can then be displayed using a nested for loop and glVertex2i() functions

	Identifying the region:
	- Manually record the RGB values of all the regions, assigning a unique integer and string to each RGB value
	- When parsing the image for RGB values, test the RGB values to see if they match one of the existing regions
	- For each pixel parsed, assign these values to a struct in a 2D array, at location (x, y) in the array:
		[short or byte (representing the region ID), and
		 R, G, B short/byte values]
*/


/**
C code:

// Represents a pixel and its associated region
struct pixel { int r, g, b, region; string name}

// Various constants:
const int WIDTH = 1000;
const int HEIGHT = 512;
const int NUM_REGIONS = ?;

// Have a function which takes args: RGB values, and returns a region #
// That way, when drawing the map, only the single int value of the region is needed, which can then be used to access the RGB info from the 'regions' array.

// The array of (region #) -> (string, RGB) mappings will go here as well : regions[5].name = "Spain", regions[5].r = "140" 
struct pixel regions [NUM_REGIONS] = {
	{150,0,0,5},	// if Spain is 5
	{},
}
// ***NOTE: THIS WON'T BE USED:***
// 2D array of pixels representing the whole map:
struct pixel map[WIDTH][HEIGHT] = {
	{0,255,255,4},{0,255,255,4}			// These will be outputted to a text file from Java
}

// 2D array of ints representing the map:
int map[WIDTH][HEIGHT] = {
	7,7,7,7,7,7,8,5,5,5,5,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
}

// Drawing the actual map, pixel-by-pixel:
for (int y = 0; y < S_HEIGHT; y++) {
	for (int x = 0; x < S_WIDTH; x++) {
		// struct pixel p = regions[map[x][y]];
		int r = regions[map[x][y]].r;
		int g = regions[map[x][y]].g;
		int b = regions[map[x][y]].b;
		glColor3i(r, g, b);
		glBegin(GL_POINTS);
			glVertex2i();
		glEnd();
	}
}

*/

import java.io.*;
import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.awt.Color;
import java.lang.String;
import java.io.BufferedWriter;

public class RiskMap {
	public static class Pixel {
		int r, g, b, region;
		String name;
		public Pixel (int r1, int g1, int b1, int region1, String name1) {
			r = r1; g = g1; b = b1; region = region1; name = name1;
		}
		public boolean equals(Object o) {
			Pixel p = (Pixel)o;
			if (this.r == p.r && this.g == p.g && this.b == p.b && this.region == p.region)
				return true;
			return false;
		}
		
		public boolean eq(int r_, int g_, int b_) {
			if (this.r == r_ && this.g == g_ && this.b == b_)
				return true;
			return false;
		}
	}
	
	// Constants/Mappings: 
	//public final static int S_WIDTH = 500;
	//public final static int S_HEIGHT = 256;
	public final static int NUM_REGIONS = 44;
	public final static int UNKNOWN_REGION = 43;
	
	public final static Pixel[] regions = new Pixel[NUM_REGIONS];
	
	// Assign a Pixel object containing RGB and region values to an array index representing the region
	public static void initRegions() {
		regions[0] = new Pixel(255, 255, 255, 0, "Ocean");
		regions[1] = new Pixel(128, 128, 0, 1, "Alaska");
		regions[2] = new Pixel(245, 245, 0, 2, "Alberta");
		regions[3] = new Pixel(255, 255, 128, 3, "Central America");
		regions[4] = new Pixel(128, 128, 5, 4, "Eastern US");
		regions[5] = new Pixel(255, 255, 0, 5, "Greenland");
		regions[6] = new Pixel(80, 80, 39, 6, "Northwest Territory");
		regions[7] = new Pixel(148, 148, 73, 7, "Ontario");
		regions[8] = new Pixel(255, 255, 133, 8, "Quebec");
		regions[9] = new Pixel(90, 90, 39, 9, "Western US");
		regions[10] = new Pixel(255, 0, 0, 10, "Argentina");
		regions[11] = new Pixel(128, 64, 64, 11, "Brazil");
		regions[12] = new Pixel(128, 0, 0, 12, "Peru");
		regions[13] = new Pixel(255, 128, 128, 13, "Venezuela");
		regions[14] = new Pixel(0, 74, 128, 14, "Great Britain");
		regions[15] = new Pixel(0, 0, 255, 15, "Iceland");
		regions[16] = new Pixel(0, 0, 245, 16, "Northern Europe");
		regions[17] = new Pixel(0, 128, 255, 17, "Scandinavia");
		regions[18] = new Pixel(0, 64, 128, 18, "Southern Europe");
		regions[19] = new Pixel(0, 0, 128, 19, "Eastern Europe");
		regions[20] = new Pixel(5, 128, 255, 20, "Western Europe");
		regions[21] = new Pixel(174, 87, 0, 21, "Central Africa");
		regions[22] = new Pixel(255, 128, 0, 22, "Eastern Africa");
		regions[23] = new Pixel(128, 74, 0, 23, "Egypt");
		regions[24] = new Pixel(179, 87, 0, 24, "Madagascar");
		regions[25] = new Pixel(255, 145, 91, 25, "North Africa");
		regions[26] = new Pixel(128, 64, 0, 26, "South Africa");
		regions[27] = new Pixel(133, 255, 128, 27, "Afghanistan");
		regions[28] = new Pixel(5, 128, 64, 28, "China");
		regions[29] = new Pixel(0, 128, 128, 29, "India");
		regions[30] = new Pixel(133, 255, 0, 30, "Irkutsk");
		regions[31] = new Pixel(128, 255, 0, 31, "Japan");
		regions[32] = new Pixel(0, 128, 64, 32, "Kamchatka");
		regions[33] = new Pixel(0, 128, 0, 33, "Middle East");
		regions[34] = new Pixel(0, 64, 0, 34, "Mongolia");
		regions[35] = new Pixel(128, 255, 128, 35, "Siam");
		regions[36] = new Pixel(5, 128, 0, 36, "Siberia");
		regions[37] = new Pixel(5, 64, 0, 37, "Ural");
		regions[38] = new Pixel(5, 128, 128, 38, "Yakutsk");
		regions[39] = new Pixel(64, 0, 64, 39, "Eastern Australia");
		regions[40] = new Pixel(128, 0, 255, 40, "Indonesia");
		regions[41] = new Pixel(255, 0, 255, 41, "New Guinea");
		regions[42] = new Pixel(128, 0, 64, 42, "Western Australia");
		regions[43] = new Pixel(0, 0, 0, 43, "Unknown");
	}
	
	// Main function for running the image analyzer
	public static void runImageAnalyzer() throws IOException {
		BufferedWriter writer = new BufferedWriter(new FileWriter("map_data.java"));
		BufferedImage img = getImage("map_edited.png");
		StringBuilder sb = new StringBuilder();
		Color color;
		int num;
		char ch;
		// Parses the entire image pixel by pixel, assigning a number to the pixel representing its region
		// in the regions[] array above.  The list of numbers are printed to the map_data file.
		for(int x = 0; x < img.getWidth(); x++) {
			for(int y = 0; y < img.getHeight(); y++) {
				color = new Color(img.getRGB(x, y));
				num = getRegion(color.getRed(), color.getGreen(), color.getBlue());
				sb.append(num);
				sb.append(',');
			}
		}
		writer.write(sb.toString());
		writer.close();
	}
	
	// Generates C code for initializing the region values
	public static void genInitCode() throws IOException {
		BufferedWriter writer = new BufferedWriter(new FileWriter("initCode.java"));
		String str = "";
		for (int i=0; i<NUM_REGIONS; i++) {
			str += "regions["+i+"].r = " + regions[i].r + "; regions["+i+"].g = "+regions[i].g + "; regions["+i+"].b = "+regions[i].b + "; regions["+i+"].region = " + i + ";\n";
		}
		str += "\n\n";
		
		for (int i=0; i<NUM_REGIONS; i++) {
			str += "case " + i + ": glutSetWindowTitle(\"" + regions[i].name + "\"); break;\n";
		}
		writer.write(str);
		writer.close();
	}
	
	// Loads the image at the specified filename into the program
	public static BufferedImage getImage(String fname) throws IOException {
		try {
			return ImageIO.read(new File(fname));
		} catch(IOException e) {
			System.out.println("Error: File not found.");
		}
		return null;
	}
	
	// Returns the region ID given RGB values
	public static int getRegion(int r, int g, int b) {
		// Check through the list of regions to find the matching RGB values
		Pixel pix;
		for(int i=0; i<NUM_REGIONS; i++) {
			pix = regions[i];
			if(pix.eq(r, g, b))
				return pix.region;
		}
		//System.out.println("Error: No region found!");
		return UNKNOWN_REGION;
	}
	
	
	
	
	public static void main(String args[]) throws IOException {
		initRegions();
		runImageAnalyzer();
		//genInitCode();
	}
}