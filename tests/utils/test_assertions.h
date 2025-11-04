void print_success(const char *message);

void print_failure(const char *message);

void expect_equal(const char *test_name, const size_t value, const size_t expected);

void expect_not_equal(const char *test_name, const size_t value, const size_t expected);

void expect_string_equal(const char *test_name, const char *value, const char *expected);