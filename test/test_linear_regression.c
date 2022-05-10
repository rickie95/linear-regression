#include <unity.h>
#include <linear_regression.h>

void setUp(void) {}
void tearDown(void) {}

void test_assert_is_equal(void){
    TEST_ASSERT_EQUAL(0, 0);
}

void test_assert_is_not_equal(void) {
    TEST_ASSERT_NOT_EQUAL(0, 1);
}

void test_assert_fails(void) {
    TEST_ASSERT_NOT_EQUAL(1, 1);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_assert_is_equal);
    RUN_TEST(test_assert_is_not_equal);
    RUN_TEST(test_assert_fails);

    return UNITY_END();
}