#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"munit.h"
#include"http.h"



//********************http.C_TEST:**********************************

/*
static void *
test_http_setup(const MunitParameter params[], void *user_data)
{
    
    return strdup("/home/himanshu/bmd.xml");
}


	
static void
test_http_tear_down(void *fixture)
{
    
    free(fixture);
}

 */

static MunitResult
test1_http(const MunitParameter params[], void *fixture )
{
        	char * remote_url="http://10.0.2.15";         //verified URL

		int actual=0;
                int expected=1;

	 
	 actual=  http(remote_url,"bmdOutput.json");

            
           if(actual==expected)
	   {
		   printf("\ntest1 passed\n");
	   }
	   else
	   { printf("\ntest1 failed\n");}

	    munit_assert_int(actual,==,expected);
               
		  return MUNIT_OK;
	      
       
    

     

     // Invoke the ESB function (or any other function to test)
   // int status = process_esb_request(str);
    
    // Assert the expected results
   // munit_assert_true(status == 0);
    return MUNIT_OK;
}


static MunitResult
test2_http(const MunitParameter params[], void *fixture )
{
        	char * remote_url=" ";             // Without URL

		int actual=0;
                int expected=1;

	 
	 actual=  http(remote_url,"bmdOutput.json");

            
           if(actual==expected)
	   {
		   printf("\ntest2 passed\n");
	   }
	   else
	   { printf("\ntest2 failed\n");}

	    munit_assert_int(actual,==,expected);
               
		  return MUNIT_OK;
	      
       
    

     

     // Invoke the ESB function (or any other function to test)
   // int status = process_esb_request(str);
    
    // Assert the expected results
   // munit_assert_true(status == 0);
    return MUNIT_OK;
}


static MunitResult
test3_http(const MunitParameter params[], void *fixture )
{
        	char * remote_url="http://10.0.2.15";

		int actual=0;
                int expected=1;

	 
	 actual=  http(remote_url,NULL);       //GIVING NULL IN Second argument

            
           if(actual==expected)
	   {
		   printf("\ntest3 passed\n");
	   }
	   else
	   { printf("\ntest3 failed\n");}

	    munit_assert_int(actual,==,expected);
               
		  return MUNIT_OK;
	      
       
    

     

     // Invoke the ESB function (or any other function to test)
   // int status = process_esb_request(str);
    
    // Assert the expected results
   // munit_assert_true(status == 0);
    return MUNIT_OK;
}


static MunitResult
test4_http(const MunitParameter params[], void *fixture )
{
        	char * remote_url="http://10.0.0.1";            // giving false URL

		int actual=0;
                int expected=1;

	 
	 actual=  http(remote_url,"bmdOutput.json");

            
           if(actual==expected)
	   {
		   printf("\ntest4 passed\n");
	   }
	   else
	   { printf("\ntest4 failed\n");}

	    munit_assert_int(actual,==,expected);
               
		  return MUNIT_OK;
	      
       
    

     

     // Invoke the ESB function (or any other function to test)
   // int status = process_esb_request(str);
    
    // Assert the expected results
   // munit_assert_true(status == 0);
    return MUNIT_OK;
}



/* Put all unit tests here. */
MunitTest esb_tests[] = {
    {
       (char*) " /test_ftp",   /* name */
       test1_http ,  /* test function */
       NULL ,    /* setup function for the test */
        NULL,    /* tear_down */
          MUNIT_TEST_OPTION_NONE  , /* options */
        NULL                    /* parameters */
    },

 {
       (char*) " /test_ftp",   /* name */
       test2_http ,  /* test function */
       NULL ,    /* setup function for the test */
        NULL,    /* tear_down */
          MUNIT_TEST_OPTION_NONE  , /* options */
        NULL                    /* parameters */
    },

     {
       (char*) " /test_ftp",   /* name */
       test3_http ,  /* test function */
       NULL ,    /* setup function for the test */
        NULL,    /* tear_down */
          MUNIT_TEST_OPTION_NONE  , /* options */
        NULL                    /* parameters */
    },


       {
       (char*) " /test_ftp",   /* name */
       test4_http ,  /* test function */
       NULL ,    /* setup function for the test */
        NULL,    /* tear_down */
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

  return munit_suite_main(&suite, NULL, argc, NULL);
}
