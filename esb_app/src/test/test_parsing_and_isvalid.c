#include<stdio.h>
#include<stdlib.h>
#include "munit.h"
#include "esb.h"



//********************parsing TEST:**********************************

static void *
test_bmd_parse_setup(const MunitParameter params[], void *user_data)
{
    
    return strdup("/home/himanshu/bmd.xml");
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

     // Invoke the ESB function (or any other function to test)
   // int status = process_esb_request(str);
    
    // Assert the expected results
   // munit_assert_true(status == 0);
    return MUNIT_OK;
}

//*******************************IS_VALIDATION TEST *******************
 

//*TEST CASE_1***************


/* Define the setup and the test for test2 */

static void *
test1_is_valid_setup(const MunitParameter params[], void *user_data)
{
    return strdup("/home/himanshu/bmd.xml");
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
	   int actual;
        char *path = (char *)fixture;


     bmd b =  parse_bmd_xml(path);

         actual = is_bmd_valid( b);
          
	 printf("\n");
           
	 if(expected==actual)
	 {
		 printf("\ntest1 passed\n");
	   }
            else printf("\ntest1 failed\n");

          munit_assert_int(expected, ==,actual);
	       {
	           return MUNIT_OK;

	             }
}


//*******************


// test case_2*****************

static void *
test2_is_valid_setup(const MunitParameter params[], void *user_data)
{
    return strdup("/home/himanshu/bmd_xml_files/bmd1.xml");
}



static void
test2_is_valid_tear_down(void *fixture)
{
    free(fixture);
}

static MunitResult
test2_is_valid(const MunitParameter params[], void *fixture)
{

           int expected=1;
           int actual;
        char *path = (char *)fixture;


     bmd b =  parse_bmd_xml(path);

         actual = is_bmd_valid( b);
          

                   printf("\n");
         if(expected==actual)
         {
                 printf("\ntest2 passed\n");
           }

	 else 
	 {	 printf("\ntest2 failed\n");
                  
	 }
	   munit_assert_int(expected, ==,actual);
               {
                   return MUNIT_OK;

                     }
}

//***********************

// TEST CASE_3**********************




static void *
test3_is_valid_setup(const MunitParameter params[], void *user_data)
{
    return strdup("/home/himanshu/bmd_xml_files/bmd2.xml");
}



static void
test3_is_valid_tear_down(void *fixture)
{
    free(fixture);
}



static MunitResult
test3_is_valid(const MunitParameter params[], void *fixture)
{
          
           int expected=1;
           int actual;
        char *path = (char *)fixture;


     bmd b =  parse_bmd_xml(path);

         actual = is_bmd_valid( b);

               printf("\n");

           
         if(expected==actual)
         {
                 printf("\ntest3 passed\n");
           }

         else
         {       printf("\ntest3 failed\n");

         }
           munit_assert_int(expected, ==,actual);
               {
                   return MUNIT_OK;

                     }
}


//*********************

// test case_4********




static void *
test4_is_valid_setup(const MunitParameter params[], void *user_data)
{
    return strdup("/home/himanshu/bmd_xml_files/bmd3.xml");
}



static void
test4_is_valid_tear_down(void *fixture)
{
    free(fixture);
}



static MunitResult
test4_is_valid(const MunitParameter params[], void *fixture)
{
          
           int expected=1;
           int actual;
        char *path = (char *)fixture;


     bmd b =  parse_bmd_xml(path);

         actual = is_bmd_valid( b);

               printf("\n");

           
         if(expected==actual)
         {
                 printf("\ntest4 passed\n");
           }

         else
         {       printf("\ntest4 failed\n");

         }
           munit_assert_int(expected, ==,actual);
               {
                   return MUNIT_OK;

                     }
}

//*******************

//test case_5.....




static void *
test5_is_valid_setup(const MunitParameter params[], void *user_data)
{
    return strdup("/home/himanshu/bmd_xml_files/bmd4.xml");
}



static void
test5_is_valid_tear_down(void *fixture)
{
    free(fixture);
}



static MunitResult
test5_is_valid(const MunitParameter params[], void *fixture)
{

           int expected=1;
           int actual;
        char *path = (char *)fixture;


     bmd b =  parse_bmd_xml(path);

         actual = is_bmd_valid( b);

               printf("\n");


         if(expected==actual)
         {
                 printf("\ntest5 passed\n");
           }

         else
         {       printf("\ntest5 failed\n");

         }
           munit_assert_int(expected, ==,actual);
               {
                   return MUNIT_OK;

                     }
}
//********************** 

// test case_6


static void *
test6_is_valid_setup(const MunitParameter params[], void *user_data)
{
    return strdup("/home/himanshu/bmd_xml_files/bmd5.xml");
}



static void
test6_is_valid_tear_down(void *fixture)
{
    free(fixture);
}



static MunitResult
test6_is_valid(const MunitParameter params[], void *fixture)
{

           int expected=1;
           int actual;
        char *path = (char *)fixture;


     bmd b =  parse_bmd_xml(path);

         actual = is_bmd_valid( b);

               printf("\n");


         if(expected==actual)
         {
                 printf("\ntest6 passed\n");
           }

         else
         {       printf("\ntest6 failed\n");

         }
           munit_assert_int(expected, ==,actual);
               {
                   return MUNIT_OK;

                     }
}

//****************************

//test case_7


static void *
test7_is_valid_setup(const MunitParameter params[], void *user_data)
{
    return strdup("/home/himanshu/bmd_xml_files/bmd6.xml");
}



static void
test7_is_valid_tear_down(void *fixture)
{
    free(fixture);
}



static MunitResult
test7_is_valid(const MunitParameter params[], void *fixture)
{

           int expected=1;
           int actual;
        char *path = (char *)fixture;


     bmd b =  parse_bmd_xml(path);

         actual = is_bmd_valid( b);

               printf("\n");


         if(expected==actual)
         {
                 printf("\ntest7 passed\n");
           }

         else
         {       printf("\ntest7 failed\n");

         }
           munit_assert_int(expected, ==,actual);
               {
                   return MUNIT_OK;

                     }
}
// ********************************

// test case_8



static void *
test8_is_valid_setup(const MunitParameter params[], void *user_data)
{
    return strdup("/home/himanshu/bmd_xml_files/bmd7.xml");
}



static void
test8_is_valid_tear_down(void *fixture)
{
    free(fixture);
}



static MunitResult
test8_is_valid(const MunitParameter params[], void *fixture)
{

           int expected=1;
           int actual;
        char *path = (char *)fixture;


     bmd b =  parse_bmd_xml(path);

         actual = is_bmd_valid( b);

               printf("\n");


         if(expected==actual)
         {
                 printf("\ntest8 passed\n");
           }

         else
         {       printf("\ntest8 failed\n");

         }
           munit_assert_int(expected, ==,actual);
               {
                   return MUNIT_OK;

                     }
}

/* Put all unit tests here. */
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
        (char*) " /test2_is_valid",   /* name */
        test2_is_valid,  /* test function */
       test2_is_valid_setup ,    /* setup function for the test */
        test2_is_valid_tear_down,    /* tear_down */
        MUNIT_TEST_OPTION_NONE, /* options */
        NULL                    /* parameters */
    },

    {
        (char*) " /test3_is_valid",   /* name */
        test3_is_valid,  /* test function */
       test3_is_valid_setup ,    /* setup function for the test */
        test3_is_valid_tear_down,    /* tear_down */
        MUNIT_TEST_OPTION_NONE, /* options */
        NULL                    /* parameters */
    },

      {
        (char*) " /test4_is_valid",   /* name */
        test4_is_valid,  /* test function */
       test4_is_valid_setup ,    /* setup function for the test */
        test4_is_valid_tear_down,    /* tear_down */
        MUNIT_TEST_OPTION_NONE, /* options */
        NULL                    /* parameters */
    },
     
      {
        (char*) " /test5_is_valid",   /* name */
        test5_is_valid,  /* test function */
       test5_is_valid_setup ,    /* setup function for the test */
        test5_is_valid_tear_down,    /* tear_down */
        MUNIT_TEST_OPTION_NONE, /* options */
        NULL                    /* parameters */
    },

           {
        (char*) " /test6_is_valid",   /* name */
        test6_is_valid,  /* test function */
       test6_is_valid_setup ,    /* setup function for the test */
        test6_is_valid_tear_down,    /* tear_down */
        MUNIT_TEST_OPTION_NONE, /* options */
        NULL                    /* parameters */
    },

      {
        (char*) " /test7_is_valid",   /* name */
        test7_is_valid,  /* test function */
       test7_is_valid_setup ,    /* setup function for the test */
        test7_is_valid_tear_down,    /* tear_down */
        MUNIT_TEST_OPTION_NONE, /* options */
        NULL                    /* parameters */
    },

   {
        (char*) " /test8_is_valid",   /* name */
        test8_is_valid,  /* test function */
       test8_is_valid_setup ,    /* setup function for the test */
        test8_is_valid_tear_down,    /* tear_down */
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

	printf("\n\nTEST CASES FOR PARSING AND IS_VALIDATION FUNCTION:\n\n\n");
  return munit_suite_main(&suite, NULL, argc, NULL);
}
