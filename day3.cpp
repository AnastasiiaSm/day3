#include <iostream>
#include <cmath>
#include <cstdlib>

//������� 6

//������� 2

//����������� ��������� ��� ������������� ������ ���������� �� ��������� v ������ ������ m.
//��� ���������� � ������ ����� ���������.

const float g = 9.8;

struct Ball {
//  float h=rand() % 100 + 100; //������ �� 100 �� 200
  float h=100;
  float x=0;
  float y=0;
//  float vx=rand() % 100; //�������� �� 0 �� 100
  float vx=10;
  float vy=0;
  float ax=0;
  float ay=-g;
  float m=0;

  Ball() {
  }
};

float time = 0;
float dtime = 0;

// ������������� ��������� ��������� ������ �� ����� dt � ��������
void move(Ball* ball, float dt) {
	
	dtime = dtime + dt;
	ball->vy += (ball->ay) * dtime;
	ball->y = ball->h + ball->ay * (dtime * dtime) / 2;
	ball->ax = 0;
	ball->x += ball->vx * dt;
	if (ball->y > 0)
		time = dtime;
	if (ball->y <= 0) {
		ball->y = 0;
		ball->vy = 0;
		ball->vx = 0;
	}
}

// ���������� �� ����� ��������� ������ ������
void show(Ball ball) {
	std::cout << "y = " << ball.y << " Vy = " << abs(ball.vy) << " ay = " << abs(ball.ay) << std::endl;
	std::cout << "x = " << ball.x << " Vx = " << abs(ball.vx) << " ax = " << abs(ball.ax) << std::endl;
}

struct Image {
	int mx;
	int my;
	int* points;
};

void CreateImage(Image* img, int tmx, int tmy) {
	img->mx = tmx;
	img->my = tmy;
	img->points = new int[tmx * tmy]{ 1 };
}

void SetPointImage(Image* img, int x, int y, int color) {
	img->points[(y * img->mx + x)] = color;
}

int GetPointImage(Image* img, int x, int y) {
	return img->points[(y * img->mx + x)];
}

void ShowImage(Image* img) {
	for (int i = 0; i < img->my; i++) {
		for (int j = 0; j < img->mx; j++) 	
			std::cout << img->points[i * img->mx + j] << " ";
		std::cout << std::endl;
	}
}

int main() {
  float t = 0;
  Ball a;
  float deltaT = 1;
  for (int i=0; i<10; i++) {
     move(&a, deltaT);
     std::cout << t << std::endl;
     show(a);
     t = t + deltaT;           // ��������� ������� �������
  }
}
