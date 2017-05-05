float clock = 0;
float clockLips = 0;
boolean up = true;
PImage textureTriangle;
PImage textureEar;

void setup() {
  size(1080, 1080, P3D);
  textureTriangle = loadImage("textureTriangle.jpg");
  textureEar = loadImage("textureEar.jpg");
}

void drawCircle(int x, int y, int z, int size, color c) {
  pushMatrix();
  noStroke();
  fill(c);
  translate(x, y, z);
  sphere(size);
  popMatrix();
}

void drawEyeRight(int x, int y, int z, int size, color c) {
  pushMatrix();
  noStroke();
  fill(c);
  translate(x, y, 0);
  rotateZ(clock * 2);
  translate(5, 0, z);
  sphere(size);
  popMatrix();
}

void drawEyeLeft(int x, int y, int z, int size, color c) {
  pushMatrix();
  noStroke();
  fill(c);
  translate(x, y, 0);
  rotateX(clock * 2);
  translate(0, 0, z);
  sphere(size);
  popMatrix();
}

void drawTriangle(int x, int y, int z, int size) {
  pushMatrix();
  translate(x, y, z);
  rotateY(50);
  rotateX(PI/2);
  
  stroke(255);
  
  beginShape();
  texture(textureTriangle);
  vertex(-size, -size, -size, 0, 0);
  vertex( size, -size, -size, 0, size);
  vertex(   0,    0,  size, size, 0);
  endShape();

  beginShape();
  texture(textureTriangle);
  vertex( size, -size, -size, 0, 0);
  vertex( size,  size, -size, 0, size);
  vertex(   0,    0,  size, size, 0);
  endShape();

  beginShape();
  texture(textureTriangle);
  vertex( size, size, -size, 0, 0);
  vertex(-size, size, -size, 0, size);
  vertex(   0,   0,  size, size, 0);
  endShape();


  beginShape();
  texture(textureTriangle);
  vertex(-size,  size, -size, 0, 0);
  vertex(-size, -size, -size, 0, size);
  vertex(   0,    0,  size, size, 0);
  endShape();
  
  popMatrix();
}

void drawUpLip(float w, float h, float d, float x, float y, color c) {
  pushMatrix();
  noStroke();
  fill(c);
  translate(x, y, 0);
  translate(0, clockLips * 2, 0);
  box(w, h, d);
  popMatrix();
}

void drawDownLip(float w, float h, float d, float x, float y, color c) {
  pushMatrix();
  noStroke();
  fill(c);
  translate(x, y, 0);
  translate(0, -clockLips * 2, 0);
  box(w, h, d);
  popMatrix();
}

void drawEar(float x, float y, float z, int size) {
  pushMatrix();
  translate(x, y, z);
  
  beginShape(QUADS);
  texture(textureEar);
  
  vertex(-size, -size,  size, 0, 0);
  vertex( size, -size,  size, size, 0);
  vertex( size,  size,  size, size, size);
  vertex(-size,  size,  size, 0, size);

  vertex( size, -size, -size, 0, 0);
  vertex(-size, -size, -size, size, 0);
  vertex(-size,  size, -size, size, size);
  vertex( size,  size, -size, 0, size);

  vertex(-size,  size,  size, 0, 0);
  vertex( size,  size,  size, size, 0);
  vertex( size,  size, -size, size, size);
  vertex(-size,  size, -size, 0, size);

  vertex(-size, -size, -size, 0, 0);
  vertex( size, -size, -size, size, 0);
  vertex( size, -size,  size, size, size);
  vertex(-size, -size,  size, 0, size);

  vertex( size, -size,  size, 0, 0);
  vertex( size, -size, -size, size, 0);
  vertex( size,  size, -size, size, size);
  vertex( size,  size,  size, 0, size);

  vertex(-size, -size, -size, 0, 0);
  vertex(-size, -size,  size, size, 0);
  vertex(-size,  size,  size, size, size);
  vertex(-size,  size, -size, 0, size);

  endShape();
  
  popMatrix();
}

void draw() {
  clock += 0.025;
  if (clock == 360)
    clock = 0;
    
  if (up) {
    clockLips -= 1;
    if (clockLips == -5)
      up = false;
  } else {
    clockLips += 1;
    if (clockLips == 5)
      up = true;
  }
  
  spotLight(255, 255, 255, 0, height, 300, -1, -1, 0, PI/2, 0.001);
  spotLight(255, 255, 255, width / 2, height, 300, 0, -1, 0, PI/2, 0.001);
  spotLight(255, 255, 255, width, height, 300, 1, -1, 0, PI/2, 0.001);
  background(#424242);
  drawCircle(width / 2 - width / 10, height / 2 - height / 8, 0, 50, #FFFFFF);
  drawEyeLeft(width / 2 - width / 10, height / 2 - height / 8, 17, 35, #111111);
  drawCircle(width / 2 + width / 10, height / 2 - height / 8, 0, 50, #FFFFFF);
  drawEyeRight(width / 2 + width / 10, height / 2 - height / 8, 17, 35, #111111);
  drawEar(width / 2 - width / 4, height / 2 - height / 8 + 30, 0, 30);
  drawEar(width / 2 + width / 4, height / 2 - height / 8 + 30, 0, 30);
  drawTriangle(width / 2, height / 2, -50, 75);
  drawUpLip(width / 4, width / 20, width / 12, width / 2, height / 2 + height / 6, #F44336);
  drawDownLip(width / 4, width / 20, width / 12, width / 2, height / 2 + height / 4, #F44336);
}