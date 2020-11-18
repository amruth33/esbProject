#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"munit.h"
#include"email.h"



//********************EMAIL.C_TEST:**********************************

/*
static void *
test_email__setup(const MunitParameter params[], void *user_data)
{
    
    return strdup("/home/himanshu/bmd.xml");
}


	
static void
test_email_tear_down(void *fixture)
{
    
    free(fixture);
}

 */
// test case_1:

static MunitResult
test1_email()
{
        int actual=0;
	int expected=1;
	char *email = "akshaynikam813@gmail.com";
            

          //  email = (char*) malloc(50*sizeof(char));
	   // text = (char*) malloc(50* sizeof(char));	
	 
	 actual= send_mail(email,"bmdOutput.json");

            
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


// Test case_2:

static MunitResult
test2_email()
{
        int actual=0;
	int expected=1;
	char *email = "hims1792@gmail.com";
            

          //  email = (char*) malloc(50*sizeof(char));
	   // text = (char*) malloc(50* sizeof(char));	
	 
	 actual= send_mail(email,"bmdOutput.json");

            
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


// Test case_3:
static MunitResult
test3_email()
{
        int actual=0;
	int expected=1;
	char *email = " ";         // not giving any email
            

          //  email = (char*) malloc(50*sizeof(char));
	   // text = (char*) malloc(50* sizeof(char));	
	 
	 actual= send_mail(email,"bmdOutput.json");

            
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

//test case_4:
static MunitResult
test4_email()
{
        int actual=0;
	int expected=1;
	char *email = " ";
            

          //  email = (char*) malloc(50*sizeof(char));
	   // text = (char*) malloc(50* sizeof(char));	
	 
	 actual= send_mail(email,NULL);             // empty Arguments

            
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
       (char*) " /test1_email",   /* name */
       test1_email ,  /* test function */
       NULL ,    /* setup function for the test */
        NULL,    /* tear_down */
          MUNIT_TEST_OPTION_NONE  , /* options */
        NULL                    /* parameters */
    },

   {
       (char*) " /test2_email",   /* name */
       test2_email ,  /* test function */
       NULL ,    /* setup function for the test */
        NULL,    /* tear_down */
          MUNIT_TEST_OPTION_NONE  , /* options */
        NULL                    /* parameters */
    },

   {
       (char*) " /test3_email",   /* name */
       test3_email ,  /* test function */
       NULL ,    /* setup function for the test */
        NULL,    /* tear_down */
          MUNIT_TEST_OPTION_NONE  , /* options */
        NULL                    /* parameters */
    },

   {
       (char*) " /test4_email",   /* name */
       test4_email ,  /* test function */
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
