#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "vector.h"

void test_init() {
	Vector vector;
	vector_init(&vector);

	CU_ASSERT(vector.size == 0);
	CU_ASSERT(vector.capacity = VECTOR_SIZE);
}

void test_append() {
	Vector vector;
	vector_init(&vector);

	// fill it up with 150 arbitrary values
	// this should expand capacity up to 200
	int i;
	for (i = 200; i > -50; i--) {
		vector_append(&vector, i);
	}

    CU_ASSERT(vector.size == 250);
    CU_ASSERT(vector.capacity == 400);

	vector_free(&vector);
}

void test_vector_set() {
	Vector vector;
	vector_init(&vector);

	vector_set(&vector, 4452, 21312984);

	CU_ASSERT(vector.data[0] == 0);
	CU_ASSERT(vector.data[4452] == 21312984);

	vector_free(&vector);	
}


int main() {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("vector_test", 0, 0);
	
    CU_add_test(suite, "Vector Initialize code appended", test_init);
    CU_add_test(suite, "Testing Append code", test_append);
    CU_add_test(suite, "Testing Set Code", test_vector_set);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return 0;
}