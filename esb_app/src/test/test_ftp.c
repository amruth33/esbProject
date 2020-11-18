#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"munit.h"
#include"ftp.h"



//********************FTP.C_TEST:**********************************

/*
static void *
test_ftp_setup(const MunitParameter params[], void *user_data)
{
    
    return strdup("/home/himanshu/bmd.xml");
}


	
static void
test_ftp_tear_down(void *fixture)
{
    
    free(fixture);
}

 */

// Test case_1:
static MunitResult
test1_ftp(const MunitParameter params[], void *fixture )
{
        	char * remote_url="ftp://iceman@192.168.42.194/payload.json";     // verified URL
		int actual=0;
                int expected=1;

	 
	 actual=  ftp(remote_url,"bmdOutput.json");

            
           if(actual==expected)
	   {
		   printf("\ntest1 passed\n");
	   }
	   else
	   { printf("\ntest1 failed\n");}

	    munit_assert_int(actual,==,expected);
               
		  return MUNIT_OK;
	      
       
    

     

     
    return MUNIT_OK;
}

// Test case_2

static MunitResult
test2_ftp(const MunitParameter params[], void *fixture )
{
        	char * remote_url=" ";       // giving empty URL
		int actual=0;
                int expected=1;

	 
	 actual=  ftp(remote_url,"bmdOutput.json");

            
           if(actual==expected)
	   {
		   printf("\ntest2 passed\n");
	   }
	   else
	   { printf("\ntest2 failed\n");}

	    munit_assert_int(actual,==,expected);
               
		  return MUNIT_OK;
	      
       
    

     

     
    return MUNIT_OK;
}

// Test case_3

static MunitResult
test3_ftp(const MunitParameter params[], void *fixture )
{
        	char * remote_url="ftp://iceman@192.168.42.194/payload.json";
		int actual=0;
                int expected=1;

	 
	 actual=  ftp(remote_url,NULL);        // giving NULL to second Argument 

            
           if(actual==expected)
	   {
		   printf("\ntest3 passed\n");
	   }
	   else
	   { printf("\ntest3 failed\n");}

	    munit_assert_int(actual,==,expected);
               
		  return MUNIT_OK;
	      
       
    

     

     
    return MUNIT_OK;
}

// Test case_4

static MunitResult
test4_ftp(const MunitParameter params[], void *fixture )
{
        	char * remote_url="ftp://xyz@192.168.42.194/payload.json";     // giving FALSE URL
		int actual=0;
                int expected=1;

	 
	 actual=  ftp(remote_url,"bmdOutput.json");

            
           if(actual==expected)
	   {
		   printf("\ntest4 passed\n");
	   }
	   else
	   { printf("\ntest4 failed\n");}

	    munit_assert_int(actual,==,expected);
               
		  return MUNIT_OK;
	      
       
    

     

     
    return MUNIT_OK;
}


/* Put all unit tests here. */
MunitTest esb_tests[] = {
    {
       (char*) " /test_ftp",   /* name */
       test1_ftp ,  /* test function */
       NULL ,    /* setup function for the test */
        NULL,    /* tear_down */
          MUNIT_TEST_OPTION_NONE  , /* options */
        NULL                    /* parameters */
    },
	
	  {
       (char*) " /test_ftp",   /* name */
       test2_ftp ,  /* test function */
       NULL ,    /* setup function for the test */
        NULL,    /* tear_down */
          MUNIT_TEST_OPTION_NONE  , /* options */
        NULL                    /* parameters */
    },
     
	  {
       (char*) " /test_ftp",   /* name */
       test3_ftp ,  /* test function */
       NULL ,    /* setup function for the test */
        NULL,    /* tear_down */
          MUNIT_TEST_OPTION_NONE  , /* options */
        NULL                    /* parameters */
    },
   
	  {
       (char*) " /test_ftp",   /* name */
       test4_ftp ,  /* test function */
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
