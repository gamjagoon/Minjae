#include <iostream>
using namespace std;

//S ���� R ���� P ��

char str[4];
int main() {
	cin >>str[0] >>str[1] >> str[2] >> str[3];
	if (str[0] == str[1] && str[2] == str[3]) {
		if (str[0] == str[2])printf("?");
		else if (str[0] == 'S') {
			if (str[2] == 'R')printf("TK");
			else printf("MS");
		}
		else if (str[0] == 'R') {
			if (str[2] == 'P')printf("TK");
			else printf("MS");
		}
		else {
			if (str[2] == 'S')printf("TK");
			else printf("MS");
		}
	}
	//S ���� R ���� P ��
	else if (str[0] == str[1]){
		if (str[0] == 'S') {
			if (str[2] == 'R' || str[3] == 'R')printf("TK");
			else {
				printf("?");
			}
		}
		else if (str[0] == 'R') {
			if (str[2] == 'P' || str[3] == 'P')printf("TK");
			else {
				printf("?");
			}
		}
		else {
			if (str[2] == 'S' || str[3] == 'S')printf("TK");
			else {
				printf("?");
			}
		}
	}
	//S ���� R ���� P ��
	else if (str[2] == str[3]) {
		if (str[2] == 'S') {
			if (str[0] == 'R' || str[1] == 'R')printf("MS");
			else {
				printf("?");
			}
		}
		else if (str[2] == 'R') {
			if (str[0] == 'P' || str[1] == 'P')printf("MS");
			else {
				printf("?");
			}
		}
		else {
			if (str[0] == 'S' || str[1] == 'S')printf("MS");
			else {
				printf("?");
			}
		}
	}
	else {
		printf("?");
	}
	return 0;
}