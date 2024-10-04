/* Display colored leaves falling down the screen to create fall-themed scenery */


// NOTE: The base code to create a leaf shape and have it move down the screen was done with the assistance of ChatGPT
// All following edits (multiple leaves, colors, staggered falling, etc.) were entirely my own original work

#include <TFT_eSPI.h>  // Include the graphics library (this includes the sprite functions)

// Create an instance of the TFT display
TFT_eSPI tft = TFT_eSPI();  

// Set dimensions of the leaf
const int leafWidth = 10;  // Width of the leaf
const int leafHeight = 15; // Height of the leaf

int leafY = 0; // Initial vertical position of highest leaf from bottom of screen
int leafYl[5] = {0,10,30,50,70}; // Possible vertical positions of the leaves
uint16_t colors[5] = {TFT_RED, TFT_ORANGE, TFT_YELLOW, TFT_OLIVE, TFT_MAROON};

// Function to draw a leaf shape
void drawLeaf(int x, int y, uint16_t leafColor) {
    tft.fillEllipse(x, y, leafWidth / 2, leafHeight / 2, leafColor); // Draw the upper part of the leaf
    tft.fillTriangle(x - leafWidth / 2, y, x + leafWidth / 2, y, x, y + leafHeight, leafColor); // Draw the lower part
}

void setup() {
    // Initialize the display
    tft.init();
    tft.setRotation(1); 
    tft.fillScreen(TFT_BROWN); // Set the background color as brown to represent crushed fall foliage
}

void loop() {
    // Clear the previous leaf position with brown screen
    tft.fillScreen(TFT_BROWN);
    
    // Draw 5 leaves across the screen, each 1/6th of the screen width apart
    int div = tft.width() / 6;

    // Use random number generators to display different leaves in different vertical locations & colors
    drawLeaf(div, leafY + leafYl[random(0,5)], colors[random(0,5)]);
    drawLeaf(div*4, leafY + leafYl[random(0,5)], colors[random(0,5)]);
    drawLeaf(div*2, leafY + leafYl[random(0,5)], colors[random(0,5)]);
    drawLeaf(div*5, leafY + leafYl[random(0,5)], colors[random(0,5)]);
    drawLeaf(div*3, leafY + leafYl[random(0,5)], colors[random(0,5)]);
    
    leafY += 5; // Move all leaves down by 5 pixels

    // Reset position if it goes off the screen
    if (leafY > tft.height()) {
        leafY = 0; // Reset to the top
    }
    
    // Delay for a smoother animation
    delay(300);
}
