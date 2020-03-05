
#define LETTERS 26

typedef unsigned char byte;


//set all elements to 0
void init_histogram(int histo[]);


//construct the histogram from String
void cons_histogram(const char string[], int histo []);


//set ret_val to a most occurring digit character "hence returning it"
void most_frequent(const int histo[], char* ret_val);


//display the histogram sparsely
void display_histogram(int* const histo);

