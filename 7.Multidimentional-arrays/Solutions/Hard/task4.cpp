
#include <iostream>

const int MAX_SIZE = 10;

bool next_permutation(int n, int arr[]) {
	int i = n - 1;
	while (i >= 0 && arr[i] == n - 1) {
		arr[i] = 0;
		i--;
	}

	if (i >= 0) {
		arr[i]++;
		return true;
	}
	return false;
}

void print_queens(int n, int queen_column_indexes[]) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j == queen_column_indexes[i]) {
				std::cout << "Q" << " ";
			}
			else {
				std::cout << "_" << " ";
			}
		}
		std::cout << std::endl;
	}
}

void populate_table(int n, int queen_column_indexes[], int table[][MAX_SIZE]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			table[i][j] = queen_column_indexes[i] == j ? 1 : 0;
		}
	}
}

bool has_conflicts_first_approach(int n, int table[][MAX_SIZE]) {
	//rows
	for (int i = 0; i < n; i++) {
		int counter = 0;
		for (int j = 0; j < n; j++) {
			if (table[i][j] == 1) {
				counter++;
			}
		}
		if (counter > 1)
			return true;
	}

	//columns
	for (int i = 0; i < n; i++) {
		int counter = 0;
		for (int j = 0; j < n; j++) {
			if (table[j][i] == 1) {
				counter++;
			}
		}
		if (counter > 1)
			return true;
	}

	//int pDIndex = row - col + numberOfQueens - 1;

	//primary diagonals above the primary diagonal (including the primary diagonal)
	for (int k = 0; k < n; k++) {
		int counter = 0;
		for (int j = k, i = 0; j < n; j++, i++) {
			if (table[i][j] == 1) {
				counter++;
			}
		}
		if (counter > 1)
			return true;
	}

	//primary diagonals below the primary diagonal
	for (int k = 1; k < n; k++)
	{
		int counter = 0;
		for (int i = k, j = 0; i < n; i++, j++) {
			if (table[i][j] == 1) {
				counter++;
			}
		}
		if (counter > 1)
			return true;
	}

	//int sDIndex = row + col;

	//secondary diagonals above the secondary diagonal (including the secondary diagonal)
	for (int k = n - 1; k >= 0; k--) {
		int counter = 0;
		for (int j = k, i = 0; j >= 0; j--, i++) {
			if (table[i][j] == 1) {
				counter++;
			}
		}
		if (counter > 1)
			return true;
	}

	//secondary diagonals below the secondary diagonal
	for (int k = n - 1; k > 0; k--) {
		int counter = 0;
		for (int j = n - 1, i = k; i < n; j--, i++) {
			if (table[i][j] == 1) {
				counter++;
			}
		}
		if (counter > 1)
			return true;
	}

	return false;
}

bool has_conflicts_second_approach(int n, int table[][MAX_SIZE]) {
	int rows[MAX_SIZE]{ 0 };
	int columns[MAX_SIZE]{ 0 };
	int primary_diagonals[2 * MAX_SIZE - 1]{ 0 };
	int secondary_diagonals[2 * MAX_SIZE - 1]{ 0 };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (table[i][j] != 0) {
				rows[i]++;
				columns[j]++;
				primary_diagonals[i - j + n - 1]++;
				secondary_diagonals[i + j]++;

				if (rows[i] > 1 || columns[j] > 1 || primary_diagonals[i - j + n - 1] > 1 || secondary_diagonals[i + j] > 1)
					return true;
			}
		}
	}

	return false;
}

void generate_all_arrangments(int n) {
	int queen_column_indexes[MAX_SIZE]{ 0 };
	int table[MAX_SIZE][MAX_SIZE]{ 0 };

	do {
		populate_table(n, queen_column_indexes, table);
		//if (!has_conflicts_first_approach(n, table)) {
		if (!has_conflicts_second_approach(n, table)) {
			print_queens(n, queen_column_indexes);
			break;
		}
	} while (next_permutation(n, queen_column_indexes));

}

int main() {
	int n;

	std::cin >> n;

	generate_all_arrangments(n);
	return 0;
}
