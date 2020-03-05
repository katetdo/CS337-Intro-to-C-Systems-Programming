typedef unsigned int word;

int* create_queue();

void enqueue(int* *queue, word* tail, word* size, const int new_value);

int dequeue(int* *queue, word* tail, word* size);

void ensureCapacity(int* *queue, word* curSize);

void shrink(int* *queue, word* curSize);

int isHalf(const word tail, const word size);

int isEmpty(const word tail);

int isFull(const word tail, const word size);

void printQueue(int* queue, const word  tail);
