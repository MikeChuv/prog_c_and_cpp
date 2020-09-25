
const int nmax = 10;



int input(double arr[][nmax], int& rows, int& colls, char* filename);

void print_static_matrix(double arr[][nmax], int rows, int colls, char* filename, char matrix_name);

void print_vector(int vec[], int length, char* filename);

void message_with_double(double number,const char* message, char* filename);

double static_max_all(double arr[][nmax], int rows, int colls);

double static_max_rows(double arr[][nmax], int rows, int colls);

void static_positive_count_all(double arr[][nmax], int rows, int colls, int vec[]);

void static_positive_count_rows(double arr[][nmax], int rows, int colls, char* filename);

