#include <iostream>

using namespace std;

void rotate(char grille[10][10], int size) {
	char rotated[10][10];
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			rotated[j][size-i-1] = grille[i][j];
		}
	}

	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			grille[i][j] = rotated[i][j];
		}
	}

	return;
}

bool isValid(char grille[10][10], int size) {
	char marked[10][10] = {0};
	for(int k = 0; k < 4; k++) {
        	for(int i = 0; i < size; i++) {
                	for(int j = 0; j < size; j++) {
                        	if(grille[i][j] == '.') {
					if(marked[i][j] == '.') {
						return false;
					}
                                	marked[i][j] = '.';
                        	}
                	}
        	}
		rotate(grille, size);
	}

	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			if(marked[i][j] == 0) {
				return false;
			}
		}
	}

	return true;

}

void print(char grille[10][10], int size) {
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			cout << grille[i][j];
		}
		cout << endl;
	}
}

int main() {
	int size;
	cin >> size;

	string cipher;

	char grille[10][10] = {0};
	char solution[10][10] = {0};

	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++)
		{
			cin >> grille[i][j];
		}
	}

	cin >> cipher;

	if(!isValid(grille, size)) {
		cout << "invalid grille" << endl;
		return 0;
	}

	int l = 0;

	while(l < cipher.length()) {

	for(int k = 0; k < 4; k++) {
		for(int i = 0; i < size; i++) {
			for(int j = 0; j < size; j++) {
				if(grille[i][j] == '.') {
					solution[i][j] = cipher[l];
					l++;
				}
			}
		}
		rotate(grille, size);
	}

	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			cout << solution[i][j];
		}
	}

	}
	cout << endl;
	return 0;
}
