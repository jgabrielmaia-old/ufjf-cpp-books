void sort(Book **to_sort, int low, int high, int copy_count, int compare_count);
void printArray(Book **to_sort, int size);
void swap(Book *a, Book *b, int copy_count);
int partition(Book **to_sort, int low, int high, int copy_count, int compare_count);

void sort_a(HashedAuthor **to_sort, int low, int high);
void print_array_a(HashedAuthor **to_sort, int size);
void swap_a(HashedAuthor *a, HashedAuthor *b);
int partition_a(HashedAuthor **to_sort, int low, int high);