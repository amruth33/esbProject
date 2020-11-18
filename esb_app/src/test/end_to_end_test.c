#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "munit.h"
#include "../esb/esb.h"
#include"../adapter/email.h"
#include"../adapter/ftp.h"
#include"../adapter/http.h"
#include"../adapter/transform.h"
#include"../adapter/csv.h"




//********************parsing TEST:**********************************

static void *
test_bmd_parse_setup(const MunitParameter params[], void *user_data)
{
    
    return strdup("/home/amruth/work/nho2020/bmd_files/bmd2.xml");
}


	
static void
test_bmd_parse_tear_down(void *fixture)
{
    
    free(fixture);
}



static MunitResult
test_bmd_parse(const MunitParameter params[], void *fixture)
{
    char *path = (char *)fixture;
    

     bmd b =  parse_bmd_xml(path);

      munit_assert_string_equal(b.envelop.messageId , "A9ECAEF2-107A-4452-9553-043B6D25386E");
      munit_assert_string_equal(b.envelop.messageType , "CreditReport");
      munit_assert_string_equal(b.envelop.sender, "756E2EAA-1D5B-4BC0-ACC4-4CEB669408DA");
      munit_assert_string_equal(b.envelop.destination, "6393F82F-4687-433D-AA23-1966330381FE");
      munit_assert_string_equal(b.envelop.creationDateTime, "2020-08-12T05:18:00+0000");
      munit_assert_string_equal(b.envelop.signature, "63f5f61f7a79301f715433f8f3689390d1f5da4f855169023300491c00b8113c");
      munit_assert_string_equal(b.envelop.referenceId , "INV-PROFILE-889712");

                     
            printf("\ntest passed\n"); 

     
    return MUNIT_OK;
}

//*******************************IS_VALIDATION TEST *******************
 




/* Define the setup and the test for test2 */

static void *
test1_is_valid_setup(const MunitParameter params[], void *user_data)
{
    return strdup("/home/amruth/work/nho2020/bmd_files/bmd5.xml");
}

static void
test1_is_valid_tear_down(void *fixture)
{
    free(fixture);
}

static MunitResult
test1_is_valid(const MunitParameter params[], void *fixture)
{
    
           int expected=1;
	   check_t actual;
        char *path = (char *)fixture;


     bmd b =  parse_bmd_xml(path);

         actual = is_bmd_valid( b);
          
	 printf("\n");
           
	 if(expected==actual.valid_status)
	 {
		 printf("\ntest1 passed\n");
	   }
            else printf("\ntest1 failed\n");

          munit_assert_int(expected, ==,actual.valid_status);
	       {
	           return MUNIT_OK;

	             }
}

//****************************************************



//   *****************PROCESS_ESB_REQUEST_TEST**************

//TEST CASE_1:

static void *
test1_process_esb_request_setup(const MunitParameter params[], void *user_data)
{

    return strdup("/home/amruth/work/nho2020/bmd_files/bmd2.xml");
}

static void
test1_process_esb_request_tear_down(void *fixture)
{

    free(fixture);
}

static MunitResult
test1_process_esb_request(const MunitParameter params[], void *fixture)
{
        check_t actual;
	int expected=1;

    char *path = (char *)fixture;

         // bmd b =  parse_bmd_xml(path);

           actual= process_esb_request(path);


	  if(actual.valid_status==expected)
	  {
		  printf("\nTEST 1 PASSED\n");
	  }
	  else { printf("\nTEST 1 FAILED\n");}



   

       munit_assert_int(actual.valid_status,==,expected);
    return MUNIT_OK;
}

//*********************

//******************QUEUE_REQUEST_TEST**************

//TEST CASE_1:

static void *
test1_queue_request_setup(const MunitParameter params[], void *user_data)
{

    return strdup("/home/amruth/work/nho2020/bmd_files/bmd2.xml");
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

// ********************EMAIL.C TEST*******************


static MunitResult
test1_email()
{
        int actual=0;
	int expected=1;
	char *email = "amruthy98@gmail.com";


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






     
    //return MUNIT_OK;
}

//*******************************************

//*********************** FTP TEST****************


static MunitResult
test_ftp(const MunitParameter params[], void *fixture )
{
        	char * remote_url="ftp://ftp1user:ambi@192.168.0.107/payload.son";
		int actual=0;
                int expected=1;

	 
	 actual=  ftp(remote_url,"bmdOutput.json");

            
           if(actual==expected)
	   {
		   printf("\ntest passed\n");
	   }
	   else
	   { printf("\ntest failed\n");}

	    munit_assert_int(actual,==,expected);
               
		  return MUNIT_OK;
	      
       
    

     

     
    return MUNIT_OK;
}

//**********************************

// *************http TEST*****************


static MunitResult
test1_http(const MunitParameter params[], void *fixture )
{
        	char * remote_url="https://reqres.in/api/users";         //verified URL

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
	      
       
    

     

    
    return MUNIT_OK;
}

//******************TRANSFORM_JSON**************

//TEST CASE_1:

// static void *
// test1_transform_json_setup(const MunitParameter params[], void *user_data)
// {

//     return strdup("../../bmd_files/1604369631/bmd.xml");
// }

// static void
// test1_transform_json_tear_down(void *fixture)
// {

//     free(fixture);
// }

static MunitResult
test1_transform_json(const MunitParameter params[], void *fixture)
{
  //       int actual=0;
	 char * expected = "{\"Payload\":\"ICICI99856014\"}";

    char *path = (char *)fixture;

          // bmd b =  parse_bmd_xml(path);

          char * actual = transformToJson("../../bmd_files/1604987912/bmd2.xml");

	  // actual= queue_the_request(b,path);

	  if(!(strcmp(actual,expected)))
	  {
		  printf("\nTEST 8 PASSED\n");
	  }
	  else { printf("\nTEST 8 FAILED\n");}



   // int status = process_esb_request(str);

   // munit_assert_true(status == 0);

       munit_assert_string_equal(actual,expected);
    return MUNIT_OK;
}

//**********************************

//******************TRANSFORM_CSV**************


static MunitResult
test1_transform_csv(const MunitParameter params[], void *fixture)
{
  //       int actual=0;
	 int expected = 1;

    char *path = (char *)fixture;

          // bmd b =  parse_bmd_xml(path);

          int actual = payload_csv("../../bmd_files/1604987912/bmd2.xml");

	  // actual= queue_the_request(b,path);

	  if(actual==expected)
	  {
		  printf("\nTEST 9 PASSED\n");
	  }
	  else { printf("\nTEST 9 FAILED\n");}



   // int status = process_esb_request(str);

   // munit_assert_true(status == 0);

       munit_assert_int(actual,==,expected);
    return MUNIT_OK;
}

//**********************************

MunitTest esb_tests[] = {
    {
       (char*) " /test_bmd_parse1",   /* name */
       test_bmd_parse ,  /* test function */
       test_bmd_parse_setup ,    /* setup function for the test */
        test_bmd_parse_tear_down,    /* tear_down */
          MUNIT_TEST_OPTION_NONE  , /* options */
        NULL                    /* parameters */
    },
    

      {
        (char*) " /test1_is_valid",   /* name */
        test1_is_valid,  /* test function */
       test1_is_valid_setup ,    /* setup function for the test */
        test1_is_valid_tear_down,    /* tear_down */
        MUNIT_TEST_OPTION_NONE, /* options */
        NULL                    /* parameters */
    },

       
 {
        " /test1_process_esb_request_",   /* name */
        test1_process_esb_request,  /* test function */
       test1_process_esb_request_setup ,    /* setup function for the test */
        test1_process_esb_request_tear_down,    /* tear_down */
        MUNIT_TEST_OPTION_NONE, /* options */
        NULL                    /* parameters */
    },
    
 {
        " /test1_queue_request_",   /* name */
        test1_queue_request,  /* test function */
       test1_queue_request_setup ,    /* setup function for the test */
        test1_queue_request_tear_down,    /* tear_down */
        MUNIT_TEST_OPTION_NONE, /* options */
        NULL                    /* parameters */
    },

     
     {
       (char*) " /test1_email",   /* name */
       test1_email ,  /* test function */
       NULL ,    /* setup function for the test */
        NULL,    /* tear_down */
          MUNIT_TEST_OPTION_NONE  , /* options */
        NULL                    /* parameters */
    },

       {
       (char*) " /test_ftp",   /* name */
       test_ftp ,  /* test function */
       NULL ,    /* setup function for the test */
        NULL,    /* tear_down */
          MUNIT_TEST_OPTION_NONE  , /* options */
        NULL                    /* parameters */
    },
      
    
       {
       (char*) " /test_http",   /* name */
       test1_http ,  /* test function */
       NULL ,    /* setup function for the test */
        NULL,    /* tear_down */
          MUNIT_TEST_OPTION_NONE  , /* options */
        NULL                    /* parameters */
    },


      {
        (char*) " /test_transform_json",   /* name */
       test1_transform_json ,  /* test function */
       NULL,//test1_transform_json_setup ,    /* setup function for the test */
        NULL,//test1_transform_json_tear_down,    /* tear_down */
          MUNIT_TEST_OPTION_NONE  , /* options */
        NULL                    /* parameters */


      },
    
      {
        (char*) " /test_transform_csv",   /* name */
       test1_transform_csv ,  /* test function */
       NULL,   /* setup function for the test */
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




