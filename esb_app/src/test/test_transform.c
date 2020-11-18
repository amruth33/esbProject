#include<stdio.h>
#include<stdlib.h>
#include "munit.h"
#include "esb.h"

//test case_1

static void *
test1_transform_to_json_setup(const MunitParameter params[], void *user_data)
{
    return strdup("/home/himanshu/bmd.xml");
}

static void
test1_transform_to_json_tear_down(void *fixture)
{
    free(fixture);
}

static MunitResult
test1_transform_to_json(const MunitParameter params[], void *fixture)
{

           char* expected= "AXIS0007954";  

	  
		  
		  
         char* actual;
        char *path = (char *)fixture;


              actual= transformToJson(path);


	 printf("\n");

	 

           munit_assert_string_equal(expected,actual);
	       {
	           return MUNIT_OK;

	             }
}

//test case_2

static void *
test2_transform_to_json_setup(const MunitParameter params[], void *user_data)
{
    return strdup("/home/himanshu/bmd1.xml");
}

static void
test2_transform_to_json_tear_down(void *fixture)
{
    free(fixture);
}

static MunitResult
test2_transform_to_json(const MunitParameter params[], void *fixture)
{

           char* expected= "001-01-1234";  

	  
		  
		  
         char* actual;
        char *path = (char *)fixture;


              actual= transformToJson(path);


	 printf("\n");

	 

           munit_assert_string_equal(expected,actual);
	       {
	           return MUNIT_OK;

	             }
}


//test case_3

static void *
test3_transform_to_json_setup(const MunitParameter params[], void *user_data)
{
    return strdup("/home/himanshu/bmd2.xml");
}

static void
test3_transform_to_json_tear_down(void *fixture)
{
    free(fixture);
}

static MunitResult
test3_transform_to_json(const MunitParameter params[], void *fixture)
{

           char* expected= "12345";  

	  
		  
		  
         char* actual;
        char *path = (char *)fixture;


              actual= transformToJson(path);


	 printf("\n");

	 

           munit_assert_string_equal(expected,actual);
	       {
	           return MUNIT_OK;

	             }
}



//test case_4

static void *
test4_transform_to_json_setup(const MunitParameter params[], void *user_data)
{
    return strdup("/home/himanshu/bmd3.xml");
}

static void
test4_transform_to_json_tear_down(void *fixture)
{
    free(fixture);
}

static MunitResult
test4_transform_to_json(const MunitParameter params[], void *fixture)
{

           char* expected= " ";  

	  
		  
		  
         char* actual;
        char *path = (char *)fixture;


              actual= transformToJson(path);


	 printf("\n");

	 

           munit_assert_string_equal(expected,actual);
	       {
	           return MUNIT_OK;

	             }
}





MunitTest esb_tests[] = {
    {
       (char*) " /test_transform_to json",   /* name */
       test1_transform_to_json ,  /* test function */
       test1_transform_to_json_setup ,    /* setup function for the test */
        test1_transform_to_json_tear_down,    /* tear_down */
          MUNIT_TEST_OPTION_NONE  , /* options */
        NULL                    /* parameters */
    },
    
    
     {
       (char*) " /test_transform_to json",   /* name */
       test2_transform_to_json ,  /* test function */
       test2_transform_to_json_setup ,    /* setup function for the test */
        test2_transform_to_json_tear_down,    /* tear_down */
          MUNIT_TEST_OPTION_NONE  , /* options */
        NULL                    /* parameters */
    },
    
    
     {
       (char*) " /test_transform_to json",   /* name */
       test3_transform_to_json ,  /* test function */
       test3_transform_to_json_setup ,    /* setup function for the test */
        test3_transform_to_json_tear_down,    /* tear_down */
          MUNIT_TEST_OPTION_NONE  , /* options */
        NULL                    /* parameters */
    },

 {
       (char*) " /test_transform_to json",   /* name */
       test4_transform_to_json ,  /* test function */
       test4_transform_to_json_setup ,    /* setup function for the test */
        test4_transform_to_json_tear_down,    /* tear_down */
          MUNIT_TEST_OPTION_NONE  , /* options */
        NULL                    /* parameters */
    },
    
     {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}};






/* Arrange the test cases into a test suite. */
static const MunitSuite suite = {
  "/my-tests", /* name */
  esb_tests, /* tests */
  NULL, /* suites */
  1, /* iterations */
  MUNIT_SUITE_OPTION_NONE /* options */
};

/* Run the the test suite */
int main (int argc, const char* argv[]) {

	printf("\n\nTEST CASES FOR PARSING AND IS_VALIDATION FUNCTION:\n\n\n");
  return munit_suite_main(&suite, NULL, argc, NULL);
}
