#include<stdio.h>
#include<stdlib.h>
#include "munit.h"
#include "esb.h"


//******************QUEUE_REQUEST_TEST**************

//TEST CASE_1:

static void *
test1_queue_request_setup(const MunitParameter params[], void *user_data)
{
    
    return strdup("/home/himanshu/bmd.xml");
}

static void
test1_queue_request_tear_down(void *fixture)
{
    
    free(fixture);
}

static MunitResult
test1_queue_request(const MunitParameter params[], void *fixture)
{
        int actual=0;
	int expected=1;

    char *path = (char *)fixture;
    
          bmd b =  parse_bmd_xml(path);

	  actual= queue_the_request(b,path);
              
	  if(actual==expected)
	  {   
		  printf("\nTEST 1 PASSED\n");
	  }
	  else { printf("\nTEST 1 FAILED\n");}

  
   
   // int status = process_esb_request(str);
    
   // munit_assert_true(status == 0);
   
       munit_assert_int(actual,==,expected);
    return MUNIT_OK;
}

//*******************

// TEST CASE_2


static void *
test2_queue_request_setup(const MunitParameter params[], void *user_data)
{
    
    return strdup("/home/himanshu/bmd_xml_files/bmd1.xml");
}

static void
test2_queue_request_tear_down(void *fixture)
{
    
    free(fixture);
}

static MunitResult
test2_queue_request(const MunitParameter params[], void *fixture)
{
        int actual=0;
	int expected=1;

    char *path = (char *)fixture;
    
          bmd b =  parse_bmd_xml(path);

	  actual= queue_the_request(b,path);
              
	  if(actual==expected)
	  {   
		  printf("\nTEST 2 PASSED\n");
	  }
	  else { printf("\nTEST 2 FAILED\n");}

  
   
   // int status = process_esb_request(str);
    
   // munit_assert_true(status == 0);
   
       munit_assert_int(actual,==,expected);
    return MUNIT_OK;
}

//********************************************

// TEST CASE_3:



static void *
test3_queue_request_setup(const MunitParameter params[], void *user_data)
{
    
    return strdup("/home/himanshu/bmd_xml_files/bmd2.xml");
}

static void
test3_queue_request_tear_down(void *fixture)
{
    
    free(fixture);
}

static MunitResult
test3_queue_request(const MunitParameter params[], void *fixture)
{
        int actual=0;
	int expected=1;

    char *path = (char *)fixture;
    
          bmd b =  parse_bmd_xml(path);

	  actual= queue_the_request(b,path);
              
	  if(actual==expected)
	  {   
		  printf("\nTEST 3 PASSED\n");
	  }
	  else { printf("\nTEST 3 FAILED\n");}

  
   
   // int status = process_esb_request(str);
    
   // munit_assert_true(status == 0);
   
       munit_assert_int(actual,==,expected);
    return MUNIT_OK;
}

//******************

// TEST CASE_4:


static void *
test4_queue_request_setup(const MunitParameter params[], void *user_data)
{

    return strdup("/home/himanshu/bmd_xml_files/bmd3.xml");
}

static void
test4_queue_request_tear_down(void *fixture)
{

    free(fixture);
}

static MunitResult
test4_queue_request(const MunitParameter params[], void *fixture)
{
        int actual=0;
	int expected=1;

    char *path = (char *)fixture;

          bmd b =  parse_bmd_xml(path);

	  actual= queue_the_request(b,path);

	  if(actual==expected)
	  {
		  printf("\nTEST 4 PASSED\n");
	  }
	  else { printf("\nTEST 4 FAILED\n");}



   // int status = process_esb_request(str);

   // munit_assert_true(status == 0);

       munit_assert_int(actual,==,expected);
    return MUNIT_OK;
}

// **************************

// test case_5:


static void *
test5_queue_request_setup(const MunitParameter params[], void *user_data)
{

    return strdup("/home/himanshu/bmd_xml_files/bmd4.xml");
}

static void
test5_queue_request_tear_down(void *fixture)
{

    free(fixture);
}

static MunitResult
test5_queue_request(const MunitParameter params[], void *fixture)
{
        int actual=0;
	int expected=1;

    char *path = (char *)fixture;

          bmd b =  parse_bmd_xml(path);

	  actual= queue_the_request(b,path);

	  if(actual==expected)
	  {
		  printf("\nTEST 5 PASSED\n");
	  }
	  else { printf("\nTEST 5 FAILED\n");}



   // int status = process_esb_request(str);

   // munit_assert_true(status == 0);

       munit_assert_int(actual,==,expected);
    return MUNIT_OK;
}

//*******************

// TEST CASE_6 


static void *
test6_queue_request_setup(const MunitParameter params[], void *user_data)
{
    
    return strdup("/home/himanshu/bmd_xml_files/bmd5.xml");
}

static void
test6_queue_request_tear_down(void *fixture)
{
    
    free(fixture);
}

static MunitResult
test6_queue_request(const MunitParameter params[], void *fixture)
{
        int actual=0;
	int expected=1;

    char *path = (char *)fixture;
    
          bmd b =  parse_bmd_xml(path);

	  actual= queue_the_request(b,path);
              
	  if(actual==expected)
	  {   
		  printf("\nTEST 6 PASSED\n");
	  }
	  else { printf("\nTEST 6FAILED\n");}

  
   
   // int status = process_esb_request(str);
    
   // munit_assert_true(status == 0);
   
       munit_assert_int(actual,==,expected);
    return MUNIT_OK;
}
//***********************

// TEST CASE_7: 


static void *
test7_queue_request_setup(const MunitParameter params[], void *user_data)
{
    
    return strdup("/home/himanshu/bmd_xml_files/bmd6.xml");
}

static void
test7_queue_request_tear_down(void *fixture)
{
    
    free(fixture);
}

static MunitResult
test7_queue_request(const MunitParameter params[], void *fixture)
{
        int actual=0;
	int expected=1;

    char *path = (char *)fixture;
    
          bmd b =  parse_bmd_xml(path);

	  actual= queue_the_request(b,path);
              
	  if(actual==expected)
	  {   
		  printf("\nTEST 7 PASSED\n");
	  }
	  else { printf("\nTEST 7 FAILED\n");}

  
   
   // int status = process_esb_request(str);
    
   // munit_assert_true(status == 0);
   
       munit_assert_int(actual,==,expected);
    return MUNIT_OK;
}

//****************************

// TEST CASE_8:


static void *
test8_queue_request_setup(const MunitParameter params[], void *user_data)
{
    
    return strdup("/home/himanshu/bmd_xml_files/bmd7.xml");
}

static void
test8_queue_request_tear_down(void *fixture)
{
    
    free(fixture);
}

static MunitResult
test8_queue_request(const MunitParameter params[], void *fixture)
{
        int actual=0;
	int expected=1;

    char *path = (char *)fixture;
    
          bmd b =  parse_bmd_xml(path);

	  actual= queue_the_request(b,path);
              
	  if(actual==expected)
	  {   
		  printf("\nTEST 8 PASSED\n");
	  }
	  else { printf("\nTEST 8 FAILED\n");}

  
   
   // int status = process_esb_request(str);
    
   // munit_assert_true(status == 0);
   
       munit_assert_int(actual,==,expected);
    return MUNIT_OK;
}


/* Put all unit tests here. */
MunitTest esb_tests[] = {
    {
        " /test1_queue_request_",   /* name */
        test1_queue_request,  /* test function */
       test1_queue_request_setup ,    /* setup function for the test */
        test1_queue_request_tear_down,    /* tear_down */
        MUNIT_TEST_OPTION_NONE, /* options */
        NULL                    /* parameters */
    },
    
     {
        " /test2_queue_request_",   /* name */
        test2_queue_request,  /* test function */
       test2_queue_request_setup ,    /* setup function for the test */
        test2_queue_request_tear_down,    /* tear_down */
        MUNIT_TEST_OPTION_NONE, /* options */
        NULL                    /* parameters */
    },

       {
        " /test3_queue_request_",   /* name */
        test3_queue_request,  /* test function */
       test3_queue_request_setup ,    /* setup function for the test */
        test3_queue_request_tear_down,    /* tear_down */
        MUNIT_TEST_OPTION_NONE, /* options */
        NULL                    /* parameters */
    },

        {
        " /test4_queue_request_",   /* name */
        test4_queue_request,  /* test function */
       test4_queue_request_setup ,    /* setup function for the test */
        test4_queue_request_tear_down,    /* tear_down */
        MUNIT_TEST_OPTION_NONE, /* options */
        NULL                    /* parameters */
    },

        {
        " /test5_queue_request_",   /* name */
        test5_queue_request,  /* test function */
       test5_queue_request_setup ,    /* setup function for the test */
        test5_queue_request_tear_down,    /* tear_down */
        MUNIT_TEST_OPTION_NONE, /* options */
        NULL                    /* parameters */
    },

	{
        " /test6_queue_request_",   /* name */
        test6_queue_request,  /* test function */
       test6_queue_request_setup ,    /* setup function for the test */
        test6_queue_request_tear_down,    /* tear_down */
        MUNIT_TEST_OPTION_NONE, /* options */
        NULL                    /* parameters */
    },
  
	{
        " /test7_queue_request_",   /* name */
        test7_queue_request,  /* test function */
       test7_queue_request_setup ,    /* setup function for the test */
        test7_queue_request_tear_down,    /* tear_down */
        MUNIT_TEST_OPTION_NONE, /* options */
        NULL                    /* parameters */
    },
	{
        " /test8_queue_request_",   /* name */
        test8_queue_request,  /* test function */
       test8_queue_request_setup ,    /* setup function for the test */
        test8_queue_request_tear_down,    /* tear_down */
        MUNIT_TEST_OPTION_NONE, /* options */
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
	printf("\n ESB QUEUE REQUEST TEST CASES:\n");
  return munit_suite_main(&suite, NULL, argc, NULL);
}
