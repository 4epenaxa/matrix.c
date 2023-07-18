#include "tests.h"

int main(void) {

    SRunner *sr = srunner_create(test_sub());
    srunner_set_fork_status(sr, CK_NOFORK);
    
    //tcase_add_test(sr, test_sub2());

    srunner_run_all(sr, CK_NORMAL);
    srunner_free(sr);
  
  return 0;
}
